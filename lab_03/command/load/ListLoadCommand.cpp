#include "ListLoadCommand.hpp"

ListLoadCommand::ListLoadCommand() {
    _director_id = LISTMODELDIRECTORCREATOR_ID;
}

void ListLoadCommand::execute() {
    _director_id = LISTMODELDIRECTORCREATOR_ID;
}
