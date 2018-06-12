#include <iostream>
#include <vector>
#include <limits>

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

int main() {
	  std::cout << "Input format: number of vertices, number of edges, total time" << std::endl;
    std::cin >> v >> e >> max_time;
    while(1)
    {
      if (std::cin.fail())
      {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
        std::cout << "Wrong input!\nInput format: number of vertices, number of edges, total time" << std::endl;
        std::cin >> v >> e >> max_time;
      }
      else
      {
        break;
      }
    }


    visited.resize(v, false);
    g.resize(v);

    std::cout << "Input format: first vertex, second vertex, weight" << std::endl;

    for(int i = 0; i < e; ++i) {
        int a, b, t;

        std::cin >> a >> b >> t;
        while(1)
        {
          if (std::cin.fail())
          {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
            std::cout << "Wrong input!\nInput format: first vertex, second vertex, weight" << std::endl;
            std::cin >> a >> b >> t;
          }
          if (a >= v || b >= v)
          {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
            std::cout << "Wrong input!\nVertex number should satisfy formula \"0 <= v < " << v << "\"" << std::endl;
            std::cin >> a >> b >> t;
          }
          else
          {
            break;
          }
        }
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
