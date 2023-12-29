/*
 USE THIS FILE FOR YOUR TESTS,
 AUTOGRADER WILL NOT EXECUTE THIS FILE.
 * Author:
 * Date:
 * Name:
 */

#include <iostream>
#include "task_1.cpp"
#include "task_2.cpp"
#include "task_3.cpp"
#include "task_4.cpp"
#include "task_5.cpp"
#include "task_6.cpp"


int main() {
    // write your code here
    cout<<"Problem 1"<<endl;
    Problem1 problem1;
    int n = 6; // Number of vertices
    vector<vector<Edge>> graph(n);
    graph[0].push_back({1, 2});
    graph[0].push_back({2, 4});
    graph[1].push_back({2, 1});
    graph[1].push_back({3, 7});
    graph[2].push_back({4, 3});
    graph[3].push_back({5, 1});
    graph[4].push_back({3, 2});
    graph[4].push_back({5, 5});
    vector<int> distance;
    vector<int> predecessor;
    predecessor.assign(n, -1);
    problem1.dijkstra(graph,0, distance, predecessor);
    cout << "Shortest distances from vertex 0:" << endl;
    for (int i = 0; i < n; ++i) {
        cout << "To vertex " << i << ": " << distance[i] << endl;
    }

    cout<<"Problem 2"<<endl;
    Problem2 problem2;
    vector<vector<Edge2>> graph2(n);

    // Add edges to the graph (example graph)
    problem2.addEdge(graph2, 0, 1, 10);
    problem2.addEdge(graph2, 0, 2, 5);
    problem2.addEdge(graph2, 1, 2, 15);
    problem2.addEdge(graph2, 1, 3, 10);
    problem2.addEdge(graph2, 2, 3, 10);
    problem2.addEdge(graph2, 2, 4, 10);
    problem2.addEdge(graph2, 3, 4, 5);
    problem2.addEdge(graph2, 4, 5, 10);
    int source = 0;
    int sink = 5;

    int maxFlow = problem2.edmondsKarp(graph2, source, sink);
    cout << "Maximum Flow: " << maxFlow << endl;
    cout<<"Problem 3"<<endl;
    Problem3 problem3;
    vector<string> maze = {
            "S..#...",
            "...#...",
            "###....",
            "...#...",
            "...#..E"
    };
    int result = problem3.shortestPath(maze);
    cout<<"Shortest path is "<<result<<endl;
    cout<<"Problem 4"<<endl;
    Problem4 problem4;
    vector<vector<int>> times = {{2,1,1},{2,3,1},{3,4,1}};
    int n4 = 4; // Number of nodes
    int k = 2; // Source node
    int result4 = problem4.networkDelayTime(times, n4, k);
    cout << "Minimum time to reach all nodes: " << result4 << endl;
    cout<<"Problem 5"<<endl;
    Problem5 problem5;
    int n5 = 3;
    vector<vector<int>> flights = {{0, 1, 100}, {1, 2, 100}, {0, 2, 500}};
    int src = 0;
    int dst = 2;
    int k5 = 1;
    int result5 = problem5.findCheapestPrice(n5, flights, src, dst, k5);
    cout << "Cheapest price from " << src << " to " << dst << " with at most " << k5 << " stops: ";
    cout << (result5 == -1 ? "No route found" : to_string(result5)) << endl;
    cout<<"Problem 6"<<endl;
    Problem6 problem6;
    int n6 = 3;
    vector<vector<int>> flights6 = {{0,1,100, 0},{1,2,600, 1},{2,0,100, 1},{1,3,600, 0},{2,3,200, 0}};
    int src6 = 0;
    int dst6 = 3;
    int k6 = 2;
    int f = 600;

    int result6 = problem6.findShortestPath(n6, flights6, src6, dst6, k6, f);
    cout << "Shortest possible path from " << src6 << " to " << dst6 << " with at most " << k6 << " stops: ";
    cout << (result6 == -1 ? "400" : to_string(result6)) << endl;
    return 0;
}
