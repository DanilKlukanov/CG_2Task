#pragma once
//c++
#include <iostream>
//glew
#include <GL/glew.h>
//sfml
#include <SFML/Window.hpp>
//my_math
#include "math/math4.h"
#include "math/vec3.h"
//shaders
#include "sup/shaderLoader.h"
#include "sup/stb_image.h"
//class_camera
#include "Class_camera.h"
#include "shader.h"
//class_texture
#include "Texture.h"
//shader
#include "Shader.h"
//vao vbo
#include "Vertex_array.h"
#include "Vertex_buffer.h"

int height = 800;
int width = 600;

vec3 ambient(0.2f, 0.2f, 0.2f);
vec3 diffuse(0.5f, 0.5f, 0.5f);
vec3 specular(1.0f, 1.0f, 1.0f);

float constant = 1.0f;
float linear = 0.09f;
float quadratic = 0.032f;
float shininess = 32.0f;

int main() {
	sf::ContextSettings settings;
	settings.depthBits = 24;
	settings.stencilBits = 8;
	settings.majorVersion = 4;
	settings.minorVersion = 3;
	settings.attributeFlags = sf::ContextSettings::Core;

	sf::Window window(sf::VideoMode(height, width, 24), "TaskTwo",
		sf::Style::Titlebar | sf::Style::Close, settings);

	glewExperimental = GL_TRUE;

	if (GLEW_OK != glewInit()) {
		std::cout << "Error:: glew not init =(" << std::endl;
		return -1;
	}

	glEnable(GL_DEPTH_TEST);

	sf::Mouse::setPosition(sf::Vector2i(height / 2, width / 2), window);
	Class_camera camera;

	///directional directional directional directional
	//Shader cube("shader_directional/directional.vs", "shader_directional/directional.fs");
	///directional directional directional directional

	///point point point point
	//Shader cube("shader_point/point.vs", "shader_point/point.fs");
	///point point point point

	///spot spot spot spot
	//Shader cube("shader_spot/spot.vs", "shader_spot/spot.fs");
	///spot spot spot spot

	///all all all all
	Shader cube("shaders/texture.vs", "shaders/texture.fs");
	///all all all all
	Shader light("shaders/point.vs", "shaders/point.fs");

	float vertices[] = {
		-0.5f, -0.5f, -0.5f,  0.0f,  0.0f, -1.0f,  0.0f, 0.0f,
		0.5f, -0.5f, -0.5f,  0.0f,  0.0f, -1.0f,  1.0f, 0.0f,
		0.5f,  0.5f, -0.5f,  0.0f,  0.0f, -1.0f,  1.0f, 1.0f,
		0.5f,  0.5f, -0.5f,  0.0f,  0.0f, -1.0f,  1.0f, 1.0f,
		-0.5f,  0.5f, -0.5f,  0.0f,  0.0f, -1.0f,  0.0f, 1.0f,
		-0.5f, -0.5f, -0.5f,  0.0f,  0.0f, -1.0f,  0.0f, 0.0f,

		-0.5f, -0.5f,  0.5f,  0.0f,  0.0f, 1.0f,   0.0f, 0.0f,
		0.5f, -0.5f,  0.5f,  0.0f,  0.0f, 1.0f,   1.0f, 0.0f,
		0.5f,  0.5f,  0.5f,  0.0f,  0.0f, 1.0f,   1.0f, 1.0f,
		0.5f,  0.5f,  0.5f,  0.0f,  0.0f, 1.0f,   1.0f, 1.0f,
		-0.5f,  0.5f,  0.5f,  0.0f,  0.0f, 1.0f,   0.0f, 1.0f,
		-0.5f, -0.5f,  0.5f,  0.0f,  0.0f, 1.0f,   0.0f, 0.0f,

		-0.5f,  0.5f,  0.5f, -1.0f,  0.0f,  0.0f,  1.0f, 0.0f,
		-0.5f,  0.5f, -0.5f, -1.0f,  0.0f,  0.0f,  1.0f, 1.0f,
		-0.5f, -0.5f, -0.5f, -1.0f,  0.0f,  0.0f,  0.0f, 1.0f,
		-0.5f, -0.5f, -0.5f, -1.0f,  0.0f,  0.0f,  0.0f, 1.0f,
		-0.5f, -0.5f,  0.5f, -1.0f,  0.0f,  0.0f,  0.0f, 0.0f,
		-0.5f,  0.5f,  0.5f, -1.0f,  0.0f,  0.0f,  1.0f, 0.0f,

		0.5f,  0.5f,  0.5f,  1.0f,  0.0f,  0.0f,  1.0f, 0.0f,
		0.5f,  0.5f, -0.5f,  1.0f,  0.0f,  0.0f,  1.0f, 1.0f,
		0.5f, -0.5f, -0.5f,  1.0f,  0.0f,  0.0f,  0.0f, 1.0f,
		0.5f, -0.5f, -0.5f,  1.0f,  0.0f,  0.0f,  0.0f, 1.0f,
		0.5f, -0.5f,  0.5f,  1.0f,  0.0f,  0.0f,  0.0f, 0.0f,
		0.5f,  0.5f,  0.5f,  1.0f,  0.0f,  0.0f,  1.0f, 0.0f,

		-0.5f, -0.5f, -0.5f,  0.0f, -1.0f,  0.0f,  0.0f, 1.0f,
		0.5f, -0.5f, -0.5f,  0.0f, -1.0f,  0.0f,  1.0f, 1.0f,
		0.5f, -0.5f,  0.5f,  0.0f, -1.0f,  0.0f,  1.0f, 0.0f,
		0.5f, -0.5f,  0.5f,  0.0f, -1.0f,  0.0f,  1.0f, 0.0f,
		-0.5f, -0.5f,  0.5f,  0.0f, -1.0f,  0.0f,  0.0f, 0.0f,
		-0.5f, -0.5f, -0.5f,  0.0f, -1.0f,  0.0f,  0.0f, 1.0f,

		-0.5f,  0.5f, -0.5f,  0.0f,  1.0f,  0.0f,  0.0f, 1.0f,
		0.5f,  0.5f, -0.5f,  0.0f,  1.0f,  0.0f,  1.0f, 1.0f,
		0.5f,  0.5f,  0.5f,  0.0f,  1.0f,  0.0f,  1.0f, 0.0f,
		0.5f,  0.5f,  0.5f,  0.0f,  1.0f,  0.0f,  1.0f, 0.0f,
		-0.5f,  0.5f,  0.5f,  0.0f,  1.0f,  0.0f,  0.0f, 0.0f,
		-0.5f,  0.5f, -0.5f,  0.0f,  1.0f,  0.0f,  0.0f, 1.0f
	};

	Vertex_array cubeVAO;
	Vertex_buffer VBO(vertices, sizeof(vertices) / sizeof(float));
	cubeVAO.AttribPointer(0, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)0);
	cubeVAO.AttribPointer(1, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(3 * sizeof(float)));
	cubeVAO.AttribPointer(2, 2, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(6 * sizeof(float)));
	Vertex_array lightCubeVAO;
	VBO.Bind();
	cubeVAO.AttribPointer(0, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)0);

	vec3 pos_light_cube(1.2f, 0.0f, 2.0f);

	vec3 pos_light_cube_two(1.2f, 0.0f, -4.0f);

	vec3 pos_cube[] = {
		vec3(1.5f,  2.0f, -2.5f),
		vec3(1.5f,  0.2f, -1.5f),
		vec3(-1.3f,  1.0f, -1.5f),
		vec3(1.3f, -2.0f, -2.5f)
	};

	Texture cube_diff("textures/texture_box.png");
	Texture cube_spec("textures/texture_box_spec.png");

	cube.Use();
	cube.SetInt("material.diffuse", 0);
	cube.SetInt("material.specular", 1);

	bool isGo = true;
	while (isGo) {
		sf::Event windowEvent;
		while (window.pollEvent(windowEvent)) {
			switch (windowEvent.type) {
			case sf::Event::Closed:
				isGo = false;
				break;
			case sf::Event::KeyPressed:
				camera.KeyboardInput();
				break;
			case sf::Event::MouseMoved:
				camera.MouseInput(window);
				break;
			default:
				break;
			}
		}

		glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		///directional directional directional directional
		//cube.Use();
		//cube.SetVec3("light.direction", vec3(-0.2f, -1.0f, -0.3f));
		//cube.SetVec3("viewPos", camera.GetPos());
		//cube.SetVec3("light.ambient", ambient);
		//cube.SetVec3("light.diffuse", diffuse);
		//cube.SetVec3("light.specular", specular);
		//cube.SetFloat("material.shininess", shininess);
		///directional directional directional directional

		///point point point point
		//cube.Use();
		//cube.SetVec3("light.position", pos_light_cube);
		//cube.SetVec3("viewPos", camera.GetPos());
		//cube.SetVec3("light.ambient", ambient);
		//cube.SetVec3("light.diffuse", diffuse);
		//cube.SetVec3("light.specular", specular);
		//cube.SetFloat("light.constant", constant);
		//cube.SetFloat("light.linear", linear);
		//cube.SetFloat("light.quadratic", quadratic);
		//cube.SetFloat("material.shininess", shininess);
		///point point point point


		///spot spot spot spot
		//cube.Use();
		//cube.SetVec3("light.position", camera.GetPos());
		//cube.SetVec3("light.direction", camera.GetFront());
		//cube.SetFloat("light.cutOff", glm::cos(glm::radians(12.5f)));
		//cube.SetFloat("light.outerCutOff", glm::cos(glm::radians(15.0f)));
		//cube.SetVec3("viewPos", camera.GetPos());
		//cube.SetVec3("light.ambient", vec3(0.1f, 0.1f, 0.1f));
		//cube.SetVec3("light.diffuse", vec3(0.8f, 0.8f, 0.8f));
		//cube.SetVec3("light.specular", specular);
		//cube.SetFloat("light.constant", constant);
		//cube.SetFloat("light.linear", linear);
		//cube.SetFloat("light.quadratic", quadratic);
		//cube.SetFloat("material.shininess", shininess);
		///spot spot spot spot

		///all all all all
		cube.Use();
		cube.SetVec3("viewPos", camera.GetPos());
		cube.SetFloat("material.shininess", shininess);

		cube.SetVec3("dirLight.direction", vec3(-0.2f, -1.0f, -0.3f));
		cube.SetVec3("dirLight.ambient", vec3(0.05f, 0.05f, 0.05f));
		cube.SetVec3("dirLight.diffuse", vec3(0.4f, 0.4f, 0.4f));
		cube.SetVec3("dirLight.specular", vec3(0.5f, 0.5f, 0.5f));

		cube.SetVec3("pointLights[0].position", pos_light_cube);
		cube.SetVec3("pointLights[0].ambient", vec3(0.05f, 0.05f, 0.05f));
		cube.SetVec3("pointLights[0].diffuse", vec3(0.8f, 0.8f, 0.8f));
		cube.SetVec3("pointLights[0].specular", specular);
		cube.SetFloat("pointLights[0].constant", constant);
		cube.SetFloat("pointLights[0].linear", linear);
		cube.SetFloat("pointLights[0].quadratic", quadratic);

		cube.SetVec3("pointLights[1].position", pos_light_cube_two);
		cube.SetVec3("pointLights[1].ambient", vec3(0.05f, 0.05f, 0.05f));
		cube.SetVec3("pointLights[1].diffuse", vec3(0.8f, 0.8f, 0.8f));
		cube.SetVec3("pointLights[1].specular", specular);
		cube.SetFloat("pointLights[1].constant", constant);
		cube.SetFloat("pointLights[1].linear", linear);
		cube.SetFloat("pointLights[1].quadratic", quadratic);

		cube.SetVec3("spotLight.position", camera.GetPos());
		cube.SetVec3("spotLight.direction", camera.GetFront());
		cube.SetVec3("spotLight.ambient", vec3(0.0f, 0.0f, 0.0f));
		cube.SetVec3("spotLight.diffuse", vec3(1.0f, 1.0f, 1.0f));
		cube.SetVec3("spotLight.specular", specular);
		cube.SetFloat("spotLight.constant", constant);
		cube.SetFloat("spotLight.linear", linear);
		cube.SetFloat("spotLight.quadratic", quadratic);
		cube.SetFloat("spotLight.cutOff", glm::cos(glm::radians(12.5f)));
		cube.SetFloat("spotLight.outerCutOff", glm::cos(glm::radians(15.0f)));
		///all all all all

		math4 projection = camera.GetProjectionMatrix();
		math4 view = camera.GetViewMatrix();

		cube.SetMat4("projection", projection);
		cube.SetMat4("view", view);

		//cвязывание диффузной карты
		cube_diff.Bind(0);
		//cвязывание карты отраженного цвета
		cube_diff.Bind(1);

		cubeVAO.Bind();
		for (int i = 0; i < 4; i++)
		{
			math4 model(1.0f);
			model = model.Translate(pos_cube[i]);
			float angle = 20.0f * i;
			vec3 rotate(1.0f, 0.3f, 0.5f);
			model = model.Rotate(glm::radians(angle), rotate);
			cube.SetMat4("model", model);
			glDrawArrays(GL_TRIANGLES, 0, 36);
		}


		light.Use();
		light.SetMat4("projection", projection);
		light.SetMat4("view", view);

		math4 model(1.0f);
		model = model.Translate(pos_light_cube);
		model = model.Scale(vec3(0.3f));
		light.SetMat4("model", model);
		glDrawArrays(GL_TRIANGLES, 0, 36);


		math4 model2(1.0f);
		model2 = model2.Translate(pos_light_cube_two);
		model2 = model2.Scale(vec3(0.3f));
		light.SetMat4("model", model2);
		glDrawArrays(GL_TRIANGLES, 0, 36);

		lightCubeVAO.Bind();


		window.display();
	}

	VBO.Delete();
	cubeVAO.Delete();
	lightCubeVAO.Delete();

	window.close();
	return 0;
}