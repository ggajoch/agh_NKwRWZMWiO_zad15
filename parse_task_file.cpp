#include <iostream>
#include <limits>
#include "parse_task_file.hpp"
#include "argument_parser.hpp"


ParseGraphFile::ParseGraphFile(std::string file_name) {
    file.open(file_name);

    if (file.good()) {
        std::cout << "Successfully opened file " << file_name << std::endl;
    } else {
        std::cout << "Can't open file " << file_name << " or it doesn't exist." << std::endl;
        argument_parser::print_help_and_exit(1);
    }
}

ParseGraphFile::~ParseGraphFile() {
    file.close();
}

Task ParseGraphFile::parse_task() {
    Task task;

    file >> task.graph.vertices >> task.graph.edges >> task.max_time;

    if (file.fail()) {
        file.clear();
        file.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Wrong input!\nFirst line format: number of vertices, number of edges, total time" << std::endl;
        argument_parser::print_help_and_exit(1);
    }

    task.graph.resize();

    for (unsigned i = 0; i < task.graph.edges; ++i) {
        unsigned v, u, time;

        file >> v >> u >> time;

        if (file.fail()) {
            file.clear();
            file.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Wrong input!\nInput format: first vertex, second vertex, weight" << std::endl;
            argument_parser::print_help_and_exit(1);
        }

        if (v >= task.graph.vertices || u >= task.graph.vertices) {
            file.clear();
            file.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Wrong input!\nVertex number should satisfy formula \"0 <= v < " << v << "\"" << std::endl;
            argument_parser::print_help_and_exit(1);
        }

        task.graph.add_edge(v, u, time);
    }

    return task;
}
