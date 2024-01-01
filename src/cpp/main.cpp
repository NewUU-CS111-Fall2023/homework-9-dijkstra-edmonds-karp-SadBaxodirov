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
    int n=6; // Number of vertices
    vector<int> distance;
    vector<int> predecessor;
    predecessor.assign(n, -1);
    vector<vector<Edge>> graph1(n);
    graph1[0].push_back({1, 2});
    graph1[0].push_back({2, 4});
    graph1[1].push_back({2, 1});
    graph1[1].push_back({3, 7});
    graph1[2].push_back({4, 3});
    graph1[3].push_back({5, 1});
    graph1[4].push_back({3, 2});
    graph1[4].push_back({5, 5});
    problem1.dijkstra(graph1, 0, distance, predecessor);
    cout << "Shortest distances from vertex 0:" << endl;
    for (int i = 0; i < n; ++i) {
        cout << "To vertex " << i << ": " << distance[i] <<", predecessor: "<<predecessor[i]<< endl;
    }

    cout<<"Problem 2"<<endl;
    Problem2 problem2;
    int n2=8;
    vector<vector<Edge2>> graph2(n2);
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
    int rows, cols;
    cout<<"Enter number of rows and columns: ";
    cin>>rows>>cols;
    vector<char> rowN;
    vector<vector<char>> maze;
    char temp;
    for (int i=0;i<rows;i++){
        for (int j=0;j<cols;j++){
            cin>>temp;
            rowN.push_back(temp);
        }
        maze.push_back(rowN);
        rowN.clear();
    }
    /*vector<vector<char>> maze = {
            {'S', '.', '.', '#', '.', '.','.'},
            {'.', '.', '.', '.', '.', '.','.'},
            {'#', '#', '#', '.','.','.','.'},
            {'.', '.', '.', '#', '.', '.','.'},
            {'S', '.', '.', '#', '.', '.','E'}
    };*/
    int result = problem3.shortestPath(maze);
    cout<<"Shortest path from S to E is "<<result<<" steps"<<endl;

    cout<<"Problem 4"<<endl;
    Problem4 problem4;
    int n4; // Number of nodes
    int k4; // Source node
    cout<<"Enter number of nodes: ";
    cin>>n4;
    int from;
    int to;
    int weight;
    vector<vector<int>> times;// = {{2,1,1},{2,3,1},{3,4,1},{4,5,2}};
    cout<<"Enter from, to and weight values: ";
    for (int i=0;i<n4;i++){
        cin>>from;
        cin>>to;
        cin>>weight;
        times.push_back({from, to, weight});
    }
    cout<<"Enter starting node: ";
    cin>>k4;
    int result4 = problem4.networkDelayTime(times, n4, k4);
    cout << "Minimum time to reach all nodes: " << result4 << endl;

    cout<<"Problem 5"<<endl;
    Problem5 problem5;
    int n5;
    int from5;
    int to5;
    int price;
    cout<<"Enter number of nodes: ";
    cin>>n5;
    vector<vector<int>> flights;// = {{0, 1, 100}, {1, 2, 100}, {0, 2, 500}};
    cout<<"Enter from, to and price values: ";
    for (int i=0;i<n5;i++){
        cin>>from5;
        cin>>to5;
        cin>>price;
        flights.push_back({from5, to5, price});
    }
    int src;
    int dst;
    int k5;
    cout<<"Enter source, destination and number of stops: ";
    cin>>src>>dst>>k5;
    int result5 = problem5.findCheapestPrice(n5, flights, src, dst, k5);
    cout << "Cheapest price from " << src << " to " << dst << " with at most " << k5 << " stops: ";
    cout << (result5 == -1 ? "No route found" : to_string(result5)) << endl;

    cout<<"Problem 6"<<endl;
    Problem6 problem6;
    int n6;
    int e6;
    int from6;
    int to6;
    int distance6;
    int ARS6;
    vector<vector<int>> flights6;// = {{0,1,100, 0},{1,2,600, 1},{2,0,100, 1},{1,3,600, 0},{2,3,200, 0}};
    cout<<"Enter number of cities: ";
    cin>>n6;
    cout<<"Enter number of edges: ";
    cin>>e6;
    cout<<"Enter from, to, distance and ARS values: ";
    for (int i=0;i<e6;i++){
        cin>>from6;
        cin>>to6;
        cin>>distance6;
        cin>>ARS6;
        flights6.push_back({from6, to6, distance6,ARS6});
    }
    int src6;
    int dst6;
    int k6;
    int f6;
    cout<<"Enter source, destination, number of stops and distance without refueling: ";
    cin>>src6>>dst6>>k6>>f6;
    int result6 = problem6.findShortestPath(n6, flights6, src6, dst6, k6, f6);
    cout << "Shortest possible path from " << src6 << " to " << dst6 << " with at most " << k6 << " stops: ";
    cout << (result6 == -1 ? "-1" : to_string(result6)) << endl;
    return 0;
}
