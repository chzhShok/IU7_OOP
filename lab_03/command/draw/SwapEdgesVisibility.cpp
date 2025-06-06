#include "SwapEdgesVisibility.hpp"

bool SwapEdgesVisibility::_visibleEdgesEnabled = true;

void SwapEdgesVisibility::execute() {
    _visibleEdgesEnabled = !_visibleEdgesEnabled;
}
