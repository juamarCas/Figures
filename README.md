# Figures
this is an application where you from a .txt file choose what will be shown on the screen and how it will be shown.

## Code design

### Tools
The tools used to make this application are: GLEW and GLFW, in order to use OpenGL as the graphic API to draw the figures.  

#### GLEW
Is an open source cross-platform C/C++ extension library. This library provides run-time mechanisms for determining which OpenGL extensions are supported on the target platform.<br/>  


Link: (http://glew.sourceforge.net/)

#### GLFW 
Is an open source multi-platform library for OpenGL, OpenGl ES and Vulkan development on the desktop. It provides a simple API for creating windows, contexts and surface, receiving input and events.<br/> 


Link: (https://www.glfw.org/)

#### OpenGL
The version of OpenGL which this application was made is OpenGL 4.6.

### Figure class
The code has a class called Figure that is father class of all the shapes you can create in this application. This class has all the important variables that defines every figure, like size, moving rate and color. The following classes inherits from Figure:<br/>  

1. Rectangle<br/>  
2. Polygon<br/>    
3. Triangle<br/>  

This is in orther to have a cleaner code and in the future will be more easy to modify.  

### Animator class
The animator class has all the animation methods in it.  



