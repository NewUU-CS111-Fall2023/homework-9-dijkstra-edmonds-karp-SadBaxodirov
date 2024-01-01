/*
 * Author:
 * Date:
 * Name:
 */
#include <vector>
#include <list>
#include <queue>
#include <climits>
using namespace std;
struct Edge {
    int to;
    int weight;
};
class Problem1 {
public:
    //big O((V+E)logV) where V is number of Vertices and E is number of Edges
    void dijkstra(vector<vector<Edge>>& graph, int start, vector<int>& distance, vector<int>& predecessor) {
        int n = graph.size();
        distance.assign(n, INT_MAX);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        distance[start] = 0;
        pq.push({0, start});
        while (!pq.empty()) {
            int u = pq.top().second;
            int dist_u = pq.top().first;
            pq.pop();
            if (dist_u > distance[u]) {
                continue;
            }
            for (const Edge& edge : graph[u]) {
                int v = edge.to;
                int weight_uv = edge.weight;
                // Relax function
                if (distance[v] > distance[u] + weight_uv) {
                    distance[v] = distance[u] + weight_uv;
                    predecessor[v] = u;
                    pq.push({distance[v], v});
                }
            }
        }
    }


};
