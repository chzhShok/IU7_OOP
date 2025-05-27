#include "MatrixLoadCommand.hpp"

MatrixLoadCommand::MatrixLoadCommand() {
    _director_id = static_cast<size_t>(DirectorType::MATRIX);
}

void MatrixLoadCommand::execute() {
    _director_id = static_cast<size_t>(DirectorType::MATRIX);
};
