#ifndef ACTIONS_HPP
#define ACTIONS_HPP

#include "logic/figure/figure.hpp"

typedef struct Action Action;

enum ActionType {
    UPLOAD,
    DRAW,
    MOVE,
    ROTATE,
    SCALE,
    QUIT,
};

struct Action {
    ActionType type;

    union {
        FilesPath path;
        View view;
        Move move;
        Rotate rotate;
        Scale scale;
    };
};

ErrorFigure manage_action(const Action &action);

#endif//ACTIONS_HPP
