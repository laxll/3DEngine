#version 330 core 

layout(location = 0) in vec3 aPos;       // Vertex position attribute
layout(location = 1) in vec3 aNormal;    // Vertex normal attribute

// Uniforms
uniform vec3 color;  // Color passed as a uniform
uniform mat4 model;  // Model matrix
uniform mat4 view;   // View matrix
uniform mat4 projection;  // Projection matrix

uniform mat4 u_MVP;

// Outputs to the fragment shader
out vec3 FragPos;    // Fragment position in world space
out vec3 Normal;     // Normal vector in world space
out vec3 aColor;     // Output color for the fragment shader


void main()
{

	gl_Position = projection * view * model * vec4(aPos, 1.0);

    // Pass data to the fragment shader
    FragPos = vec3(model * vec4(aPos, 1.0));  // Transform vertex to world space
    Normal = mat3(transpose(inverse(model))) * aNormal;  // Transform normal to world space
    aColor = color;  

}
 