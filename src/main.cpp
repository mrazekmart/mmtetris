#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <cmath>
#include <iostream>
#include <vector>
#include <chrono>

#include "shaderClass.h"
#include "VAO.h"
#include "VBO.h"
#include "EBO.h"
#include "MMRectangle.h"
#include "MMParticleMatrix.h"
#include "MMSand.h"
#include "MMSand3d.h"
#include "MMStone.h"
#include "MMStone3d.h"
#include "MMGraphicsSingleton.h"
#include "MMCamera.h"
#include "MMTetrisManager.h"

const int WINDOW_HEIGHT = 800;
const int WINDOW_WIDTH = 800;

int main()
{
    std::vector<float> vertices;
    std::vector<GLfloat> colors;
    std::vector<unsigned int> indices;

    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    GLFWwindow *window = glfwCreateWindow(WINDOW_HEIGHT, WINDOW_WIDTH, "MMTetris", NULL, NULL);

    if (window == NULL)
    {
        std::cout << "Failed to create window" << std::endl;
        glfwTerminate();
        return -1;
    }

    glfwMakeContextCurrent(window);
    gladLoadGL();
    glViewport(0, 0, WINDOW_HEIGHT, WINDOW_WIDTH);
    Shader shaderProgram("c:\\Users\\Martin\\WORKSPACE\\VSC\\3dG\\resource\\shaders\\default.vert",
                         "c:\\Users\\Martin\\WORKSPACE\\VSC\\3dG\\resource\\shaders\\default.frag");

    const int particleSize = 24;
    const int cubeIndices = 36;
    const int matrixSize = WINDOW_HEIGHT / particleSize;

    MMGraphicsSingleton &mmGraphics = MMGraphicsSingleton::getInstance();
    MMTetrisManager mmTetris(matrixSize / 2, matrixSize, particleSize);

    glEnable(GL_DEPTH_TEST);
    MMCamera camera(WINDOW_HEIGHT, WINDOW_WIDTH, glm::vec3(0.0f, 0.0f, 2.0f));

    auto startMoveDown = std::chrono::high_resolution_clock::now();
    auto startMoveSide = std::chrono::high_resolution_clock::now();
    auto startRotate = std::chrono::high_resolution_clock::now();

    while (!glfwWindowShouldClose(window))
    {
        vertices = mmGraphics.GetVerticesAll();
        indices = mmGraphics.GetIndicesAll();
        colors = mmGraphics.GetColorsAll();

        auto stopMove = std::chrono::high_resolution_clock::now();
        auto durationMoveDown = std::chrono::duration_cast<std::chrono::milliseconds>(stopMove - startMoveDown);
        auto durationMoveSide = std::chrono::duration_cast<std::chrono::milliseconds>(stopMove - startMoveSide);
        auto durationRotate = std::chrono::duration_cast<std::chrono::milliseconds>(stopMove - startRotate);
        if (durationMoveDown.count() > 100)
        {
            mmTetris.moveDown = true;
            startMoveDown = stopMove;
        }
        if (durationMoveSide.count() > 150)
        {
            mmTetris.moveSide = true;
            startMoveSide = stopMove;
        }
        if (durationRotate.count() > 350)
        {
            mmTetris.rotate = true;
            startRotate = stopMove;
        }

        camera.Inputs(window);
        mmTetris.Update(window);
        camera.Matrix(45.0f, 0.1f, 100.0f, shaderProgram, "camMatrix");

        VAO VAO1;
        VAO1.Bind();

        GLfloat *verticesArr = &vertices[0];
        GLfloat *colorsArr = &colors[0];
        GLuint *indicesArr = &indices[0];

        VBO VBO1(verticesArr, vertices.size() * sizeof(GLfloat));
        VBO VBO2(colorsArr, colors.size() * sizeof(GLfloat));
        EBO EBO1(indicesArr, indices.size() * sizeof(GLint));

        VAO1.LinkAttrib(VBO1, 0, 3, GL_FLOAT, 3 * sizeof(float), (void *)0);
        VAO1.LinkAttrib(VBO2, 1, 3, GL_FLOAT, 3 * sizeof(float), (void *)0);
        VAO1.Unbind();
        VBO1.Unbind();
        VBO2.Unbind();
        EBO1.Unbind();

        glClearColor(0.07f, 0.13f, 0.17f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        shaderProgram.Activate();

        VAO1.Bind();
        glDrawElements(GL_TRIANGLES, cubeIndices * mmTetris.blocksCount, GL_UNSIGNED_INT, 0);
        glfwSwapBuffers(window);

        glfwPollEvents();

        VAO1.Delete();
        VBO1.Delete();
        EBO1.Delete();
        VBO2.Delete();

        // std::cout << duration.count() << std::endl;
    }
    shaderProgram.Delete();

    glfwDestroyWindow(window);
    glfwTerminate();
    return 0;
}