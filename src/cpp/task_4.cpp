/*
 * Author:
 * Date:
 * Name:
 */

#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <climits>
class Problem4 {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        unordered_map<int, vector<pair<int, int>>> graph;
        for (const auto& edge : times) {
            int u = edge[0];
            int v = edge[1];
            int w = edge[2];
            graph[u].emplace_back(v, w);
        }
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        vector<int> distance(n + 1, INT_MAX);
        pq.push({0, k});
        distance[k] = 0;
        while (!pq.empty()) {
            int dist, node;
            tie(dist, node) = pq.top();
            pq.pop();
            if (dist > distance[node]) {
                continue;
            }
            for (const auto& neighbor : graph[node]) {
                int nextNode = neighbor.first;
                int nextDist = dist + neighbor.second;
                if (nextDist < distance[nextNode]) {
                    distance[nextNode] = nextDist;
                    pq.push({nextDist, nextNode});
                }
            }
        }
        int maxTime = 0;
        for (int i = 1; i <= n; ++i) {
            if (distance[i] == INT_MAX) {
                return -1;
            }
            maxTime = max(maxTime, distance[i]);
        }
        return maxTime;
    }
};
