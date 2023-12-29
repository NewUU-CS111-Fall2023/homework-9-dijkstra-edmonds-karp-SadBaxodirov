/*
 * Author:
 * Date:
 * Name:
 */
#include <iostream>
#include <vector>
#include <queue>
#include <tuple>

using namespace std;
class Problem3 {
public:
    int shortestPath(vector<string>& maze) {
        int rows = maze.size();
        int cols = maze[0].size();
        pair<int, int> start, end;
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                if (maze[i][j] == 'S') {
                    start = make_pair(i, j);
                } else if (maze[i][j] == 'E') {
                    end = make_pair(i, j);
                }
            }
        }
        vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        queue<tuple<int, int, int>> q;  // {row, col, distance}
        q.push(make_tuple(start.first, start.second, 0));
        vector<vector<bool>> visited(rows, vector<bool>(cols, false));
        visited[start.first][start.second] = true;
        while (!q.empty()) {
            int row, col, distance;
            tie(row, col, distance) = q.front();
            q.pop();
            if (make_pair(row, col) == end) {
                return distance;
            }
            for (const auto& dir : directions) {
                int newRow = row + dir.first;
                int newCol = col + dir.second;
                if (newRow >= 0 && newRow < rows && newCol >= 0 && newCol < cols &&
                    maze[newRow][newCol] == '.' && !visited[newRow][newCol]) {
                    visited[newRow][newCol] = true;
                    q.push(make_tuple(newRow, newCol, distance + 1));
                }
            }
        }
        return -1;
    }
};
