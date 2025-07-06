#include "JsonModelLoader.hpp"

using json = nlohmann::json;

JsonModelLoader::JsonModelLoader(const char *filename) : _fname(filename), _centerStrategy(std::make_shared<CenterStrategy>()) {
}

JsonModelLoader::~JsonModelLoader() {
    close();
}

void JsonModelLoader::open() {
    if (_file.is_open())
        close();

    _file.open(_fname);
    if (!_file.is_open()) {
        time_t now = time(nullptr);
        throw JsonNoFileException(ctime(&now), __FILE__, __LINE__, typeid(*this).name(), __FUNCTION__);
    }
}

void JsonModelLoader::close() {
    if (_file.is_open())
        _file.close();
}

bool JsonModelLoader::isOpen() {
    return _file.is_open();
}

std::vector<Vertex> JsonModelLoader::readVertices() {
    if (!isOpen())
        return std::vector<Vertex>();

    _file.seekg(0);
    json data;
    _file >> data;

    std::vector<Vertex> vertices;
    for (const auto &vertexData: data["vertices"]) {
        double x = vertexData["x"];
        double y = vertexData["y"];
        double z = vertexData["z"];
        vertices.emplace_back(x, y, z);
    }

    return vertices;
}

std::vector<Edge> JsonModelLoader::readEdges() {
    if (!isOpen())
        return std::vector<Edge>();

    _file.seekg(0);
    json data;
    _file >> data;

    std::vector<Edge> edges;
    for (const auto &edgeData: data["edges"]) {
        size_t first = edgeData["first"];
        size_t second = edgeData["second"];
        edges.emplace_back(first, second);
    }

    return edges;
}

Vertex JsonModelLoader::readCenter() {
    std::vector<Vertex> vertices = readVertices();
    return _centerStrategy->CenterAlgorithm(vertices);
}
