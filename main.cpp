#include <iostream>
#include <vector>
#include "ParseGraphFile.hpp"

int v, e, max_time;

struct Edge {
    int next;
    int time;

    Edge(int next, int time) : next(next), time(time) {}
};
std::vector<std::vector<Edge>> g;

std::vector<bool> visited;

int best_solution_time;
std::vector<int> best_solution;

int dfs(int vec, int time, std::vector<int> path) {
//    printf("IN %d\n", vec);
    bool any = false;
    for(auto next : g[vec]) {
        if (time + next.time <= max_time && !visited[next.next]) {
            any = true;

            visited[next.next] = true;
            path.push_back(next.next);
            dfs(next.next, time + next.time, path);
            path.pop_back();

            visited[next.next] = false;
        }
    }

    if (!any) {
        // last vertex on path
        for(auto x : path) {
            printf("%d ", x);
        }
        printf("---> %d %d\n", time, path.size());

        if (path.size() > best_solution.size()) {
            best_solution = path;
            best_solution_time = time;
        }
    }
//    printf("OUT %d\n", vec);
}

int main()
{

    ParseGraphFile pf("in.txt");
    pf.GetStrLines();
    IntMatrix GraphMatrix = pf.ConvertStrLinesToInt();
    
    
    v = GraphMatrix[0][0];
    e = GraphMatrix[0][1];
    max_time = GraphMatrix[0][2];
    //std::cin >> v >> e >> max_time;
    

    visited.resize(v, false);
    g.resize(v);

    
    for(int i = 1; i <= e; ++i) {
        int a, b, t;

	a = GraphMatrix[i][0];
	b = GraphMatrix[i][1];
	t = GraphMatrix[i][2];
        //std::cin >> a >> b >> t;
        
        g[a].push_back(Edge(b, t));
        g[b].push_back(Edge(a, t));
    }


    visited[0] = true;
    dfs(0, 0, {0});


    printf("Best solution found [len = %u, time = %d]:\n", best_solution.size(), best_solution_time);
    for(auto i : best_solution) {
        printf("%d ", i);
    }
    printf("\n");
    return 0;
}
