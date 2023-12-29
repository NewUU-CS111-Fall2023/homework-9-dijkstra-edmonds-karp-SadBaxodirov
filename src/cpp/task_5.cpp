/*
 * Author:
 * Date:
 * Name:
 */

class Problem5 {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        unordered_map<int, vector<pair<int, int>>> graph;
        for (const auto& flight : flights) {
            graph[flight[0]].emplace_back(flight[1], flight[2]);
        }
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        pq.push({0, src, 0});
        while (!pq.empty()) {
            vector<int> top = pq.top();
            pq.pop();
            int cost = top[0];
            int node = top[1];
            int stops = top[2];
            if (node == dst) {
                return cost;
            }
            if (stops <= k) {
                for (const auto& neighbor : graph[node]) {
                    pq.push({cost + neighbor.second, neighbor.first, stops + 1});
                }
            }
        }
        return -1;
    }
};
