#pragma once

#include <memory>
#include <fstream>
#include <sstream>

#include "CarcassModelLoader.hpp"

class CsvModelLoader : public CarcassModelLoader {
public:
    CsvModelLoader(std::string filename);
    virtual ~CsvModelLoader();

    virtual std::vector<Vertex> readVertices();
    virtual std::vector<Edge> readEdges();

protected:
//    std::string _fname;
//    std::ifstream _file;
};
