#include "CsvModelLoader.hpp"

CsvModelLoader::CsvModelLoader(std::string filename) : CarcassModelLoader(filename) {}

CsvModelLoader::~CsvModelLoader() {
    if (isOpen())
        close();
}

std::vector<Vertex> CsvModelLoader::readVertices() {
    if (!isOpen())
        return std::vector<Vertex>();

    std::vector<Vertex> vertices;
    std::string line;

    _file.clear();
    _file.seekg(0);

    int vertexCount = 0;
    if (!std::getline(_file, line)) {
        time_t now = time(nullptr);
        throw CsvReadException(ctime(&now), __FILE__, __LINE__, typeid(*this).name(), __FUNCTION__);
    }

    vertexCount = std::stoi(line);

    for (int i = 0; i < vertexCount; ++i) {
        if (!std::getline(_file, line)) {
            time_t now = time(nullptr);
            throw CsvReadException(ctime(&now), __FILE__, __LINE__, typeid(*this).name(), __FUNCTION__);
        }

        std::istringstream iss(line);
        std::string token;
        std::vector<float> coords;

        while (std::getline(iss, token, ',')) {
            try {
                coords.push_back(std::stof(token));
            } catch (...) {
                time_t now = time(nullptr);
                throw CsvReadException(ctime(&now), __FILE__, __LINE__, typeid(*this).name(), __FUNCTION__);
            }
        }

        if (coords.size() != 3) {
            time_t now = time(nullptr);
            throw CsvReadException(ctime(&now), __FILE__, __LINE__, typeid(*this).name(), __FUNCTION__);
        }

        vertices.emplace_back(coords[0], coords[1], coords[2]);
    }

    return vertices;
}

std::vector<Edge> CsvModelLoader::readEdges() {
    if (!isOpen())
        return std::vector<Edge>();

    std::vector<Edge> edges;
    std::string line;

    readVertices();

    int edgeCount = 0;
    if (!std::getline(_file, line)) {
        time_t now = time(nullptr);
        throw CsvReadException(ctime(&now), __FILE__, __LINE__, typeid(*this).name(), __FUNCTION__);
    }
    edgeCount = std::stoi(line);

    // Читаем рёбра
    for (int i = 0; i < edgeCount; ++i) {
        if (!std::getline(_file, line)) {
            time_t now = time(nullptr);
            throw CsvReadException(ctime(&now), __FILE__, __LINE__, typeid(*this).name(), __FUNCTION__);
        }

        std::istringstream iss(line);
        std::string token;
        std::vector<int> indices;

        while (std::getline(iss, token, ',')) {
            try {
                indices.push_back(std::stoi(token));
            } catch (...) {
                time_t now = time(nullptr);
                throw CsvReadException(ctime(&now), __FILE__, __LINE__, typeid(*this).name(), __FUNCTION__);
            }
        }

        if (indices.size() != 2) {
            time_t now = time(nullptr);
            throw CsvReadException(ctime(&now), __FILE__, __LINE__, typeid(*this).name(), __FUNCTION__);
        }

        edges.emplace_back(indices[0], indices[1]);
    }

    return edges;
}
