#include <iostream>
#include <vector>
#include "parse_task_file.hpp"
#include "argument_parser.hpp"


Task task;

std::vector<bool> visited;
int best_solution_time;
std::vector<int> best_solution;


void dfs(int vec, int time, std::vector<int> path) {
    bool any_adjanced_edge = false;

    for (auto next : task.graph.adjanced[vec]) {
        // is not visited and still able to reach (time)
        if (time + next.time <= task.max_time && !visited[next.next]) {
            any_adjanced_edge = true;

            // run DFS recursively with new start
            // filling out visited and path
            
            visited[next.next] = true;
            path.push_back(next.next);
            dfs(next.next, time + next.time, path);
            path.pop_back();

            visited[next.next] = false;
        }
    }

    if (!any_adjanced_edge) {
        // no adjanced edges - last vertex on path
        // check if found path is better then longest previous one

        if (path.size() > best_solution.size()) {
            best_solution = path;
            best_solution_time = time;
        }
    }
}

int main(int argc, char* argv[]) {
    auto file_name = argument_parser::get_input_file_name(argc, argv);

    ParseGraphFile pf(file_name);
    task = pf.parse_task();

    visited.resize(task.graph.vertices, false);
    visited[0] = true;
    dfs(0, 0, {0});


    std::cout << "Best solution: length = " << best_solution.size() << " vertices, time = " << best_solution_time << std::endl;
    
    std::cout << "Path: ";
    for (auto i : best_solution) {
        std::cout << i << " ";
    }
    std::cout << std::endl;

    return 0;
}
