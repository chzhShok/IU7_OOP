#pragma once

#include <fstream>
#include <memory>

#include "BaseLoader.hpp"
#include "Edge.hpp"
#include "Vertex.hpp"

class ModelCsvLoader : public BaseLoader {
public:
    ModelCsvLoader(std::string filename);
    virtual ~ModelCsvLoader();

    void open() override;
    void close() override;
    bool isOpen() override;

    std::vector<Vertex> readVertices();
    std::vector<Edge> readEdges();

protected:
    std::string _fname;
    std::ifstream _file;
};
