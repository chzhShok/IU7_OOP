#include "ModelCsvLoader.hpp"
#include <ctime>
#include <sstream>
#include <stdexcept>
#include <typeinfo>

ModelCsvLoader::ModelCsvLoader(std::string filename) : _fname(std::move(filename)) {}

ModelCsvLoader::~ModelCsvLoader() {
    if (isOpen())
        close();
}

void ModelCsvLoader::open() {
    if (isOpen())
        return;

    _file.open(_fname);
    if (!_file) {
        time_t now = time(nullptr);
        throw CsvNoFileException(ctime(&now), __FILE__, __LINE__, typeid(*this).name(), __FUNCTION__);
    }
}

void ModelCsvLoader::close() {
    if (_file.is_open())
        _file.close();
}

bool ModelCsvLoader::isOpen() {
    return _file.is_open();
}

std::vector<Vertex> ModelCsvLoader::readVertices() {
    if (!isOpen())
        return {};

    _file.clear();
    _file.seekg(0, std::ios::beg);

    int count = 0;
    _file >> count;
    _file.ignore(std::numeric_limits<std::streamsize>::max(), '\n');// переход к следующей строке

    std::vector<Vertex> vertices;
    vertices.reserve(count);

    std::string line;
    for (int i = 0; i < count; ++i) {
        if (!std::getline(_file, line)) {
            time_t now = time(nullptr);
            throw CsvNoFileException(ctime(&now), __FILE__, __LINE__, typeid(*this).name(), __FUNCTION__);
        }

        std::istringstream iss(line);
        std::string x_str, y_str, z_str;

        if (!std::getline(iss, x_str, ',') ||
            !std::getline(iss, y_str, ',') ||
            !std::getline(iss, z_str, ',')) {
            time_t now = time(nullptr);
            throw CsvNoFileException(ctime(&now), __FILE__, __LINE__, typeid(*this).name(), __FUNCTION__);
        }

        double x = std::stod(x_str);
        double y = std::stod(y_str);
        double z = std::stod(z_str);

        vertices.emplace_back(x, y, z);
    }

    return vertices;
}

std::vector<Edge> ModelCsvLoader::readEdges() {
    if (!isOpen())
        return {};

    // Переоткрытие файла и пропуск до начала рёбер
    _file.clear();
    _file.seekg(0, std::ios::beg);

    int vertexCount = 0;
    _file >> vertexCount;
    _file.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    std::string tmp;
    for (int i = 0; i < vertexCount; ++i)
        std::getline(_file, tmp);// пропускаем строки с вершинами

    int edgeCount = 0;
    _file >> edgeCount;
    _file.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    std::vector<Edge> edges;
    edges.reserve(edgeCount);

    std::string line;
    for (int i = 0; i < edgeCount; ++i) {
        if (!std::getline(_file, line)) {
            time_t now = time(nullptr);
            throw CsvNoFileException(ctime(&now), __FILE__, __LINE__, typeid(*this).name(), __FUNCTION__);
        }

        std::istringstream iss(line);
        std::string a_str, b_str;

        if (!std::getline(iss, a_str, ',') ||
            !std::getline(iss, b_str, ',')) {
            time_t now = time(nullptr);
            throw CsvNoFileException(ctime(&now), __FILE__, __LINE__, typeid(*this).name(), __FUNCTION__);
        }

        int a = std::stoi(a_str);
        int b = std::stoi(b_str);

        edges.emplace_back(a - 1, b - 1);// переиндексация: с 1 на 0
    }

    return edges;
}
