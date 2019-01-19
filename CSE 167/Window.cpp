#include "Window.h"

const char* window_title = "GLFW Starter Project";
Cube cube(5.0f);
OBJObject bunny("/Users/apple/Desktop/CSE167StarterCode-master/GLFWStarterProject/bunny.obj");
OBJObject dragon("/Users/apple/Desktop/CSE167StarterCode-master/GLFWStarterProject/dragon.obj");
OBJObject bear("/Users/apple/Desktop/CSE167StarterCode-master/GLFWStarterProject/bear.obj");

int Window::width;
int Window::height;
int kb = 4;
int ec = 0;
int current = 1;
int changesize = 0;
int buttonsize = 0;

void Window::initialize_objects()
{
}

void Window::clean_up()
{
}

GLFWwindow* Window::create_window(int width, int height)
{
	// Initialize GLFW.
	if (!glfwInit())
	{
		fprintf(stderr, "Failed to initialize GLFW\n");
		return NULL;
	}

	// 4x antialiasing
	glfwWindowHint(GLFW_SAMPLES, 4);

	// Create the GLFW window
	GLFWwindow* window = glfwCreateWindow(width, height, window_title, NULL, NULL);

	// Check if the window could not be created
	if (!window)
	{
		fprintf(stderr, "Failed to open GLFW window.\n");
		glfwTerminate();
		return NULL;
	}

	// Make the context of the window
	glfwMakeContextCurrent(window);

	// Set swap interval to 1
	glfwSwapInterval(1);

	// Call the resize callback to make sure things get drawn immediately
	Window::resize_callback(window, width, height);

	return window;
}

void Window::resize_callback(GLFWwindow* window, int width, int height)
{
#ifdef __APPLE__
	glfwGetFramebufferSize(window, &width, &height); // In case your Mac has a retina display
#endif
	Window::width = width;
	Window::height = height;
	// Set the viewport size
	glViewport(0, 0, width, height);
	// Set the matrix mode to GL_PROJECTION to determine the proper camera properties
	glMatrixMode(GL_PROJECTION);
	// Load the identity matrix
	glLoadIdentity();
	// Set the perspective of the projection viewing frustum
	gluPerspective(60.0, double(width) / (double)height, 1.0, 1000.0);
	// Move camera back 20 units so that it looks at the origin (or else it's in the origin)
	glTranslatef(0, 0, -20);
}

void Window::idle_callback()
{
	// Perform any updates as necessary. Here, we will spin the cube slightly.
	bunny.update();
    dragon.update();
    bear.update();
}

void Window::display_callback(GLFWwindow* window)
{
	// Clear the color and depth buffers
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	// Set the matrix mode to GL_MODELVIEW
	glMatrixMode(GL_MODELVIEW);
	// Load the identity matrix
	glLoadIdentity();
   
    if(kb == 2){
        if(changesize == -1){
            glPointSize(dragon.size = buttonsize - 0.5);
            buttonsize = dragon.size;
            changesize = 0;
        }
        else if(changesize == 1){
            glPointSize(dragon.size = buttonsize + 1.5);
            buttonsize = dragon.size;
            changesize = 0;
        }
        if(ec == 0){
            dragon.draw();
        }
        else{
            dragon.EC_draw();
        }
    }
    else if(kb == 3 ){
        if(changesize == -1){
            glPointSize(bear.size = buttonsize - 0.5);
            buttonsize = bear.size;
            changesize = 0;
        }
        else if(changesize == 1){
            glPointSize(bear.size = buttonsize + 1.5);
            buttonsize = bear.size;
            changesize = 0;
        }
        
        if(ec == 0){
            bear.draw();
        }
        else{
            bear.EC_draw();
        }
        current = 2;
    }
    else if(kb == 1){
        if(changesize == -1){
            glPointSize(bunny.size = buttonsize - 0.5);
            buttonsize = bunny.size;
            changesize = 0;
        }
        else if(changesize == 1){
            glPointSize(bunny.size = buttonsize + 1.5);
            buttonsize = bunny.size;
            changesize = 0;
        }
        if(ec == 0){
            bunny.draw();
        }
        else{
            bunny.EC_draw();
        }
    }
    else{
        if(changesize == -1){
            glPointSize(bunny.size = buttonsize - 0.5);
            buttonsize = bunny.size;
            changesize = 0;
        }
        else if(changesize == 1){
            glPointSize(bunny.size = buttonsize + 1.5);
            buttonsize = bunny.size;
            changesize = 0;
        }
        if(ec == 0){
            bunny.draw();
        }
        else{
            bunny.EC_draw();
        }
    }
	// Render objects
	// Gets events, including input such as keyboard and mouse or window resizing
	glfwPollEvents();
	// Swap buffers
	glfwSwapBuffers(window);
}
/* handle the F1 F2 F3*/
void Window::key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
	// Check for a key press
	if (action == GLFW_PRESS)
	{
		// Check if escape was pressed
		if (key == GLFW_KEY_ESCAPE)
		{
			// Close the window. This causes the program to also terminate.
			glfwSetWindowShouldClose(window, GL_TRUE);
		}
        else{
            //for EC
            if(key == GLFW_KEY_E){
                if(ec == 0){
                    ec = 1;
                }
                else{
                    ec = 0;
                }
            }
            if(mods == GLFW_MOD_SHIFT && key == GLFW_KEY_P){
                changesize = 1;
            }
            else if(key == GLFW_KEY_P){
                changesize = -1;
            }
            //not closing window, handling F1, F2, F3
            if(key == GLFW_KEY_F1){
                kb = 1;
                
            }
            else if(key == GLFW_KEY_F2){
                kb = 2;
                
            }
            else if(key == GLFW_KEY_F3){
                kb = 3;
                
            }
            
        }
	}
}
