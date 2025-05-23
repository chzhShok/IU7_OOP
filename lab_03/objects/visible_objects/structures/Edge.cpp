#include "Edge.hpp"


Edge::Edge(size_t first, size_t second) : _first(first), _second(second) {};

size_t Edge::getFirst() const {
    return _first;
}

size_t Edge::getSecond() const {
    return _second;
}

void Edge::setFirst(size_t first) {
    _first = first;
}

void Edge::setSecond(size_t second) {
    _second = second;
}

void Edge::set(size_t first, size_t second) {
    _first = first;
    _second = second;
}

void Edge::set(const Edge &other) {
    _first = other._first;
    _second = other._second;
}

bool Edge::isEqual(const Edge &other) const {
    return (_first == other._first && _second == other._second) || (_first == other._second && _second == other._first);
}

bool Edge::operator==(const Edge &other) const {
    return isEqual(other);
}

bool Edge::isNotEqual(const Edge &other) const {
    return !isEqual(other);
}

bool Edge::operator!=(const Edge &other) const {
    return isNotEqual(other);
}
