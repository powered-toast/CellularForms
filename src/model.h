#pragma once

#include <glm/glm.hpp>
#include <vector>

#include "triangle.h"

// list of cells
// list of neighbors for each cell
// spatial hash index

class Model {
public:
    Model(const std::vector<Triangle> &triangles);

    const std::vector<glm::vec3> &Cells() const {
        return m_Cells;
    }

    const std::vector<std::vector<int>> &Links() const {
        return m_Links;
    }

    void Update();

private:
    float m_LinkRestLength;
    float m_SpringFactor;
    float m_PlanarFactor;
    float m_BulgeFactor;
    float m_RadiusOfInfluence;
    float m_RepulsionStrength;

    // position of each cell
    std::vector<glm::vec3> m_Cells;

    // list of indexes of linked cells
    std::vector<std::vector<int>> m_Links;
};