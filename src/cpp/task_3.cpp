/*
 * Author:
 * Date:
 * Name:
 */
#include <iostream>
#include <vector>
#include <queue>

using namespace std;
class Problem3 {
public:
    struct Point {
        int row, col, distance;
    };
    //Big O(rows*columns) as the algorithms visits each node of maze once
    int shortestPath(vector<vector<char>>& maze) {
        int rows = maze.size();
        if (rows == 0) return -1;
        int cols = maze[0].size();
        if (cols == 0) return -1;
        int dr[] = {-1, 0, 0, 1};
        int dc[] = {0, -1, 1, 0};
        int startRow = -1, startCol = -1;
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                if (maze[i][j] == 'S') {
                    startRow = i;
                    startCol = j;
                    break;
                }
            }
            if (startRow != -1) break;
        }
        if (startRow == -1) return -1;
        queue<Point> q;
        q.push({startRow, startCol, 0});
        maze[startRow][startCol] = '#';
        while (!q.empty()) {
            Point current = q.front();
            q.pop();
            for (int i = 0; i < 4; ++i) {
                int nextRow = current.row + dr[i];
                int nextCol = current.col + dc[i];
                if (nextRow >= 0 && nextRow < rows && nextCol >= 0 && nextCol < cols &&
                    maze[nextRow][nextCol] != '#') {
                    if (maze[nextRow][nextCol] == 'E') {
                        return current.distance + 1;
                    }
                    q.push({nextRow, nextCol, current.distance + 1});
                    maze[nextRow][nextCol] = '#';
                }
            }
        }
        return -1;
    }
};
