#include "CarcassModelLoader.hpp"

CarcassModelLoader::CarcassModelLoader(std::string filename) : _fname(filename), _file(nullptr) {}

Vertex CarcassModelLoader::readCenter() {
    std::vector<Vertex> vertices = readVertices();
    return Vertex::findCenter(vertices);
}

bool CarcassModelLoader::isOpen() {
    return _file.is_open();
}

void CarcassModelLoader::open() {
    if (_file.is_open())
        return;

    _file.open(_fname);
    if (!_file) {
        time_t now = time(nullptr);
        throw NoFileException(ctime(&now), __FILE__, __LINE__, typeid(*this).name(), __FUNCTION__);
    }
}

void CarcassModelLoader::close() {
    if (!_file.is_open())
        return _file.close();
}
