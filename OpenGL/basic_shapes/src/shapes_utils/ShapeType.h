#ifndef SHAPE_TYPE_H
#define SHAPE_TYPE_H

#include <vector>

enum class ShapeType {
    Triangle,
    TriangleColor,
    UpsideDownTriangle,
    Rectangle,
    RectangleColor,
    RectangleColorTexture
};

/**
 * @brief Return a vector with positions and possibly colors
 *        based on the shapeType. 
 */
std::vector<float> getShapeVertices(ShapeType shape);

#endif
