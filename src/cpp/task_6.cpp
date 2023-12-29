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
class Problem6 {
public:
    int findShortestPath(int n, vector<vector<int>>& flights, int src, int dst, int k, int f) {
        unordered_map<int, vector<pair<int, pair<int, int>>>> graph;
        for (const auto& flight : flights) {
            graph[flight[0]].emplace_back(flight[1], make_pair(flight[2], flight[3]));
        }
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        pq.push({0, f, src, 0});
        while (!pq.empty()) {
            vector<int> top = pq.top();
            pq.pop();
            int totalDistance = top[0];
            int fuel = top[1];
            int node = top[2];
            int stops = top[3];
            if (node == dst) {
                return totalDistance;
            }
            if (stops <= k) {
                for (const auto& neighbor : graph[node]) {
                    int nextNode = neighbor.first;
                    int distance = neighbor.second.first;
                    int ars = neighbor.second.second;
                    if (fuel >= distance) {
                        int remainingFuel = ars == 1 ? f : fuel - distance;
                        pq.push({totalDistance + distance, remainingFuel, nextNode, stops + 1});
                    }
                }
            }
        }
        return -1;
    }
};
