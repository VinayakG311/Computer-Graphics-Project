// Assignment 03: Lighting and shading

/*References
  Trackball: http://en.wikibooks.org/wiki/OpenGL_Programming/Modern_OpenGL_Tutorial_Arcball
*/

#include "utils.h"

#define GLM_FORCE_RADIANS
#define GLM_ENABLE_EXPERIMENTAL

#include <glm/gtc/type_ptr.hpp>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtx/string_cast.hpp>
#include <iostream>
#include <cage.hpp>
using namespace std;
// Globals
int screen_width = 640, screen_height = 640;
GLint vModel_uniform, vView_uniform, vProjection_uniform;
GLint vColor_uniform;
glm::mat4 modelT, viewT, projectionT;
int val, val2; // The model, view and projection transformations
// vector<float> v;
double oldX, oldY, currentX, currentY;
bool isDragging = false;

GLfloat max_x_coord = INT_MIN;
GLfloat max_y_coord = INT_MIN;

GLfloat min_x_coord = INT_MAX;
GLfloat min_y_coord = INT_MAX;

GLfloat min_z_coord = INT_MAX;
GLfloat max_z_coord = INT_MIN;

vector<float> controlPoints;

int LoadObj(char *, unsigned int &, unsigned int &);
int createCage(unsigned int &, unsigned int &, vector<float> &);
void setupModelTransformation(unsigned int &);
void setupViewTransformation(unsigned int &);
void setupProjectionTransformation(unsigned int &);
glm::vec3 getTrackBallVector(double x, double y);

vector<float> cage1;
vector<float> cage2;
vector<float> cage3;
vector<float> cage4;
vector<float> cage5;
vector<float> cage6;
int grid1[7][7], grid2[7][7], grid3[7][7], grid4[7][7], grid5[7][7], grid6[7][7];

int main(int, char **)
{

    // Setup window
    GLFWwindow *window = setupWindow(screen_width, screen_height);
    ImGuiIO &io = ImGui::GetIO(); // Create IO object

    ImVec4 clearColor = ImVec4(1.0f, 1.0f, 1.0f, 1.00f);

    unsigned int shaderProgram = createProgram("./shaders/vshader.vs", "./shaders/fshader.fs");

    // Get handle to color variable in shader
    vColor_uniform = glGetUniformLocation(shaderProgram, "vColor");
    if (vColor_uniform == -1)
    {
        fprintf(stderr, "Could not bind location: vColor\n");
        exit(0);
    }

    glUseProgram(shaderProgram);

    unsigned int VAO, VAO2, VAO3, VAO4, VAO5, VAO6;
    glGenVertexArrays(1, &VAO);
    glGenVertexArrays(1, &VAO2);
    glGenVertexArrays(1, &VAO3);
    glGenVertexArrays(1, &VAO4);
    glGenVertexArrays(1, &VAO5);
    glGenVertexArrays(1, &VAO6);

    unsigned int cage1_VAO, cage2_VAO, cage3_VAO, cage4_VAO, cage5_VAO, cage6_VAO, VAO_controlPoints;
    unsigned int VBO_controlPoints;

    glGenVertexArrays(1, &cage1_VAO);
    glGenVertexArrays(1, &cage2_VAO);
    glGenVertexArrays(1, &cage3_VAO);
    glGenVertexArrays(1, &cage4_VAO);
    glGenVertexArrays(1, &cage5_VAO);
    glGenVertexArrays(1, &cage6_VAO);
    // glGenVertexArrays(1,&controlPoints_VAO);

    setupModelTransformation(shaderProgram);
    setupViewTransformation(shaderProgram);
    setupProjectionTransformation(shaderProgram);

    //  createCubeObject(shaderProgram, VAO);

    glGenBuffers(1, &VBO_controlPoints);
    glGenVertexArrays(1, &VAO_controlPoints);

    char *file1 = "/Users/vinayakgoel/Desktop/Computer-Graphics-Project/code-7/data/body2d.obj";
    char *file2 = "/Users/vinayakgoel/Desktop/Computer-Graphics-Project/code-7/data/lh2d.obj";
    char *file3 = "/Users/vinayakgoel/Desktop/Computer-Graphics-Project/code-7/data/rh2d.obj";
    char *file4 = "/Users/vinayakgoel/Desktop/Computer-Graphics-Project/code-7/data/head-new2d.obj";
    char *file5 = "/Users/vinayakgoel/Desktop/Computer-Graphics-Project/code-7/data/rl2d.obj";
    char *file6 = "/Users/vinayakgoel/Desktop/Computer-Graphics-Project/code-7/data/ll2d.obj";

    int mesh1size = LoadObj(file1, shaderProgram, VAO);
    int cage1size = createCage(shaderProgram, cage1_VAO, cage1);

    int mesh2size = LoadObj(file2, shaderProgram, VAO2);
    int cage2size = createCage(shaderProgram, cage2_VAO, cage2);

    int mesh3size = LoadObj(file3, shaderProgram, VAO3);
    int cage3size = createCage(shaderProgram, cage3_VAO, cage3);

    int mesh4size = LoadObj(file4, shaderProgram, VAO4);
    int cage4size = createCage(shaderProgram, cage4_VAO, cage4);

    int mesh5size = LoadObj(file5, shaderProgram, VAO5);
    int cage5size = createCage(shaderProgram, cage5_VAO, cage5);

    int mesh6size = LoadObj(file6, shaderProgram, VAO6);
    int cage6size = createCage(shaderProgram, cage6_VAO, cage6);

    oldX = oldY = currentX = currentY = 0.0;
    int prevLeftButtonState = GLFW_RELEASE;

    while (!glfwWindowShouldClose(window))
    {

        glfwPollEvents();

        // Get current mouse position
        int leftButtonState = glfwGetMouseButton(window, GLFW_MOUSE_BUTTON_LEFT);
        double x, y;
        glfwGetCursorPos(window, &x, &y);
        if (leftButtonState == GLFW_PRESS && prevLeftButtonState == GLFW_RELEASE)
        {
            isDragging = true;
            currentX = oldX = x;
            currentY = oldY = y;
        }
        else if (leftButtonState == GLFW_PRESS && prevLeftButtonState == GLFW_PRESS)
        {
            currentX = x;
            currentY = y;
        }
        else if (leftButtonState == GLFW_RELEASE && prevLeftButtonState == GLFW_PRESS)
        {
            isDragging = false;
        }

        // Rotate based on mouse drag movement
        prevLeftButtonState = leftButtonState;
        if (isDragging && (currentX != oldX || currentY != oldY))
        {
            glm::vec3 va = getTrackBallVector(oldX, oldY);
            glm::vec3 vb = getTrackBallVector(currentX, currentY);

            float angle = acos(std::min(1.0f, glm::dot(va, vb)));
            glm::vec3 axis_in_camera_coord = glm::cross(va, vb);
            glm::mat3 camera2object = glm::inverse(glm::mat3(viewT * modelT));
            glm::vec3 axis_in_object_coord = camera2object * axis_in_camera_coord;
            modelT = glm::rotate(modelT, angle, axis_in_object_coord);
            glUniformMatrix4fv(vModel_uniform, 1, GL_FALSE, glm::value_ptr(modelT));

            oldX = currentX;
            oldY = currentY;
        }

        // Start the Dear ImGui frame
        ImGui_ImplOpenGL3_NewFrame();
        ImGui_ImplGlfw_NewFrame();
        ImGui::NewFrame();

        glUseProgram(shaderProgram);

        {
            ImGui::Begin("Information");
            ImGui::Text("%.3f ms/frame (%.1f FPS)", 1000.0f / ImGui::GetIO().Framerate, ImGui::GetIO().Framerate);
            ImGui::End();
        }

        glBindVertexArray(VAO_controlPoints);
        glBindBuffer(GL_ARRAY_BUFFER, VBO_controlPoints);
        glBufferData(GL_ARRAY_BUFFER, controlPoints.size() * sizeof(GLfloat), &controlPoints[0], GL_DYNAMIC_DRAW);
        glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void *)0);
        glEnableVertexAttribArray(0);

        // Rendering
        ImGui::Render();
        int display_w, display_h;
        glfwGetFramebufferSize(window, &display_w, &display_h);
        glViewport(0, 0, display_w, display_h);
        glClearColor(clearColor.x, clearColor.y, clearColor.z, clearColor.w);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        glBindVertexArray(VAO);
        glUniform3f(vColor_uniform, 0.5, 0.5, 0.5);
        glDrawArrays(GL_TRIANGLES, 0, mesh1size);

        glBindVertexArray(VAO2);
        glUniform3f(vColor_uniform, 0.5, 0.5, 0.5);
        glDrawArrays(GL_TRIANGLES, 0, mesh2size);

        glBindVertexArray(VAO3);
        glUniform3f(vColor_uniform, 0.5, 0.5, 0.5);
        glDrawArrays(GL_TRIANGLES, 0, mesh3size);

        glBindVertexArray(VAO4);
        glUniform3f(vColor_uniform, 0.5, 0.5, 0.5);
        glDrawArrays(GL_TRIANGLES, 0, mesh4size);

        glBindVertexArray(VAO5);
        glUniform3f(vColor_uniform, 0.5, 0.5, 0.5);
        glDrawArrays(GL_TRIANGLES, 0, mesh5size);

        glBindVertexArray(VAO6);
        glUniform3f(vColor_uniform, 0.5, 0.5, 0.5);
        glDrawArrays(GL_TRIANGLES, 0, mesh6size);

        glBindVertexArray(cage1_VAO);
        glUniform3f(vColor_uniform, 0.5, 0.5, 0.5);
        glDrawArrays(GL_LINES, 0, cage1size / 3);

        glBindVertexArray(cage2_VAO);
        glUniform3f(vColor_uniform, 0.5, 0.5, 0.5);
        glDrawArrays(GL_LINES, 0, cage2size / 3);

        glBindVertexArray(cage3_VAO);
        glUniform3f(vColor_uniform, 0.5, 0.5, 0.5);
        glDrawArrays(GL_LINES, 0, cage3size / 3);

        glBindVertexArray(cage4_VAO);
        glUniform3f(vColor_uniform, 0.5, 0.5, 0.5);
        glDrawArrays(GL_LINES, 0, cage4size / 3);

        glBindVertexArray(cage5_VAO);
        glUniform3f(vColor_uniform, 0.5, 0.5, 0.5);
        glDrawArrays(GL_LINES, 0, cage5size / 3);

        glBindVertexArray(cage6_VAO);
        glUniform3f(vColor_uniform, 0.5, 0.5, 0.5);
        glDrawArrays(GL_LINES, 0, cage6size / 3);

        glBindVertexArray(VAO_controlPoints);
        glDrawArrays(GL_POINTS, 0, controlPoints.size() / 3);
        //

        ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());

        glfwSwapBuffers(window);
    }

    // Cleanup
    cleanup(window);

    return 0;
}
int createCage(unsigned int &program, unsigned int &obj_VAO, vector<float> &cage)
{
    glUseProgram(program);

    // Bind shader variables
    int vVertex_attrib = glGetAttribLocation(program, "vVertex");
    if (vVertex_attrib == -1)
    {
        fprintf(stderr, "Could not bind location: vVertex\n");
        exit(0);
    }

    vector<float> v;
    cage.push_back(min_x_coord - 0.2);
    cage.push_back(min_y_coord - 0.2);
    cage.push_back(min_z_coord - 0.2);

    cage.push_back(min_x_coord - 0.2);
    cage.push_back(max_y_coord + 0.2);
    cage.push_back(min_z_coord - 0.2);

    cage.push_back(min_x_coord - 0.2);
    cage.push_back(max_y_coord + 0.2);
    cage.push_back(min_z_coord - 0.2);

    cage.push_back(max_x_coord + 0.2);
    cage.push_back(max_y_coord + 0.2);
    cage.push_back(min_z_coord - 0.2);

    cage.push_back(max_x_coord + 0.2);
    cage.push_back(max_y_coord + 0.2);
    cage.push_back(min_z_coord - 0.2);

    cage.push_back(max_x_coord + 0.2);
    cage.push_back(min_y_coord - 0.2);
    cage.push_back(min_z_coord - 0.2);

    cage.push_back(max_x_coord + 0.2);
    cage.push_back(min_y_coord - 0.2);
    cage.push_back(min_z_coord - 0.2);

    cage.push_back(min_x_coord - 0.2);
    cage.push_back(min_y_coord - 0.2);
    cage.push_back(min_z_coord - 0.2);

    cage.push_back(min_x_coord - 0.2);
    cage.push_back(min_y_coord - 0.2);
    cage.push_back(max_z_coord + 0.2);

    cage.push_back(min_x_coord - 0.2);
    cage.push_back(max_y_coord + 0.2);
    cage.push_back(max_z_coord + 0.2);

    cage.push_back(min_x_coord - 0.2);
    cage.push_back(max_y_coord + 0.2);
    cage.push_back(max_z_coord + 0.2);

    cage.push_back(max_x_coord + 0.2);
    cage.push_back(max_y_coord + 0.2);
    cage.push_back(max_z_coord + 0.2);

    cage.push_back(max_x_coord + 0.2);
    cage.push_back(max_y_coord + 0.2);
    cage.push_back(max_z_coord + 0.2);

    cage.push_back(max_x_coord + 0.2);
    cage.push_back(min_y_coord - 0.2);
    cage.push_back(max_z_coord + 0.2);

    cage.push_back(max_x_coord + 0.2);
    cage.push_back(min_y_coord - 0.2);
    cage.push_back(max_z_coord + 0.2);

    cage.push_back(min_x_coord - 0.2);
    cage.push_back(min_y_coord - 0.2);
    cage.push_back(max_z_coord + 0.2);

    cage.push_back(min_x_coord - 0.2);
    cage.push_back(min_y_coord - 0.2);
    cage.push_back(min_z_coord - 0.2);

    cage.push_back(min_x_coord - 0.2);
    cage.push_back(min_y_coord - 0.2);
    cage.push_back(max_z_coord + 0.2);

    cage.push_back(min_x_coord - 0.2);
    cage.push_back(max_y_coord + 0.2);
    cage.push_back(min_z_coord - 0.2);

    cage.push_back(min_x_coord - 0.2);
    cage.push_back(max_y_coord + 0.2);
    cage.push_back(max_z_coord + 0.2);

    cage.push_back(max_x_coord + 0.2);
    cage.push_back(min_y_coord - 0.2);
    cage.push_back(min_z_coord - 0.2);

    cage.push_back(max_x_coord + 0.2);
    cage.push_back(min_y_coord - 0.2);
    cage.push_back(max_z_coord + 0.2);

    cage.push_back(max_x_coord + 0.2);
    cage.push_back(max_y_coord + 0.2);
    cage.push_back(min_z_coord - 0.2);

    cage.push_back(max_x_coord + 0.2);
    cage.push_back(max_y_coord + 0.2);
    cage.push_back(max_z_coord + 0.2);
    int grid[100][100];
    int stepx = (max_x_coord - min_x_coord) / 100;
    int stepy = (max_y_coord - min_y_coord) / 100;
    for (int i = min_x_coord; i <= max_x_coord; i += stepx)
    {
        for (int j = min_y_coord; j <= max_y_coord; j += stepy)
        {
            if (i == max_x_coord || i == min_x_coord || j == min_y_coord || j == max_y_coord)
            {
                // Exterior/Boundary
                grid[i][j] = 1;
            }
            else
            {
                // Interior
                grid[i][j] = -1;
            }
        }
    }
    vector<float> cubicBezier;

    bool first = true;
    int sz = cage.size(); // Contains 3 points/vertex. Ignore Z
    float x[4], y[4], z[4];
    float delta_t = 1.0 / (100.0 - 1.0);
    float t;
    float prevX, prevY;

    for (int i = 0; i < (sz - 3); i += 3)
    {
        x[0] = cage[i];
        y[0] = cage[i + 1];
        z[0] = cage[i + 2];
        x[3] = cage[i + 3];
        y[3] = cage[i + 4];
        z[3] = cage[i + 5];
        cubicBezier.push_back(x[0]);
        cubicBezier.push_back(y[0]);
        cubicBezier.push_back(z[0]);
        controlPoints.push_back(x[0]);
        controlPoints.push_back(y[0]);
        controlPoints.push_back(z[0]);
    }

    cubicBezier.push_back(x[3]);
    cubicBezier.push_back(y[3]);
    cubicBezier.push_back(z[3]);
    controlPoints.push_back(x[3]);
    controlPoints.push_back(y[3]);
    controlPoints.push_back(z[3]);

    glGenVertexArrays(1, &obj_VAO);
    glBindVertexArray(obj_VAO);
    GLuint vertex_VBO;
    // cout << v.size() << endl;

    glGenBuffers(1, &vertex_VBO);
    glBindBuffer(GL_ARRAY_BUFFER, vertex_VBO);
    glBufferData(GL_ARRAY_BUFFER, cubicBezier.size() * sizeof(GLfloat), &cubicBezier[0], GL_STATIC_DRAW);
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0);
    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindVertexArray(0);

    min_x_coord = INT_MAX;
    min_y_coord = INT_MAX;
    min_z_coord = INT_MAX;

    max_x_coord = INT_MIN;
    max_y_coord = INT_MIN;
    max_z_coord = INT_MIN;

    return cubicBezier.size();
}
int LoadObj(char *path, unsigned int &program, unsigned int &obj_VAO)
{
    FILE *ObjFile = fopen(path, "r");
    if (ObjFile == NULL)
    {
        cout << "Error Opening Obj File";
        return -1;
    }
    glUseProgram(program);

    // Bind shader variables
    int vVertex_attrib = glGetAttribLocation(program, "vVertex");
    if (vVertex_attrib == -1)
    {
        fprintf(stderr, "Could not bind location: vVertex\n");
        exit(0);
    }

    vector<float> VertexDataTemp;
    vector<float> FaceDataTemp;
    while (true)
    {
        char data[1024];
        int recv = fscanf(ObjFile, "%s\n", data);

        if (recv < 0)
        {
            break;
        }

        glm::vec3 vertices;
        glm::vec4 faces;
        if (!strcmp(data, "v"))
        {
            fscanf(ObjFile, "%f %f %f\n", &vertices.x, &vertices.y, &vertices.z);
            VertexDataTemp.push_back(vertices.x * 2);
            VertexDataTemp.push_back(vertices.y * 2);
            VertexDataTemp.push_back(vertices.z * 2);

            max_x_coord = max(max_x_coord, vertices.x * 2);
            max_y_coord = max(max_y_coord, vertices.y * 2);

            min_x_coord = min(min_x_coord, vertices.x * 2);
            min_y_coord = min(min_y_coord, vertices.y * 2);

            max_z_coord = max(max_z_coord, vertices.z * 2);
            min_z_coord = min(min_z_coord, vertices.z * 2);
        }
        if (!strcmp(data, "f"))
        {
            float f1, f2, f3, f4, f5, f6, f7, f8, f9;
            fscanf(ObjFile, "%f/%f/%f %f/%f/%f %f/%f/%f \n", &f1, &f4, &f7, &f2, &f5, &f8, &f3, &f6, &f9);

            FaceDataTemp.push_back((f1 - 1));
            FaceDataTemp.push_back((f2 - 1));
            FaceDataTemp.push_back((f3 - 1));
        }
    }
    glGenVertexArrays(1, &obj_VAO);
    glBindVertexArray(obj_VAO);
    float v[FaceDataTemp.size() * 3];
    val = FaceDataTemp.size();
    for (int i = 0; i < FaceDataTemp.size(); i++)
    {
        v[i * 3] = VertexDataTemp[FaceDataTemp[i] * 3];
        v[i * 3 + 1] = VertexDataTemp[FaceDataTemp[i] * 3 + 1];
        v[i * 3 + 2] = VertexDataTemp[FaceDataTemp[i] * 3 + 2];
    }
    // cout << VertexDataTemp.size() << " " << FaceDataTemp.size() << endl;

    GLuint vertex_VBO;
    glGenBuffers(1, &vertex_VBO);
    glBindBuffer(GL_ARRAY_BUFFER, vertex_VBO);
    glBufferData(GL_ARRAY_BUFFER, FaceDataTemp.size() * 3 * sizeof(float), v, GL_STATIC_DRAW);
    glEnableVertexAttribArray(vVertex_attrib);
    glVertexAttribPointer(vVertex_attrib, 3, GL_FLOAT, GL_FALSE, 0, 0);

    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindVertexArray(0); // Unbind the VAO to disable changes outside this function.

    return FaceDataTemp.size();
}

void setupModelTransformation(unsigned int &program)
{
    // Modelling transformations (Model -> World coordinates)
    modelT = glm::translate(glm::mat4(1.0f), glm::vec3(0.0, 0.0, 0.0)); // Model coordinates are the world coordinates

    // Pass on the modelling matrix to the vertex shader
    glUseProgram(program);
    vModel_uniform = glGetUniformLocation(program, "vModel");
    if (vModel_uniform == -1)
    {
        fprintf(stderr, "Could not bind location: vModel\n");
        exit(0);
    }
    glUniformMatrix4fv(vModel_uniform, 1, GL_FALSE, glm::value_ptr(modelT));
}

void setupViewTransformation(unsigned int &program)
{
    // Viewing transformations (World -> Camera coordinates
    // Camera at (0, 0, 100) looking down the negative Z-axis in a right handed coordinate system
    viewT = glm::lookAt(glm::vec3(40.0, -40.0, 40.0), glm::vec3(0.0, 0.0, 0.0), glm::vec3(0.0, 1.0, 0.0));

    // Pass-on the viewing matrix to the vertex shader
    glUseProgram(program);
    vView_uniform = glGetUniformLocation(program, "vView");
    if (vView_uniform == -1)
    {
        fprintf(stderr, "Could not bind location: vView\n");
        exit(0);
    }
    glUniformMatrix4fv(vView_uniform, 1, GL_FALSE, glm::value_ptr(viewT));
}

void setupProjectionTransformation(unsigned int &program)
{
    // Projection transformation
    projectionT = glm::perspective(45.0f, (GLfloat)screen_width / (GLfloat)screen_height, 0.1f, 1000.0f);

    // Pass on the projection matrix to the vertex shader
    glUseProgram(program);
    vProjection_uniform = glGetUniformLocation(program, "vProjection");
    if (vProjection_uniform == -1)
    {
        fprintf(stderr, "Could not bind location: vProjection\n");
        exit(0);
    }
    glUniformMatrix4fv(vProjection_uniform, 1, GL_FALSE, glm::value_ptr(projectionT));
}

glm::vec3 getTrackBallVector(double x, double y)
{
    glm::vec3 p = glm::vec3(2.0 * x / screen_width - 1.0, 2.0 * y / screen_height - 1.0, 0.0); // Normalize to [-1, +1]
    p.y = -p.y;                                                                                // Invert Y since screen coordinate and OpenGL coordinates have different Y directions.

    float mag2 = p.x * p.x + p.y * p.y;
    if (mag2 <= 1.0f)
        p.z = sqrtf(1.0f - mag2);
    else
        p = glm::normalize(p); // Nearest point, close to the sides of the trackball
    return p;
}
