#include "TxtModelLoader.hpp"

TxtModelLoader::TxtModelLoader(const char *filename) : _fname(filename), _centerStrategy(std::make_shared<CenterStrategy>()) {
    std::string fn(filename);
    if (fn.size() > 4 &&
        (fn.substr(fn.size() - 4) != ".txt")) {
        time_t now = time(nullptr);
        throw TxtReadException(ctime(&now), __FILE__, __LINE__, typeid(*this).name(), __FUNCTION__);
    }
}

TxtModelLoader::~TxtModelLoader() {
    if (isOpen())
        close();
}

bool TxtModelLoader::isOpen() {
    return _file.is_open();
}

void TxtModelLoader::open() {
    if (_file.is_open())
        return;

    _file.open(_fname);
    if (!_file) {
        time_t now = time(nullptr);
        throw TxtNoFileException(ctime(&now), __FILE__, __LINE__, typeid(*this).name(), __FUNCTION__);
    }
}

void TxtModelLoader::close() {
    if (!_file.is_open())
        return _file.close();
}

std::vector<Vertex> TxtModelLoader::readVertices() {
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
        if (!(_file >> x >> y >> z)) {
            time_t now = time(nullptr);
            throw TxtNoFileException(ctime(&now), __FILE__, __LINE__, typeid(*this).name(), __FUNCTION__);
        }

        vertices[i].setX(x);
        vertices[i].setY(y);
        vertices[i].setZ(z);
    }

    return vertices;
}

std::vector<Edge> TxtModelLoader::readEdges() {
    if (!isOpen())
        return std::vector<Edge>();

    std::vector<Vertex> vertices = readVertices();

    int size = 0;
    _file >> size;
    std::vector<Edge> edges(size);

    int a, b;
    for (int i = 0; i < size; i++) {
        if (!(_file >> a >> b)) {
            time_t now = time(nullptr);
            throw TxtNoFileException(ctime(&now), __FILE__, __LINE__, typeid(*this).name(), __FUNCTION__);
        }

        edges[i].setFirst(a - 1);
        edges[i].setSecond(b - 1);
    }

    return edges;
}

Vertex TxtModelLoader::readCenter() {
    std::vector<Vertex> vertices = readVertices();
    return _centerStrategy->CenterAlgorithm(vertices);
}
