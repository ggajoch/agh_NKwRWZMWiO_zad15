#include <iostream>
#include <vector>
#include "ParseGraphFile.hpp"


Task task;

std::vector<bool> visited;
int best_solution_time;
std::vector<int> best_solution;


int dfs(int vec, int time, std::vector<int> path) {
    bool any_adjanced_edge = false;

    for (auto next : task.graph.adjanced[vec]) {
        if (time + next.time <= task.max_time && !visited[next.next]) {
            any_adjanced_edge = true;

            visited[next.next] = true;
            path.push_back(next.next);
            dfs(next.next, time + next.time, path);
            path.pop_back();

            visited[next.next] = false;
        }
    }

    if (!any_adjanced_edge) {
        // no adjanced edges - last vertex on path

        if (path.size() > best_solution.size()) {
            best_solution = path;
            best_solution_time = time;
        }
    }
}

int main() {
    ParseGraphFile pf("in.txt");
    task = pf.ParseTask();

    visited.resize(task.graph.vertices, false);
    visited[0] = true;
    dfs(0, 0, {0});


    std::cout << "Best solution found [length = " << best_solution.size() <<
         ", time = " << best_solution_time << "]" << std::endl;
    
    std::cout << "Path: ";
    for (auto i : best_solution) {
        std::cout << i << " ";
    }
    std::cout << std::endl;

    return 0;
}
