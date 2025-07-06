#pragma once

#include <fstream>
#include <memory>

#include "CarcassModelLoader.hpp"
#include "CenterStrategy.hpp"
#include "Exception.hpp"

class TxtModelLoader : public CarcassModelLoader {
public:
    TxtModelLoader(const char *filename);
    virtual ~TxtModelLoader();

    virtual void open();
    virtual void close();
    virtual bool isOpen();

    virtual std::vector<Vertex> readVertices();
    virtual std::vector<Edge> readEdges();
    virtual Vertex readCenter();

protected:
    const char *_fname;
    std::ifstream _file;
    std::shared_ptr<BaseCenterStrategy> _centerStrategy;
};
