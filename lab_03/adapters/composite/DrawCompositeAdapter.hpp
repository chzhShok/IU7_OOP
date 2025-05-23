#ifndef DRAWCOMPOSITEADAPTER_H
#define DRAWCOMPOSITEADAPTER_H

#include "BaseDrawer.hpp"
#include "Camera.hpp"
#include "CompositeAdapter.hpp"

class DrawCompositeAdapter : public CompositeAdapter {
public:
    void setCamera(std::shared_ptr<Camera> camera);
    void setDrawer(std::shared_ptr<BaseDrawer> drawer);

    virtual void request() override;

private:
    std::shared_ptr<Camera> _camera;
    std::shared_ptr<BaseDrawer> _drawer;
};


#endif// DRAWCOMPOSITEADAPTER_H
