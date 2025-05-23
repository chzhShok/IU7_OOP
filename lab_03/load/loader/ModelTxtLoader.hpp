#pragma once

#include <fstream>
#include <memory>

#include "BaseLoader.hpp"
#include "Edge.hpp"
#include "Vertex.hpp"

class ModelTxtLoader : public BaseLoader {
public:
    ModelTxtLoader(std::string filename);
    virtual ~ModelTxtLoader();

    void open() override;
    void close() override;
    bool isOpen() override;

    std::vector<Vertex> readVertices();
    std::vector<Edge> readEdges();

protected:
    std::string _fname;
    std::ifstream _file;
};
