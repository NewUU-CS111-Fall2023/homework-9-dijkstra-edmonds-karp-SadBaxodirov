#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

struct Edge2 {
    int to;
    int capacity;
    int flow;
};
class Problem2 {
public:
    void addEdge(vector<vector<Edge2>>& graph, int from, int to, int capacity) {
        graph[from].push_back({to, capacity, 0});
    }
    //Big O(E*V^2) where V is number of vertices and E is number of Edges
    int edmondsKarp(vector<vector<Edge2>>& graph, int source, int sink) {
        int totalFlow = 0;
        while (true) {
            queue<int> q;
            q.push(source);
            vector<int> pred(graph.size(), -1);
            while (!q.empty() && pred[sink] == -1) {
                int cur = q.front();
                q.pop();
                for (const Edge2& e : graph[cur]) {
                    if (pred[e.to] == -1 && e.to != source && e.capacity > e.flow) {
                        pred[e.to] = cur;
                        q.push(e.to);
                    }
                }
            }
            if (pred[sink] == -1) {
                break;
            }
            int pathFlow = INT_MAX;
            for (int u = sink; u != source; u = pred[u]) {
                for (const Edge2& e : graph[pred[u]]) {
                    if (e.to == u) {
                        pathFlow = min(pathFlow, e.capacity - e.flow);
                        break;
                    }
                }
            }
            for (int u = sink; u != source; u = pred[u]) {
                for (Edge2& e : graph[pred[u]]) {
                    if (e.to == u) {
                        e.flow += pathFlow;
                        break;
                    }
                }
                for (Edge2& e : graph[u]) {
                    if (e.to == pred[u]) {
                        e.flow -= pathFlow;
                        break;
                    }
                }
            }
            totalFlow += pathFlow;
        }
        return totalFlow;
    }
};


