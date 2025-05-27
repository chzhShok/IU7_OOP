#pragma once

#include <fstream>
#include <memory>

#include "CarcassModelLoader.hpp"

class TxtModelLoader : public CarcassModelLoader {
public:
    TxtModelLoader(std::string filename);
    virtual ~TxtModelLoader();

    virtual std::vector<Vertex> readVertices();
    virtual std::vector<Edge> readEdges();

protected:
//    std::string _fname;
//    std::ifstream _file;

private:
    void resetFileStream();
    int readVertexCount();
    Vertex readSingleVertex();
    int readEdgeCount();
    Edge readSingleEdge();
    void validateStreamState();
};
