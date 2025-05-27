#pragma once

#include <vector>
#include <fstream>

#include "BaseLoader.hpp"
#include "Edge.hpp"
#include "Vertex.hpp"
#include "Exception.hpp"

class CarcassModelLoader : public BaseLoader {
public:
    CarcassModelLoader() = default;
    CarcassModelLoader(std::string filename);
    ~CarcassModelLoader() = default;

    void open();
    void close();
    bool isOpen();

    virtual std::vector<Vertex> readVertices() = 0;
    virtual std::vector<Edge> readEdges() = 0;
    virtual Vertex readCenter();

protected:
    std::string _fname;
    std::ifstream _file;
};
