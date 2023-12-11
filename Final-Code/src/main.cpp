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
#include <vector>
#include "cage.hpp"
using namespace std;
// Globals
int screen_width = 640, screen_height = 640;
GLint vModel_uniform, vView_uniform, vProjection_uniform;
GLint vColor_uniform;
glm::mat4 modelT, viewT, projectionT;
int val, val2; // The model, view and projection transformations
// vector<float> v;

// For camera rotation
double oldX, oldY, currentX, currentY;
bool isDragging = false;
bool rotater = true;
bool editer = false;

bool movement = false;

GLfloat max_x_coord = INT_MIN;
GLfloat max_y_coord = INT_MIN;

GLfloat min_x_coord = INT_MAX;
GLfloat min_y_coord = INT_MAX;

GLfloat min_z_coord = INT_MAX;
GLfloat max_z_coord = INT_MIN;
vector<GLfloat> VertexData;
bool controlPointsUpdated = false;

int selectedControlPoint = 0;
int selectedMovePoint = 0;

vector<float> controlPoints;
vector<float> MovePoints;

// Storing mesh coordinates for each mesh
vector<GLfloat> mesh1;
vector<GLfloat> mesh2;
vector<GLfloat> mesh3;
vector<GLfloat> mesh4;
vector<GLfloat> mesh5;
vector<GLfloat> mesh6;
vector<GLfloat> mesh7;
vector<GLfloat> mesh8;

int LoadObj(char *, unsigned int &, unsigned int &, vector<GLfloat> &);
void editControlPoint(std::vector<float> &, float, float, int, int);
bool searchNearestControlPoint(float, float);
void mousemoved();
void getcageandupdate(Cage &, float, float, float, float, float, unsigned int &, unsigned int &, vector<GLfloat> &, int);
void getcageandupdate2(Cage &, float, float, float, float, float, unsigned int &, unsigned int &, vector<GLfloat> &, int,bool,bool);
void setupModelTransformation(unsigned int &);
void setupViewTransformation(unsigned int &);
void setupProjectionTransformation(unsigned int &);
glm::vec3 getTrackBallVector(double x, double y);
void setter();
void pushpoints(Cage &);
void computeCage();

// Storing cage coordinates for each cage
vector<float> cage1;
vector<float> cage2;
vector<float> cage3;
vector<float> cage4;
vector<float> cage5;
vector<float> cage6;
vector<float> cage7;
vector<float> cage8;

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

    // Vertex array objects for each mesh
    unsigned int VAO, VAO2, VAO3, VAO4, VAO5, VAO6,VAO7,VAO8;
    glGenVertexArrays(1, &VAO);
    glGenVertexArrays(1, &VAO2);
    glGenVertexArrays(1, &VAO3);
    glGenVertexArrays(1, &VAO4);
    glGenVertexArrays(1, &VAO5);
    glGenVertexArrays(1, &VAO6);
    glGenVertexArrays(1, &VAO7);
    glGenVertexArrays(1, &VAO8);

    // Vertex array objects for each cage of the mesh
    unsigned int cage1_VAO, cage2_VAO, cage3_VAO, cage4_VAO, cage5_VAO, cage6_VAO, VAO_controlPoints, VAO1, VAO_move,cage7_VAO,cage8_VAO;
    unsigned int VBO_controlPoints, VBO1, VBO_move;

    glGenVertexArrays(1, &cage1_VAO);
    glGenVertexArrays(1, &cage2_VAO);
    glGenVertexArrays(1, &cage3_VAO);
    glGenVertexArrays(1, &cage4_VAO);
    glGenVertexArrays(1, &cage5_VAO);
    glGenVertexArrays(1, &cage6_VAO);
    glGenVertexArrays(1, &cage7_VAO);
    glGenVertexArrays(1, &cage8_VAO);
    glGenVertexArrays(1, &VAO_move);
    glGenBuffers(1, &VBO_move);

    // glGenVertexArrays(1,&controlPoints_VAO);

    setupModelTransformation(shaderProgram);
    setupViewTransformation(shaderProgram);
    setupProjectionTransformation(shaderProgram);

    //  createCubeObject(shaderProgram, VAO);

    glGenBuffers(1, &VBO_controlPoints);
    glGenVertexArrays(1, &VAO_controlPoints);

    glGenBuffers(1, &VBO1);
    glGenVertexArrays(1, &VAO1);
    char *file1 = "../Final-Code/data-new/body.obj";
    char *file2 = "../Final-Code/data-new/lh.obj";
    char *file3 = "../Final-Code/data-new/rh.obj";
    char *file4 = "../Final-Code/data-new/head.obj";
    char *file5 = "../Final-Code/data-new/rl.obj";
    char *file6 = "../Final-Code/data-new/ll.obj";
    char *file7 = "../Final-Code/data-new/er.obj";
    char *file8 = "../Final-Code/data-new/el.obj";
    controlPoints.clear();

    int mesh1size = LoadObj(file1, shaderProgram, VAO, mesh1);                                       // Loading and storing mesh 1
    Cage c1 = Cage(max_x_coord, max_y_coord, min_x_coord, min_y_coord, min_z_coord, max_z_coord, 0); // Initializing cage class for mesh 1
    int cage1size = c1.createCage3d(shaderProgram, cage1_VAO, controlPoints);                        // Creating cage for mesh 1
    setter();
    c1.createGrid(); // Creating grid for cage 1 of size 100 X 100 to compute harmonic coordinate values
    pushpoints(c1);
    VertexData.clear();
    int mesh2size = LoadObj(file2, shaderProgram, VAO2, mesh2);                                       // Loading and storing mesh 2
    Cage c2 = Cage(max_x_coord, max_y_coord, min_x_coord, min_y_coord, min_z_coord, max_z_coord, 12); // Initializing cage class for mesh 2
    int cage2size = c2.createCage3d(shaderProgram, cage2_VAO, controlPoints);                         // Creating cage for mesh 2
    setter();
    pushpoints(c2);
    c2.createGrid(); // Creating grid for cage 2 of size 100 X 100 to compute harmonic coordinate values

    int mesh3size = LoadObj(file3, shaderProgram, VAO3, mesh3);                                       // Loading and storing mesh 3
    Cage c3 = Cage(max_x_coord, max_y_coord, min_x_coord, min_y_coord, min_z_coord, max_z_coord, 24); // Initializing cage class for mesh 3
    int cage3size = c3.createCage3d(shaderProgram, cage3_VAO, controlPoints);                         // Creating cage for mesh 3
    setter();
    pushpoints(c3);
    // // cout << c3.max_x_coord << " " << c3.max_y_coord << endl;
    c3.createGrid(); // Creating grid for cage 3 of size 100 X 100 to compute harmonic coordinate values

    int mesh4size = LoadObj(file4, shaderProgram, VAO4, mesh4);                                       // Loading and storing mesh 4
    Cage c4 = Cage(max_x_coord, max_y_coord, min_x_coord, min_y_coord, min_z_coord, max_z_coord, 36); // Initializing cage class for mesh 4
    int cage4size = c4.createCage3d(shaderProgram, cage4_VAO, controlPoints);                         // Creating cage for mesh 4
    setter();
    pushpoints(c4);
    c4.createGrid(); // Creating grid for cage 4 of size 100 X 100 to compute harmonic coordinate values

    int mesh5size = LoadObj(file5, shaderProgram, VAO5, mesh5);                                       // Loading and storing mesh 5
    Cage c5 = Cage(max_x_coord, max_y_coord, min_x_coord, min_y_coord, min_z_coord, max_z_coord, 48); // Initializing cage class for mesh 5
    int cage5size = c5.createCage3d(shaderProgram, cage5_VAO, controlPoints);                         // Creating cage for mesh 5
    setter();
    pushpoints(c5);
    c5.createGrid(); // Creating grid for cage 5 of size 100 X 100 to compute harmonic coordinate values

    int mesh6size = LoadObj(file6, shaderProgram, VAO6, mesh6);                                       // Loading and storing mesh 6
    Cage c6 = Cage(max_x_coord, max_y_coord, min_x_coord, min_y_coord, min_z_coord, max_z_coord, 60); // Initializing cage class for mesh 6
    int cage6size = c6.createCage3d(shaderProgram, cage6_VAO, controlPoints);                         // Creating cage for mesh 6
    setter();
    pushpoints(c6);
    c6.createGrid(); // Creating grid for cage 6 of size 100 X 100 to compute harmonic coordinate values

    int mesh7size = LoadObj(file7, shaderProgram, VAO7, mesh7);
    Cage c7 = Cage(max_x_coord, max_y_coord, min_x_coord, min_y_coord, min_z_coord, max_z_coord, 60); // Initializing cage class for mesh 6
    int cage7size = c7.createCage3d(shaderProgram, cage7_VAO, controlPoints);                         // Creating cage for mesh 6
    setter();
    pushpoints(c7);
    c7.createGrid(); // Creating grid for cage 6 of size 100 X 100 to compute harmonic coordinate values

    int mesh8size = LoadObj(file8, shaderProgram, VAO8, mesh8);
    Cage c8 = Cage(max_x_coord, max_y_coord, min_x_coord, min_y_coord, min_z_coord, max_z_coord, 60); // Initializing cage class for mesh 6
    int cage8size = c8.createCage3d(shaderProgram, cage8_VAO, controlPoints);                         // Creating cage for mesh 6
    setter();
    pushpoints(c8);
    c8.createGrid(); // Creating grid for cage 6 of size 100 X 100 to compute harmonic coordinate values

    oldX = oldY = currentX = currentY = 0.0;
    int prevLeftButtonState = GLFW_RELEASE;
    float x, y;

    while (!glfwWindowShouldClose(window))
    {

        glfwPollEvents();
        if (ImGui::IsKeyPressed(ImGui::GetKeyIndex(ImGuiKey_Z)))
        { // Stop adding points
            movement = false;
            rotater = false;
            editer = true;
        }
        if (ImGui::IsKeyPressed(ImGui::GetKeyIndex(ImGuiKey_X)))
        { // Stop adding points
            movement = false;
            rotater = true;
            editer = false;
        }
        if (ImGui::IsKeyPressed(ImGui::GetKeyIndex(ImGuiKey_Y)))
        { // Stop adding points

            movement = true;
            rotater = false;
            editer = false;
        }

        if (editer)
        {

            float newx, newy, oldx, oldy;
            if (ImGui::IsMouseClicked(ImGuiMouseButton_Left))
            {
                double xpos, ypos;
                glfwGetCursorPos(glfwGetCurrentContext(), &xpos, &ypos);

                glm::vec4 viewport = glm::vec4(0.0f, 0.0f, screen_width, screen_height);
                glm::vec3 winPos = glm::vec3(xpos, screen_height - ypos, 0.0f);
                glm::vec3 worldPos = glm::unProject(winPos, projectionT * viewT * modelT, glm::inverse(projectionT * viewT * modelT), viewport);


                // cout << worldPos[0] << " " << worldPos[1] << endl;
                glm::vec3 va = getTrackBallVector(xpos, ypos);
                glm::vec4 w = glm::inverse(modelT) * glm::vec4(va, 1.0f);
                // cout << va[0] << " " << va[1] << " " << w[0] << " " << w[1] << endl;
            }
            // Updating position of control points based on user input WASD

            if (ImGui::IsKeyPressed(ImGui::GetKeyIndex(ImGuiKey_RightArrow)))
            {
                selectedControlPoint++;
                if (selectedControlPoint > controlPoints.size() / 3)
                {
                    selectedControlPoint = 0;
                }
            }
            if (ImGui::IsKeyPressed(ImGui::GetKeyIndex(ImGuiKey_LeftArrow)))
            {
                selectedControlPoint--;
                if (selectedControlPoint < 0)
                {
                    selectedControlPoint = controlPoints.size() / 3 - 1;
                }
            }

            if (ImGui::IsKeyPressed(GLFW_KEY_W))
            {
                // controlPoints[0] = controlPoints[0]+2.5f;
                oldy = controlPoints[3 * selectedControlPoint + 1];
                oldx = controlPoints[3 * selectedControlPoint];
                newy = controlPoints[3 * selectedControlPoint + 1] + 2.5f;
                newx = controlPoints[3 * selectedControlPoint];
                controlPointsUpdated = true;
                // c1.max_y_coord = max(c1.max_y_coord,controlPoints[1]);
            }

            else if (ImGui::IsKeyPressed(GLFW_KEY_A))
            {
                // controlPoints[0] = controlPoints[0]+2.5f;
                oldx = controlPoints[3 * selectedControlPoint];
                oldy = controlPoints[3 * selectedControlPoint + 1];
                newx = controlPoints[3 * selectedControlPoint] - 2.5f;
                newy = controlPoints[3 * selectedControlPoint + 1];
                controlPointsUpdated = true;
                // c1.min_x_coord = max(c1.min_x_coord,controlPoints[1]);
            }

            else if (ImGui::IsKeyPressed(GLFW_KEY_D))
            {
                // controlPoints[0] = controlPoints[0]+2.5f;
                oldx = controlPoints[3 * selectedControlPoint];
                newx = controlPoints[3 * selectedControlPoint] + 2.5f;
                oldy = controlPoints[3 * selectedControlPoint + 1];
                newy = controlPoints[3 * selectedControlPoint + 1];
                controlPointsUpdated = true;
            }

            else if (ImGui::IsKeyPressed(GLFW_KEY_S))
            {
                // controlPoints[0] = controlPoints[0]+2.5f;
                oldy = controlPoints[3 * selectedControlPoint + 1];
                newy = controlPoints[3 * selectedControlPoint + 1] - 2.5f;
                oldx = controlPoints[3 * selectedControlPoint];
                newx = controlPoints[3 * selectedControlPoint];
                controlPointsUpdated = true;
            }

            if (controlPointsUpdated)
            {

                for (int i = 0; i < controlPoints.size(); i += 3)
                {
                    if (controlPoints[i] == oldx && controlPoints[i + 1] == oldy)
                    {
                        controlPoints[i] = newx;
                        controlPoints[i + 1] = newy;
                    }
                }
     
                if (selectedControlPoint < 5)
                {
                    getcageandupdate(c1, oldx, oldy, newx, newy, selectedControlPoint, shaderProgram, VAO, mesh1, selectedControlPoint);
                }
                else if (selectedControlPoint >= 5 && selectedControlPoint < 10)
                {
                    getcageandupdate(c2, oldx, oldy, newx, newy, selectedControlPoint, shaderProgram, VAO2, mesh2, selectedControlPoint);
                }
                else if (selectedControlPoint >= 10 && selectedControlPoint < 15)
                {
                    getcageandupdate(c3, oldx, oldy, newx, newy, selectedControlPoint, shaderProgram, VAO3, mesh3, selectedControlPoint);
                }
                else if (selectedControlPoint >= 15 && selectedControlPoint < 20)
                {
                    getcageandupdate(c4, oldx, oldy, newx, newy, selectedControlPoint, shaderProgram, VAO4, mesh4, selectedControlPoint);
                }
                else if (selectedControlPoint >= 20 && selectedControlPoint < 25)
                {
                    getcageandupdate(c5, oldx, oldy, newx, newy, selectedControlPoint, shaderProgram, VAO5, mesh5, selectedControlPoint);
                }
                else if (selectedControlPoint >= 25 && selectedControlPoint < 30)
                {
                    getcageandupdate(c6, oldx, oldy, newx, newy, selectedControlPoint, shaderProgram, VAO6, mesh6, selectedControlPoint);
                }
                else if (selectedControlPoint >= 30 && selectedControlPoint < 35)
                {
                    getcageandupdate(c7, oldx, oldy, newx, newy, selectedControlPoint, shaderProgram, VAO7, mesh7, selectedControlPoint);
                }
                else
                {
                    getcageandupdate(c8, oldx, oldy, newx, newy, selectedControlPoint, shaderProgram, VAO8, mesh8, selectedControlPoint);
                }
                controlPointsUpdated = false;
            }
        }

        if (rotater)
        {

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
        }

        if (movement)
        {

            float newx, newy, oldx, oldy;
            float oldNextx = INT_MAX;
            float oldNexty = INT_MAX;
            float newNextx, newNexty;
 
            int click = 0;

            // Updating position of control points based on user input WASD

            if (ImGui::IsKeyPressed(ImGui::GetKeyIndex(ImGuiKey_RightArrow)))
            {
                selectedMovePoint++;
                if (selectedMovePoint > MovePoints.size() / 3)
                {
                    selectedMovePoint = 0;
                }
            }
            if (ImGui::IsKeyPressed(ImGui::GetKeyIndex(ImGuiKey_LeftArrow)))
            {
                selectedMovePoint--;
                if (selectedMovePoint < 0)
                {
                    selectedMovePoint = MovePoints.size() / 3 - 1;
                }
            }

            if (ImGui::IsKeyPressed(GLFW_KEY_W))
            {
                int p1, p2, p3, p4;
               
                if (selectedMovePoint == 2)
                {
                    p1 = selectedMovePoint * 15;
                    p2 = selectedMovePoint * 15 + 1;
                    p3 = selectedMovePoint * 15 + 3;
                    p4 = selectedMovePoint * 15 + 4;
                    click = 1;
                    oldy = controlPoints[p4];
                    oldx = controlPoints[p3];
                    newy = oldy + 2.5f;
                    newx = oldx;

                    oldNexty = controlPoints[p2];
                    oldNextx = controlPoints[p1];
                    newNexty = oldNexty + 2.5f;
                    newNextx = oldNextx;
                    controlPointsUpdated = true;
                }
                else if (selectedMovePoint == 1)
                {
                    p1 = selectedMovePoint * 15 + 6;
                    p2 = selectedMovePoint * 15 + 7;
                    p3 = selectedMovePoint * 15 + 9;
                    p4 = selectedMovePoint * 15 + 10;
                    click = 2;
                    oldy = controlPoints[p2];
                    oldx = controlPoints[p1];
                    newy = oldy + 2.5f;
                    newx = oldx;

                    oldNexty = controlPoints[p4];
                    oldNextx = controlPoints[p3];
                    newNexty = oldNexty + 2.5f;
                    newNextx = oldNextx;
                    controlPointsUpdated = true;
                }
                else
                {
                    continue;
                }
            }
            else if (ImGui::IsKeyPressed(GLFW_KEY_S))
            {

                int p1, p2, p3, p4;
                if (selectedMovePoint == 2)
                {
                    p1 = selectedMovePoint * 15;
                    p2 = selectedMovePoint * 15 + 1;
                    p3 = selectedMovePoint * 15 + 3;
                    p4 = selectedMovePoint * 15 + 4;
                    click = 0;
                    oldy = controlPoints[p2];
                    newy = oldy - 2.5f;
                    oldx = controlPoints[p1];
                    newx = oldx;

                    oldNexty = controlPoints[p4];
                    oldNextx = controlPoints[p3];
                    newNexty = oldNexty - 2.5f;
                    newNextx = oldNextx;
                    controlPointsUpdated = true;
                }
                else if (selectedMovePoint == 1)
                {
                    p1 = selectedMovePoint * 15 + 6;
                    p2 = selectedMovePoint * 15 + 7;
                    p3 = selectedMovePoint * 15 + 9;
                    p4 = selectedMovePoint * 15 + 10;
                    click = 3;
                    oldy = controlPoints[p4];
                    newy = oldy - 2.5f;
                    oldx = controlPoints[p3];
                    newx = oldx;

                    oldNexty = controlPoints[p2];
                    oldNextx = controlPoints[p1];
                    newNexty = oldNexty - 2.5f;
                    newNextx = oldNextx;
                    controlPointsUpdated = true;
                }
                else
                {
                    continue;
                }
            }

            else if (ImGui::IsKeyPressed(GLFW_KEY_A))
            {
                int p1, p2, p3, p4;
                if (selectedMovePoint == 4 || selectedMovePoint == 5)
                {
                   
                    p1 = selectedMovePoint * 15;
                    p2 = selectedMovePoint * 15 + 1;
                    p3 = selectedMovePoint * 15 + 9;
                    p4 = selectedMovePoint * 15 + 10;
                    oldx = controlPoints[p1];
                    oldy = controlPoints[p2];
                    newx = oldx - 2.5;
                    newy = oldy;

                    oldNextx = controlPoints[p3];
                    oldNexty = controlPoints[p4];
                    newNextx = oldNextx - 2.5;
                    newNexty = oldNexty;
                   // cout<<oldx<<" "<<oldy<<" "<<newx<<" "<<newy<<" "<<oldNextx<<" "<<oldNexty<<" "<<newNextx<<" "<<newNexty<<endl;
                    click = 0;
                    controlPointsUpdated = true;
                }

                else
                {
                    continue;
                }
            }

            else if (ImGui::IsKeyPressed(GLFW_KEY_D))
            {
                
                int p1, p2, p3, p4;
                if (selectedMovePoint == 4 || selectedMovePoint == 5)
                {
                   
                    p1 = selectedMovePoint * 15;
                    p2 = selectedMovePoint * 15 + 1;
                    p3 = selectedMovePoint * 15 + 9;
                    p4 = selectedMovePoint * 15 + 10;
                    oldx = controlPoints[p3];
                    oldy = controlPoints[p4];
                    newx = oldx + 2.5;
                    newy = oldy;

                    oldNextx = controlPoints[p1];
                    oldNexty = controlPoints[p2];
                    newNextx = oldNextx + 2.5;
                    newNexty = oldNexty;
                    click = 3;
                    controlPointsUpdated = true;
                }

                else
                {
                   
                    continue;
                }
            }

            if (controlPointsUpdated)
            {
                
                for (int i = 0; i < controlPoints.size(); i += 3)
                {
                    if (controlPoints[i] == oldNextx && controlPoints[i + 1] == oldNexty)
                    {

                        controlPoints[i] = newNextx;
                        controlPoints[i + 1] = newNexty;
                    }

                    if (controlPoints[i] == oldx && controlPoints[i + 1] == oldy)
                    {

                        controlPoints[i] = newx;
                        controlPoints[i + 1] = newy;
                    }
                }
            

                if (selectedMovePoint == 0)
                {
                    getcageandupdate2(c1, newNextx, newNexty, newx, newy, selectedMovePoint, shaderProgram, VAO, mesh1, click,false,false);
                }
                else if (selectedMovePoint == 1)
                {
                    getcageandupdate2(c2, newNextx, newNexty, newx, newy, selectedMovePoint, shaderProgram, VAO2, mesh2, click,false,true);
                }
                else if (selectedMovePoint == 2)
                {

                    getcageandupdate2(c3, newNextx, newNexty, newx, newy, selectedControlPoint, shaderProgram, VAO3, mesh3, click,false,true);
                }
                else if (selectedMovePoint == 3)
                {
                    getcageandupdate2(c4, newNextx, newNexty, newx, newy, selectedMovePoint, shaderProgram, VAO4, mesh4, click,false,false);
                }
                else if (selectedMovePoint == 4)
                {
                    getcageandupdate2(c5, newNextx, newNexty, newx, newy, selectedMovePoint, shaderProgram, VAO5, mesh5, click,true,false);
                }
                else
                {
                    getcageandupdate2(c6, newNextx, newNexty, newx, newy, selectedMovePoint, shaderProgram, VAO6, mesh6, click,true,false);
                }
                controlPointsUpdated = false;
            }
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

        glBindVertexArray(VAO_move);
        glBindBuffer(GL_ARRAY_BUFFER, VBO_move);
        glBufferData(GL_ARRAY_BUFFER, MovePoints.size() * sizeof(GLfloat), &MovePoints[0], GL_DYNAMIC_DRAW);
        glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void *)0);
        glEnableVertexAttribArray(0);

        glBindVertexArray(VAO1);
        glBindBuffer(GL_ARRAY_BUFFER, VBO1);
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

        glBindVertexArray(VAO7);
        glUniform3f(vColor_uniform, 0.3, 0.5, 0.5);
        glDrawArrays(GL_TRIANGLES, 0, mesh7size);

        glBindVertexArray(VAO8);
        glUniform3f(vColor_uniform, 0.3, 0.5, 0.5);
        glDrawArrays(GL_TRIANGLES, 0, mesh8size);

        glBindVertexArray(VAO_move);
        glUniform3f(vColor_uniform, 0.3, 0.8, 0.5);

        for (int i = 0; i < MovePoints.size() / 3; i++)
        {
            if (i == selectedMovePoint)
            {
                glUniform3f(vColor_uniform, 0.3, 0.8, 0.5);
            }
            else
            {
                glUniform3f(vColor_uniform, 0.5, 0.5, 0.5);
            }
            glDrawArrays(GL_POINTS, i, 1);
        }

        glBindVertexArray(VAO1);
        glUniform3f(vColor_uniform, 0.5, 0.5, 0.5);
        for (int i = 0; i < controlPoints.size() / 3; i += 5)
        {
            glDrawArrays(GL_LINE_STRIP, i, 5);
        }

        glBindVertexArray(VAO_controlPoints);
        for (int i = 0; i < controlPoints.size() / 3; i++)
        {
            if (i == selectedControlPoint)
            {
                glUniform3f(vColor_uniform, 0.3, 0.8, 0.5);
            }
            else
            {
                glUniform3f(vColor_uniform, 0.5, 0.5, 0.5);
            }
            glDrawArrays(GL_POINTS, i, 1);
        }

        ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());

        glfwSwapBuffers(window);
    }

    // Cleanup
    cleanup(window);

    return 0;
}

// Updating minX,minY,minZ,maxX,maxY,maxZ coordinates for setting the values for the cage of next mesh
void setter()
{
    min_x_coord = INT_MAX;
    min_y_coord = INT_MAX;
    min_z_coord = INT_MAX;

    max_x_coord = INT_MIN;
    max_y_coord = INT_MIN;
    max_z_coord = INT_MIN;
}

/*
A function to load the .obj file to render the object
The vertices and face indices are taken from the .obj file and expanded vertices are calculated by setting expanding_vertices[i] = vertices[face_index]
The vertices are sclaed by 2 to obtain a better result
maxX,maxY,maxZ,minX,minY,minZ are computed
*/

int LoadObj(char *path, unsigned int &program, unsigned int &obj_VAO, vector<GLfloat> &mesh)
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
            glm::vec4 wv = modelT * glm::vec4(vertices.x, vertices.y, vertices.z, 1.0f);
            VertexDataTemp.push_back(vertices.x * 2);
            VertexDataTemp.push_back(vertices.y * 2);
            VertexDataTemp.push_back(vertices.z * 2);
            VertexData.push_back(vertices.x * 2);
            VertexData.push_back(vertices.y * 2);
            VertexData.push_back(vertices.z * 2);

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
        mesh.push_back(v[i * 3]);
        mesh.push_back(v[i * 3 + 1]);
        mesh.push_back(v[i * 3 + 2]);
    }
    // cout << VertexDataTemp.size() << " " << FaceDataTemp.size() << endl;

    // Binding the mesh vertices to vertex buffer
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
    viewT = glm::lookAt(glm::vec3(0.0, 0.0, 40.0), glm::vec3(0.0, 0.0, 0.0), glm::vec3(0.0, 1.0, 0.0));

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

void mousemoved()
{
    // Get the control point that was edited using edit and search from below

    // get the cage whose control point was edited

    // use recompute for that cage

    // and edit the meshes so that new mesh is rendered
}

void getcageandupdate(Cage &c, float oldx, float oldy, float newx, float newy, float updatedindex, unsigned int &program, unsigned int &obj_VAO, vector<GLfloat> &mesh, int index)
{


    int val = index % 5;
  
    if (val == 0)
    {
   
        c.min_x_coord = newx;
        c.min_y_coord = newy;
    }
    else if (val == 1)
    {
        c.min_x_coord = newx;
        c.max_y_coord = newy;
    }
    else if (val == 2)
    {
        c.max_x_coord = newx;
        c.max_y_coord = newy;
    }
    else if (val == 3)
    {
        c.max_x_coord = newx;
        c.min_y_coord = newy;
    }

 
    c.createCage3d(program, obj_VAO, controlPoints);
    setter();
    c.createGrid();

    c.RecomputeVertex(mesh, program, obj_VAO, index % 5,false);
}

void getcageandupdate2(Cage &c, float newNextx, float newNexty, float newx, float newy, float updatedindex, unsigned int &program, unsigned int &obj_VAO, vector<GLfloat> &mesh, int index,bool hor,bool ver)
{


    int val = index % 5;
    if (val == 0)
    {
        c.min_x_coord = newx;
        c.min_y_coord = newy;
        if(ver){
        c.max_y_coord = newNexty;
        }
        if(hor)
        {
            
            c.max_x_coord = newNextx;
           
        }

       
    }
    else if (val == 1)
    {
        c.min_x_coord = newx;
        c.max_y_coord = newy;
        if (ver)
        {
            c.min_y_coord = newNexty;
        }
    
    }
    else if (val == 2)
    {
        c.max_x_coord = newx;
        c.max_y_coord = newy;
        if (ver)
        {
            c.min_y_coord = newNexty;
        }
    }

    else if (val == 3)
    {
        c.max_x_coord = newx;
        c.min_y_coord = newy;
        if (ver)
        {
            c.max_y_coord = newNexty;
        }

        if (hor)
        {
            c.min_x_coord = newNextx;
        }
    }


    c.createCage3d(program, obj_VAO, controlPoints);
    setter();
    c.createGrid();
    c.RecomputeVertex(mesh, program, obj_VAO, index % 5,true);
}

void pushpoints(Cage &c)
{
    MovePoints.push_back((c.min_x_coord + c.max_x_coord) / 2.0f);
    MovePoints.push_back((c.min_y_coord + c.max_y_coord) / 2.0f);
    MovePoints.push_back(c.max_z_coord+0.2);
}
