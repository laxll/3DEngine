#include "pch.h"
#include "VertexIndexBuffer.h"

using namespace Render;

VertexIndexBuffer::VertexIndexBuffer() : m_vertexBuffer(0), m_indexBuffer(0)
{}

void Render::VertexIndexBuffer::print() {
    std::cout << "bruh:" << std::endl;
};

void Render::VertexIndexBuffer::create(const std::vector<glm::vec3>& vertices, const std::vector<unsigned int>& indices)
{

    //// Create and bind the vertex buffer
    glGenBuffers(1, &m_vertexBuffer);
    std::cout << "bruh:"<< m_vertexBuffer << std::endl;
    glBindBuffer(GL_ARRAY_BUFFER, m_vertexBuffer);
    glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(float), vertices.data(), GL_STATIC_DRAW);

    // Create and bind the index buffer
    glGenBuffers(1, &m_indexBuffer);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_indexBuffer);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, indices.size() * sizeof(unsigned int), indices.data(), GL_STATIC_DRAW);

    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(glm::vec3), (void*)0);
    
    glEnableVertexAttribArray(1);
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(glm::vec3), (void*)(3 * sizeof(float)));
    

    // Unbind buffers after use
    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
};


// Delete the vertex and index buffers
void  VertexIndexBuffer::destroy()
{
    if (m_vertexBuffer) {
        glDeleteBuffers(1, &m_vertexBuffer);
        m_vertexBuffer = 0;
    }
    if (m_indexBuffer) {
        glDeleteBuffers(1, &m_indexBuffer);
        m_indexBuffer = 0;
    }
};

 // Bind the vertex and index buffers
void VertexIndexBuffer::bind()
{
    glBindBuffer(GL_ARRAY_BUFFER, m_vertexBuffer);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_indexBuffer);
};

// Unbind the vertex and index buffers
void VertexIndexBuffer::unbind()
{
    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
};

// Draw the object using the index buffer
void VertexIndexBuffer::draw(int index_count)
{
    glDrawElements(GL_TRIANGLES, index_count, GL_UNSIGNED_INT, nullptr);
};
