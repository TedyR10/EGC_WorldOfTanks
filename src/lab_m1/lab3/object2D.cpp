#include "object2D.h"

#include <vector>

#include "core/engine.h"
#include "utils/gl_utils.h"


Mesh* object2D::CreateSquare(
    const std::string &name,
    glm::vec3 leftBottomCorner,
    float length,
    glm::vec3 color,
    bool fill)
{
    glm::vec3 corner = leftBottomCorner;

    std::vector<VertexFormat> vertices =
    {
        VertexFormat(corner, color),
        VertexFormat(corner + glm::vec3(length, 0, 0), color),
        VertexFormat(corner + glm::vec3(length, length, 0), color),
        VertexFormat(corner + glm::vec3(0, length, 0), color)
    };

    Mesh* square = new Mesh(name);
    std::vector<unsigned int> indices = { 0, 1, 2, 3 };

    if (!fill) {
        square->SetDrawMode(GL_LINE_LOOP);
    } else {
        // Draw 2 triangles. Add the remaining 2 indices
        indices.push_back(0);
        indices.push_back(2);
    }

    square->InitFromData(vertices, indices);
    return square;
}


Mesh* object2D::CreateStar(
    const std::string& name,
    glm::vec3 color,
    bool fill)
{

    std::vector<VertexFormat> vertices
    {
        VertexFormat(glm::vec3(0, 1.5, 0), color),
        VertexFormat(glm::vec3(1, 1, 0), color),
        VertexFormat(glm::vec3(1.2, 1.5, 0), color),
        VertexFormat(glm::vec3(0.6, 0, 0), color),
        VertexFormat(glm::vec3(1.6, 2.5, 0), color),
        VertexFormat(glm::vec3(2.2, 0, 0), color),
        VertexFormat(glm::vec3(2, 1, 0), color),
        VertexFormat(glm::vec3(3, 1.5, 0), color),
        VertexFormat(glm::vec3(2, 1.5, 0), color),
        VertexFormat(glm::vec3(1.6, 2.5, 0), color),


    };
    std::vector<unsigned int> indices =
    {
        2, 0, 1,
        1, 3, 0,
    };

    //meshes["square"] = new Mesh("square");
    //meshes["square"]->InitFromData(vertices3, indices3);

    Mesh* star = new Mesh(name);

    //if (!fill) {
    //    star->SetDrawMode(GL_LINE_LOOP);
    //}
    //else {
    //    // Draw 2 triangles. Add the remaining 2 indices
    //    indices.push_back(0);
    //    indices.push_back(2);
    //}

    star->InitFromData(vertices, indices);
    return star;
}
