#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <math.h>

#include "Renderer.h"
#include "VertexBuffer.h"
#include "IndexBuffer.h"
#include "Square.h"
#include "Animator.h"

struct ShaderProgramSource {
	std::string vertexSource;
	std::string fragmentSource;
};
static ShaderProgramSource ParseShader(const std::string& filePath) {
	//this function identifies the shader file and separete the vertex and fragment shader
	std::ifstream stream(filePath);
	enum class shaderType {
		NONE = -1, VERTEX = 0, FRAGMENT = 1
	};
	shaderType type = shaderType::NONE;


	std::stringstream ss[2];
	std::string line;
	while (getline(stream, line)) {
		if (line.find("#shader") != std::string::npos) {
			if (line.find("vertex") != std::string::npos) {
				type = shaderType::VERTEX;
			}
			else if (line.find("fragment") != std::string::npos) {
				type = shaderType::FRAGMENT;
			}
		}
		else {
			ss[(int)type] << line << "\n";
		}
	}
	return {
		ss[0].str(), ss[1].str()
	};
}

static unsigned int CompileShader(unsigned int type, const std::string& source) {
	unsigned int id = glCreateShader(type);  // crea el vertex shader y el fragment shader
	const char* src = source.c_str(); // lo mismo que &source[0]
	glShaderSource(id, 1, &src, nullptr); //reemplaza el código fuente en un objeto shader
	glCompileShader(id);

	int result;
	glGetShaderiv(id, GL_COMPILE_STATUS, &result);
	if (result == GL_FALSE) {
		int length;
		glGetShaderiv(id, GL_INFO_LOG_LENGTH, &length);
		char* message = (char*)alloca(length * sizeof(char));
		glGetShaderInfoLog(id, length, &length, message);
		std::cout << "Failed to compile" << (type == GL_VERTEX_SHADER ? "vertex" : "fragment") << "shader" << std::endl;
		std::cout << message << std::endl;
		glDeleteShader(id);
		return 0;
	}

	return id;
}

static unsigned int CreateShader(const std::string& vertexShader, const std::string& fragmentShader) {
	unsigned int program = glCreateProgram(); //
	unsigned int vs = CompileShader(GL_VERTEX_SHADER, vertexShader);
	unsigned int fs = CompileShader(GL_FRAGMENT_SHADER, fragmentShader);

	glAttachShader(program, vs);
	glAttachShader(program, fs);
	glLinkProgram(program);
	glValidateProgram(program);

	glDeleteShader(vs);
	glDeleteShader(fs);

	return program;
}

int main(void)
{

	GLFWwindow* window;
	float rate = 0.001; 

	/* Initialize the library */
	if (!glfwInit())
		return -1;


	/* Create a windowed mode window and its OpenGL context */
	window = glfwCreateWindow(640, 480, "Figures", NULL, NULL);
	if (!window)
	{
		glfwTerminate();
		return -1;
	}

	/* Make the window's context current */
	glfwMakeContextCurrent(window);
	if (glewInit() != GLEW_OK) {
		std::cout << "Error!" << std::endl;
	}

	std::cout << glGetString(GL_VERSION) << std::endl;
	{
		//define the figure and setting animator
		Figure * square = new Square(4.0f, 0.0f, 0.0f);
		Animator anim(square, rate); 

		//preparing the figure to be displayed
		VertexBuffer vb(square->GetPositions(), square->GetVertexCount() * sizeof(float));
		GLCall(glEnableVertexAttribArray(0));
		GLCall(glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, sizeof(float) * 2, 0));
		IndexBuffer ib(square->GetIndex(), 6);
		
		//shader setting
		ShaderProgramSource source = ParseShader("res/shader/Basic.shader");

		unsigned int shader = CreateShader(source.vertexSource, source.fragmentSource);
		GLCall(glUseProgram(shader));

		GLCall(int location = glGetUniformLocation(shader, "u_Color"));
		ASSERT(location != -1);
		GLCall(glUniform4f(location, 0.2f, 0.3f, 0.8f, 1.0f));
		
		
		while (!glfwWindowShouldClose(window))
		{			
			glClear(GL_COLOR_BUFFER_BIT);
			anim.SetAnimation("UpDown"); 
			vb.UpdateBufferData(square->GetPositions(), square->GetVertexCount() * sizeof(float)); 
			ib.Bind(); 
			GLCall(glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, nullptr));
			glfwSwapBuffers(window);		
			glfwPollEvents();
		}
	}

	glfwTerminate();
	return 0;
}