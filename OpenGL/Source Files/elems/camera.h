#pragma once


#include <glm/gtc/matrix_transform.hpp> 
#include <string>
#include <GLFW/glfw3.h>
#include "shader/shader.h"

namespace elems {

	class Camera {

	private:
		glm::vec3 m_position = glm::vec3(0.0f, 0.0f, -1.0f);  // Camera starts at (0, 0, -1)
		glm::vec3 m_targetPos = glm::vec3(0.0f, 0.0f, 0.0f);  // Camera looks at the origin

		glm::vec3 m_up = glm::vec3(0.0f, 1.0f, 0.0f);         // World up direction
		glm::vec3 m_front = glm::vec3(0.0f, 0.0f, -1.0f);     // Default forward direction
		glm::vec3 m_right = glm::vec3(1.0f, 0.0f, 0.0f);      // Default right direction
		glm::vec3 m_worldUP = glm::vec3(0.0f, 1.0f, 0.0f);    // Explicitly set world up



		float m_fov;
		float m_near;
		float m_far;

		float m_aspectRatio = 1.246f;
		

	public:
		float m_yaw;
		float m_pitch;

		float m_moveSpeed;
		float m_senstivity;

	public:

		Camera() = default;
		Camera(glm::vec3 position, glm::vec3 up, float yaw, float pitch, float fov, float near, float far);

		glm::vec3 GetCameraPosition() const;
		glm::mat4 GetProjectionMatrix();
		glm::mat4 GetViewMatrix() const;
		glm::vec3 GetCameraFront() const;
		glm::vec3 GetCameraRight() const;
		void set_aspect(GLFWwindow* window);
		float GetAspectRatio();


		void CalKeyboardMovement(glm::vec3 direction, float deltaTime);
		void CalMouseRotation(float xOffset, float yOffset, bool contrainPitch);
		
		void UpdateCameraMatrix(Shader& shader);

		void on_mouse_move(float xOffset, float yOffset, bool constrainPitch);
		void on_mouse_scroll();

	public:
		void UpdateCameraVectors();      // for camera fly cam

		void UpdateOrbit();

		void UpdateZoom(float offset);

		float GetDistance();

	};

}