#include "MatrixLoadCommand.hpp"

MatrixLoadCommand::MatrixLoadCommand() {
    _director_id = MATRIXMODELDIRECTORCREATOR_ID;
}

void MatrixLoadCommand::execute() {
    _director_id = MATRIXMODELDIRECTORCREATOR_ID;
}
