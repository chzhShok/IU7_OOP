#include "Edge.hpp"

Edge::Edge(size_t first, size_t second) : __first(first), __second(second) {};

size_t Edge::getFirst() const {
    return __first;
}

size_t Edge::getSecond() const {
    return __second;
}

void Edge::setFirst(size_t first) {
    __first = first;
}

void Edge::setSecond(size_t second) {
    __second = second;
}

void Edge::set(size_t first, size_t second) {
    __first = first;
    __second = second;
}

void Edge::set(const Edge &other) {
    __first = other.__first;
    __second = other.__second;
}

bool Edge::isEqual(const Edge &other) const {
    return (__first == other.__first && __second == other.__second) || (__first == other.__second && __second == other.__first);
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
