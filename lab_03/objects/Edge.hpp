#pragma once

#include <cstddef>

class Edge {
public:
    Edge() = default;
    Edge(size_t first, size_t second);
    explicit Edge(const Edge &other) = default;
    Edge(Edge &&other) = default;

    Edge &operator=(const Edge &other) = default;
    Edge &operator=(Edge &&other) = default;

    size_t getFirst() const;
    size_t getSecond() const;
    void setFirst(size_t first);
    void setSecond(size_t second);
    void set(const Edge &other);
    void set(size_t first, size_t second);

    bool operator==(const Edge &other) const;
    bool operator!=(const Edge &other) const;
    bool isEqual(const Edge &other) const;
    bool isNotEqual(const Edge &other) const;

private:
    size_t _first;
    size_t _second;
};
