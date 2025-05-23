#include "ModelTxtLoader.hpp"
#include <sstream>
#include <stdexcept>

ModelTxtLoader::ModelTxtLoader(std::string filename) : _fname(std::move(filename)) {}

ModelTxtLoader::~ModelTxtLoader() {
    if (isOpen())
        close();
}

void ModelTxtLoader::open() {
    if (isOpen())
        return;

    _file.open(_fname);
    if (!_file) {
        time_t now = time(nullptr);
        throw TxtNoFileException(ctime(&now), __FILE__, __LINE__, typeid(*this).name(), __FUNCTION__);
    }
}

void ModelTxtLoader::close() {
    if (_file.is_open())
        _file.close();
}

bool ModelTxtLoader::isOpen() {
    return _file.is_open();
}

std::vector<Vertex> ModelTxtLoader::readVertices() {
    if (!isOpen())
        return std::vector<Vertex>();

    std::vector<Vertex> vertices;
    _file.clear();
    _file.seekg(0, std::ios::beg);

    int size = 0;
    _file >> size;
    vertices.resize(size);
    double x, y, z;
    for (int i = 0; i < size; i++) {
        _file >> x >> y >> z;
        if (!_file) {
            time_t now = time(nullptr);
            throw TxtNoFileException(ctime(&now), __FILE__, __LINE__, typeid(*this).name(), __FUNCTION__);
        }

        vertices[i].setX(x);
        vertices[i].setY(y);
        vertices[i].setZ(z);
    }

    return vertices;
}

std::vector<Edge> ModelTxtLoader::readEdges() {
    if (!isOpen())
        return std::vector<Edge>();

    std::vector<Edge> edges;
    readVertices();

    int size = 0;
    _file >> size;
    edges.resize(size);
    for (int i = 0; i < size; i++) {
        int a, b;
        _file >> a >> b;
        if (!_file) {
            time_t now = time(nullptr);
            throw TxtNoFileException(ctime(&now), __FILE__, __LINE__, typeid(*this).name(), __FUNCTION__);
        }

        edges[i].setFirst(a - 1);
        edges[i].setSecond(b - 1);
    }

    return edges;
}
