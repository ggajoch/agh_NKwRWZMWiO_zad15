#include <iostream>
#include <vector>

int v, e;
std::vector<std::vector<int>> g;

std::vector<bool> visited;


int dfs(int vec, std::vector<int> path) {
//    printf("IN %d\n", vec);
    bool any = false;
    for(auto next : g[vec]) {
        if (!visited[next]) {
            any = true;

            visited[next] = true;
            path.push_back(next);
            dfs(next, path);
            path.pop_back();

            visited[next] = false;
        }
    }

    if (!any) {
        // last vertex on path
        for(auto x : path) {
            printf("%d ", x);
        }
        printf("\n");
    }
//    printf("OUT %d\n", vec);
}

int main() {
    std::cin >> v >> e;

    visited.resize(v, false);
    g.resize(v);

    for(int i = 0; i < e; ++i) {
        int a, b;
        std::cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    visited[0] = true;
    dfs(0, {});

    std::cout << "Hello, World!" << std::endl;
    return 0;
}