#ifndef DFS1_STRUCTS_H
#define DFS1_STRUCTS_H

#include <vector>

struct Edge {
    unsigned next;
    unsigned time;

    Edge(unsigned next, unsigned time) : next(next), time(time) {}
};


struct Graph {
    unsigned vertices, edges;
    std::vector<std::vector<Edge>> adjanced;

    void resize() {
        adjanced.clear();
        adjanced.resize(vertices);
    }

    void add_edge(unsigned v, unsigned u, unsigned time) {
        adjanced[v].push_back(Edge(u, time));
        adjanced[u].push_back(Edge(v, time));
    }
};

struct Task {
    Graph graph;
    unsigned max_time;
};

#endif //DFS1_STRUCTS_H
