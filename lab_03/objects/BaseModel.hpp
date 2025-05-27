#pragma once

#include "VisibleObject.hpp"

class BaseModel : public VisibleObject {
public:
    BaseModel();
    virtual ~BaseModel() = 0;

    virtual void add(std::shared_ptr<BaseObject> obj);
    virtual void remove(const iterator &it);
    virtual iterator begin();
    virtual iterator end();
    virtual void accept(std::shared_ptr<Visitor> v);
    virtual std::shared_ptr<BaseObject> clone() const;
};
