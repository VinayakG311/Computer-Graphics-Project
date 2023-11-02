#include "utils/utils.hpp"
#include "drawable.hpp"
#include "camera/camera.hpp"
#include "mesh/mesh.hpp"

#define GLM_FORCE_RADIANS
#define GLM_ENABLE_EXPERIMENTAL

#include <glm/gtc/type_ptr.hpp>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtx/string_cast.hpp>
#include <iostream>
using namespace std;
Mesh *testCubeMesh()
{
	GLfloat verts[] = {0, 0, 0,
					   1, 0, 0,
					   1, 1, 0,
					   0, 1, 0,
					   0, 0, 1,
					   1, 0, 1,
					   1, 1, 1,
					   0, 1, 1};

	GLuint indices[] = {0, 1, 2,
						0, 2, 3,
						4, 5, 6,
						4, 6, 7,
						0, 4, 7,
						0, 7, 3,
						1, 5, 6,
						1, 6, 2,
						0, 1, 5,
						0, 5, 4,
						3, 2, 6,
						3, 6, 7};

	return new Mesh(verts, indices, 8, 12);
}
Mesh *LoadObj()
{
	FILE *ObjFile = fopen("BEAR2.obj", "r");
	if (ObjFile == NULL)
	{
		cout << "Error Opening Obj File";
	}

	GLfloat VertexDataTemp[1401 * 3];
	GLuint FaceDataTemp[2723 * 3];
	int i = 0, j = 0;
	while (true)
	{
		char data[1024];
		int recv = fscanf(ObjFile, "%s\n", data);
		//	cout << data << endl;
		if (recv < 0)
		{
			break;
		}

		glm::vec3 vertices;

		if (!strcmp(data, "v"))
		{
			fscanf(ObjFile, "%f %f %f\n", &vertices.x, &vertices.y, &vertices.z);
			VertexDataTemp[i++] = (vertices.x);
			VertexDataTemp[i++] = (vertices.y);
			VertexDataTemp[i++] = (vertices.z);
		}
		if (!strcmp(data, "f"))
		{
			float f1, f2, f3, f4, f5, f6;
			fscanf(ObjFile, "%f/%f %f/%f %f/%f\n", &f1, &f2, &f3, &f4, &f5, &f6);

			FaceDataTemp[j++] = (f1 - 1);
			FaceDataTemp[j++] = (f3 - 1);
			FaceDataTemp[j++] = (f5 - 1);
		}
	}
	cout << i << " " << j << endl;
	// float v[j * 3];

	// for (int k = 0; k < j; k++)
	// {
	// 	v[k * 3] = VertexDataTemp[FaceDataTemp[k] * 3];
	// 	v[k * 3 + 1] = VertexDataTemp[FaceDataTemp[k] * 3 + 1];
	// 	v[k * 3 + 2] = VertexDataTemp[FaceDataTemp[k] * 3 + 2];
	// }
	return new Mesh(VertexDataTemp, FaceDataTemp, i / 3, j / 3);
}
int main(int, char **)
{
	// Setup window
	GLFWwindow *window = setupWindow(SCREEN_W, SCREEN_H, "Parametric Representations of Surfaces");
	ImGuiIO &io = ImGui::GetIO(); // Create IO

	double last_time = 0;
	double delta_time = 0;

	unsigned int shader_program = createProgram("shaders/vshader.vs", "shaders/fshader.fs");

	Camera *cam = new Camera(glm::vec3(-5.0f, 3.0f, 3.5f), glm::vec3(0.0f, 0.0f, 0.0f), glm::vec3(0.0f, 1.0f, 0.0f),
							 45.0f, 0.1f, 10000.0f, window);

	cam->setProjectionTransformation(shader_program);
	cam->setViewTransformation(shader_program);

	// LoadObj();
	Mesh *mesh = LoadObj();
	// Render a sphere using parametric representation.
	//  ParametricMesh *mesh = new ParametricMesh(100);

	glEnable(GL_DEPTH_TEST);
	glEnable(GL_BLEND);
	while (!glfwWindowShouldClose(window))
	{
		// Start the Dear ImGui frame
		ImGui_ImplOpenGL3_NewFrame();
		ImGui_ImplGlfw_NewFrame();
		ImGui::NewFrame();

		double curr_time = static_cast<double>(glfwGetTime());
		delta_time = curr_time - last_time;
		last_time = curr_time;

		if (!io.WantCaptureMouse)
		{
			cam->process_input(window, delta_time);
			cam->setViewTransformation(shader_program);
		}

		// Rendering
		ImGui::Render();
		int display_w, display_h;
		glfwGetFramebufferSize(window, &display_w, &display_h);
		glViewport(0, 0, display_w, display_h);
		glClearColor(WHITE.x, WHITE.y, WHITE.z, WHITE.w);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		mesh->draw(shader_program);

		ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
		glfwSwapBuffers(window);
		glfwPollEvents();
	}

	// Cleanup
	cleanup(window);

	return 0;
}
