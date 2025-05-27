#include "ListLoadCommand.hpp"

ListLoadCommand::ListLoadCommand() {
    _director_id = static_cast<size_t>(DirectorType::LIST);
}

void ListLoadCommand::execute() {
    _director_id = static_cast<size_t>(DirectorType::LIST);
};
