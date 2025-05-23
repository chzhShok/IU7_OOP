#pragma once

#include <cstddef>
#include <memory>

#include "BaseCommand.hpp"

using ID = std::shared_ptr<std::size_t>;

class CameraCommand : public BaseCommand {};

class AddCamera : public CameraCommand {
public:
    AddCamera(const ID &id, const Vertex &location);

    virtual void execute() override;

private:
    ID _id;
    Vertex _location;
};


class DeleteCamera : public CameraCommand {
public:
    DeleteCamera(const std::size_t id);

    virtual void execute() override;

private:
    std::size_t _id;
};


class MoveCamera : public CameraCommand {
public:
    MoveCamera(const double dx, const double dy, const double dz, const size_t id);

    virtual void execute() override;

private:
    double _dx, _dy, _dz;
    std::size_t _id;
};


class SetCamera : public CameraCommand {
public:
    explicit SetCamera(const std::size_t id);

    virtual void execute() override;

private:
    std::size_t _id;
};
