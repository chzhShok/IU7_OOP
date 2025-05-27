#include "ClearSceneCommand.hpp"

void ClearSceneCommand::execute() {
    _sceneManager->clearScene();
}
