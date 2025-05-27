#include "BaseModel.hpp"

BaseModel::BaseModel() {}

BaseModel::~BaseModel() {}

void BaseModel::add(std::shared_ptr<BaseObject> obj) { (void) obj; }

void BaseModel::remove(const iterator &it) { (void) it; }

BaseModel::iterator BaseModel::begin() { return iterator(); }

BaseModel::iterator BaseModel::end() { return iterator(); }

void BaseModel::accept(std::shared_ptr<Visitor> v) { (void) v; }

std::shared_ptr<BaseObject> BaseModel::clone() const { return nullptr; }
