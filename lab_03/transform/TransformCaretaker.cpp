#include "TransformCaretaker.hpp"

void TransformCaretaker::save(std::shared_ptr<TransformMemento> memento) {
    __history.push(memento);
}

std::shared_ptr<TransformMemento> TransformCaretaker::undo() {
    if (__history.empty())
        return nullptr;

    auto memento = __history.top();
    __history.pop();
    return memento;
}

bool TransformCaretaker::canUndo() const {
    return !__history.empty();
}
