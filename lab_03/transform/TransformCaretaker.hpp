#pragma once

#include <memory>
#include <stack>

#include "TransformMemento.hpp"

class TransformCaretaker {
public:
    void save(std::shared_ptr<TransformMemento> memento);
    std::shared_ptr<TransformMemento> undo();
    bool canUndo() const;

private:
    std::stack<std::shared_ptr<TransformMemento>> __history;
};
