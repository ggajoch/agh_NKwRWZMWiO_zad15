
#include <iostream>
#include <limits>
#include "ParseGraphFile.hpp"


ParseGraphFile::ParseGraphFile(std::string FileName) {
    file.open(FileName);

    if (!file.good()) {
        std::cout << "Can't open file " << FileName << " or it doesn't exist." << std::endl;
        std::exit(1);
    }
}

ParseGraphFile::~ParseGraphFile() {
    file.close();
}

Task ParseGraphFile::ParseTask() {
    Task task;

    file >> task.graph.vertices >> task.graph.edges >> task.max_time;

    if (file.fail()) {
        file.clear();
        file.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Wrong input!\nFirst line format: number of vertices, number of edges, total time" << std::endl;
        std::exit(1);
    }

    task.graph.resize();

    for (int i = 0; i < task.graph.edges; ++i) {
        unsigned v, u, time;

        file >> v >> u >> time;

        if (file.fail()) {
            file.clear();
            file.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Wrong input!\nInput format: first vertex, second vertex, weight" << std::endl;
            std::exit(1);
        }

        if (v >= task.graph.vertices || u >= task.graph.vertices) {
            file.clear();
            file.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Wrong input!\nVertex number should satisfy formula \"0 <= v < " << v << "\"" << std::endl;
            std::exit(1);
        }

        task.graph.add_edge(v, u, time);
    }

    return task;
}
