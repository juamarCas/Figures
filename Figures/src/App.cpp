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
#include "Polygon.h"
#include "Animator.h"

#define WIDTH 640
#define HEIGHT 640

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


template<typename T>
void SetConfiguration(T *value, std::string& filepath, std::string param, std::string var, std::string symbol) {
	std::ifstream configFile(filepath); 
	std::stringstream ss; 
	std::string line; 
	while (getline(configFile, line)) {
		if (line.find(param) != std::string::npos) {
			if (line.find(var) != std::string::npos) {
				std::size_t f = line.find(symbol);
				ss.str(line);
				ss.seekg(f + 1);
				ss >> *value; 
			}
		}
	}
}
int main(void)
{

	GLFWwindow* window;
	

	/* Initialize the library */
	if (!glfwInit())
		return -1;


	/* Create a windowed mode window and its OpenGL context */
	window = glfwCreateWindow(WIDTH, HEIGHT, "figure", NULL, NULL);
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
		//setting up graphics properties
		float rate, size;
		float red, green, blue;
		std::string animation; 
		std::string figureType; 

		//config variables
		std::string path = "res/config.txt"; 
		std::string symbol = "=";
		std::string param;
		std::string var;
		

		//Configuring Colors
		param = "-Color"; 
		var = "red"; 
		SetConfiguration(&red, path, param, var, symbol);

		var = "green";
		SetConfiguration(&green, path, param, var, symbol);	

		var = "blue"; 
		SetConfiguration(&blue, path, param, var, symbol);
		
		//configuring animations and other characteristics
		param = "-Characteristic"; 
		var = "animation"; 
		SetConfiguration(&animation, path, param, var, symbol); 

		var = "size"; 
		SetConfiguration(&size, path, param, var, symbol);

		var = "rate"; 
		SetConfiguration(&rate, path, param, var, symbol);

		var = "figure"; 
		SetConfiguration(&figureType, path, param, var, symbol);
	
		//define the figure and setting animator
		
		Figure * figure;
		if (figureType == "Square") {
			 figure = new Square(size, 0.0f, 0.0f, red, green, blue);
		}
		else if (figureType == "Hexagon") {
			figure = new Polygon(size, 0.0f, 0.0f, red, green, blue, 16); 
		}
		else {
			//by default generate a square
			figure = new Square(size, 0.0f, 0.0f, red, green, blue);
		}
		Animator anim(figure, rate);

		//preparing the figure to be displayed
		VertexBuffer vb(figure->GetPositions(), figure->GetVertexCount() * sizeof(float));
		GLCall(glEnableVertexAttribArray(0));
		GLCall(glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, sizeof(float) * 2, 0));
		
		IndexBuffer ib(figure->GetIndex(), figure->GetIndexCount());
		
		//shader setting
		ShaderProgramSource source = ParseShader("res/shader/Basic.shader");

		unsigned int shader = CreateShader(source.vertexSource, source.fragmentSource);
		GLCall(glUseProgram(shader));

		GLCall(int location = glGetUniformLocation(shader, "u_Color"));
		ASSERT(location != -1);
		float * rgb = figure->GetColors(); 
		GLCall(glUniform4f(location, rgb[0], rgb[1], rgb[2], 1.0f));
		
		
		while (!glfwWindowShouldClose(window))
		{			
			glClear(GL_COLOR_BUFFER_BIT);
			anim.SetAnimation(animation); 
			vb.UpdateBufferData(figure->GetPositions(), figure->GetVertexCount() * sizeof(float)); 
			ib.Bind(); 
			GLCall(glDrawElements(GL_TRIANGLES, figure->GetIndexCount() , GL_UNSIGNED_INT, nullptr));
			glfwSwapBuffers(window);		
			glfwPollEvents();
		}
	}

	glfwTerminate();
	return 0;
}