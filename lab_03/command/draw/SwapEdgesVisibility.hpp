#pragma once

#include "BaseDrawCommand.hpp"

class SwapEdgesVisibility : public BaseDrawCommand {
public:
    SwapEdgesVisibility() = default;
    virtual void execute() override;
    static bool getFaceCullingEnabled() { return _visibleEdgesEnabled; }

private:
    static bool _visibleEdgesEnabled;
};
