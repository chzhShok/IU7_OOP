#include "DrawManager.h"
#include "SwapEdgesVisibility.hpp"

void DrawManager::setEdgesVisibilityForVisitor(DrawVisitor &visitor) {
    visitor.setEdgesVisibilityEnabled(SwapEdgesVisibility::getFaceCullingEnabled());
}
