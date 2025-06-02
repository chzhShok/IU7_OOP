#pragma once

#include <memory>
#include <fstream>
#include "nlohmann/json.hpp"

#include "CarcassModelLoader.hpp"
#include "CenterStrategy.hpp"
#include "Exception.hpp"

class JsonModelLoader : public CarcassModelLoader {
public:
    JsonModelLoader(const char *filename);
    virtual ~JsonModelLoader();

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
