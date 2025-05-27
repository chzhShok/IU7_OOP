#include "TxtModelLoader.hpp"

TxtModelLoader::TxtModelLoader(std::string filename) : CarcassModelLoader(filename) {}

TxtModelLoader::~TxtModelLoader() {
    if (isOpen())
        close();
}

std::vector<Vertex> TxtModelLoader::readVertices() {
    if (!isOpen())
        return {};

    resetFileStream();

    const int vertexCount = readVertexCount();
    std::vector<Vertex> vertices;
    vertices.reserve(vertexCount);

    for (int i = 0; i < vertexCount; ++i)
        vertices.emplace_back(readSingleVertex());

    return vertices;
}

std::vector<Edge> TxtModelLoader::readEdges() {
    if (!isOpen())
        return {};

    readVertices();

    const int edgeCount = readEdgeCount();
    std::vector<Edge> edges;
    edges.reserve(edgeCount);

    for (int i = 0; i < edgeCount; ++i)
        edges.emplace_back(readSingleEdge());

    return edges;
}

void TxtModelLoader::resetFileStream() {
    _file.clear();
    _file.seekg(0, std::ios::beg);
}

int TxtModelLoader::readVertexCount() {
    int count;
    _file >> count;
    validateStreamState();
    return count;
}

Vertex TxtModelLoader::readSingleVertex() {
    double x, y, z;
    _file >> x >> y >> z;
    validateStreamState();
    return Vertex(x, y, z);
}

int TxtModelLoader::readEdgeCount() {
    int count;
    _file >> count;
    validateStreamState();
    return count;
}

Edge TxtModelLoader::readSingleEdge() {
    int from, to;
    _file >> from >> to;
    validateStreamState();
    return Edge(from - 1, to - 1);
}

void TxtModelLoader::validateStreamState() {
    if (!_file) {
        time_t now = time(nullptr);
        throw TxtNoFileException(ctime(&now), __FILE__, __LINE__, typeid(*this).name(), __FUNCTION__);
    }
}
