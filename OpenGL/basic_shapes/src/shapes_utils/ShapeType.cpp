#include "ShapeType.h"


std::vector<float> getShapeVertices(ShapeType shape) {
    switch (shape) {
        
        case ShapeType::Triangle:
        return {
            -0.5f, -0.5f, 0.0f,
             0.5f, -0.5f, 0.0f,
             0.0f,  0.5f, 0.0f
        };
        
        case ShapeType::TriangleColor:
        return {
             0.5f, -0.5f, 0.0f,  1.0f, 0.0f, 0.0f,   // bottom right
            -0.5f, -0.5f, 0.0f,  0.0f, 1.0f, 0.0f,   // bottom left
             0.0f,  0.5f, 0.0f,  0.0f, 0.0f, 1.0f    // top
        };
        
        case ShapeType::UpsideDownTriangle:
        return {
             0.5f,  0.5f, 0.0f,  1.0f, 0.0f, 0.0f,   // top right
            -0.5f,  0.5f, 0.0f,  0.0f, 1.0f, 0.0f,   // top left
             0.0f, -0.5f, 0.0f,  0.0f, 0.0f, 1.0f    // bottom
        };
        
        case ShapeType::Rectangle:
            return {
                0.5f,  0.5f, 0.0f,  // top right
                0.5f, -0.5f, 0.0f,  // bottom right
               -0.5f, -0.5f, 0.0f,  // bottom left
               -0.5f,  0.5f, 0.0f   // top left
            };
        case ShapeType::RectangleColor:
            return {
                // positions          // colors      
                 0.5f,  0.5f, 0.0f,   1.0f, 0.0f, 0.0f,
                 0.5f, -0.5f, 0.0f,   0.0f, 1.0f, 0.0f,
                -0.5f, -0.5f, 0.0f,   0.0f, 0.0f, 1.0f,
                -0.5f,  0.5f, 0.0f,   1.0f, 1.0f, 0.0f,
            };

            
        case ShapeType::RectangleColorTexture:
            return {
                // positions          // colors           // texture coords
                 0.5f,  0.5f, 0.0f,   1.0f, 0.0f, 0.0f,   1.0f, 1.0f,   // top right
                 0.5f, -0.5f, 0.0f,   0.0f, 1.0f, 0.0f,   1.0f, 0.0f,   // bottom right
                -0.5f, -0.5f, 0.0f,   0.0f, 0.0f, 1.0f,   0.0f, 0.0f,   // bottom left
                -0.5f,  0.5f, 0.0f,   1.0f, 1.0f, 0.0f,   0.0f, 1.0f    // top left 
            };
    }

    return {};
}


