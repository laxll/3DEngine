#ifndef SHADER_H
#define SHADER_H

#include <glad/glad.h>
#include <string>
#include <fstream>
#include <iostream>
#include <cerrno>
#include <glm/gtc/matrix_transform.hpp>
#include <unordered_map>

// Function to read the contents of a file
std::string get_file_contents(const char* filename);


class Shader
{
	mutable std::unordered_map<std::string, int> m_UniformLocationCache;
	
public:
	
	GLuint ID; // Reference ID of the Shader Program

	// Constructor that builds the Shader Program from two shaders
	Shader(const char* vertexFile, const char* fragmentFile);

	// Activates the Shader Program
	void Bind() const;
	// Deletes the Shader Program
	void Unbind() const;

	void SetUniformMat4f(const std::string& name, const glm::mat4& matrix);

	//int GetUniformLocation(const std::string& name);

	//Set Uniforms
	void SetUniform1i(const std::string& name, int value);
	void SetUniform1f(const std::string& name, float v1);
	void SetUniform3fv(const std::string& name, glm::vec3 pos);


private: 
	int GetUniformLocation(const std::string& name);
};

#endif
