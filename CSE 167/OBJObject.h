#ifndef OBJOBJECT_H
#define OBJOBJECT_H

#define GLFW_INCLUDE_GLEXT
#ifdef __APPLE__
#define GLFW_INCLUDE_GLCOREARB
#else
#include <GL/glew.h>
#endif
#include <GLFW/glfw3.h>
// Use of degrees is deprecated. Use radians instead.
#ifndef GLM_FORCE_RADIANS
#define GLM_FORCE_RADIANS
#endif
#include <glm/mat4x4.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <vector>

class OBJObject
{
private:
    std::vector<unsigned int> indices;
    std::vector<glm::vec3> vertices;
    std::vector<glm::vec3> normals;
    float angle;
    
public:
    OBJObject();
    ~OBJObject();
    OBJObject(const char* filepath);
    
    glm::mat4 toWorld;
    
    void draw(GLuint);
    void update();
    void spin(float);
    
    void parse(const char* filepath);
    
    void transit(OBJObject &obj1, OBJObject &obj2);
    std::vector<glm::vec3> getvertices(){
        return vertices;
    }
    float size;
    // These variables are needed for the shader program
    GLuint VBO, VAO, EBO;
    GLuint uProjection, uModelview;
    
};

#endif

