#include <bits/stdc++.h>

using namespace std;

class Solution {
   public:
    vector<int> dir_x{-1, 0, 1, 0};
    vector<int> dir_y{0, -1, 0, 1};
    int max_area = 0;

    void markAndCalculateAreas(int i, int j, vector<vector<int>>& grid, int marker, unordered_map<int, int>& sizeOfIslands) {
        grid[i][j] = marker;
        sizeOfIslands[marker]++;

        for (int k = 0; k < 4; k++) {
            int next_i = i + dir_x[k];
            int next_j = j + dir_y[k];

            if (next_i >= 0 && next_i < grid.size() && next_j >= 0 && next_j < grid[next_i].size() && grid[next_i][next_j] == 1) {
                markAndCalculateAreas(next_i, next_j, grid, marker, sizeOfIslands);
            }
        }
    }

    void changeFourAdjacentCell(int i, int j, int remaining, set<pair<int, int>>& visited, vector<vector<int>>& grid, unordered_map<int, int>& sizeOfIslands) {
        visited.insert({i, j});
        remaining -= 1;

        int new_size = 0;
        unordered_set<int> lands;
        for (auto cell : visited) {
            if (grid[cell.first][cell.second] == 0)
                new_size++;
        }

        for (auto changed_cell : visited) {
            for (int k = 0; k < dir_x.size(); k++) {
                int next_i = changed_cell.first + dir_x[k];
                int next_j = changed_cell.second + dir_y[k];

                if (next_i >= 0 && next_i < grid.size() && next_j >= 0 && next_j < grid.size() && grid[next_i][next_j] != 0 && lands.find(grid[next_i][next_j]) == lands.end()) {
                    lands.insert(grid[next_i][next_j]);
                    new_size += sizeOfIslands[grid[next_i][next_j]];
                }
            }
        }
        max_area = max(max_area, new_size);

        if (remaining == 0) {
            visited.erase({i, j});
            return;
        }

        for (int k = 0; k < dir_x.size(); k++) {
            int next_i = i + dir_x[k];
            int next_j = j + dir_y[k];

            if (next_i >= 0 && next_i < grid.size() && next_j >= 0 && next_j < grid.size() && visited.find({next_i, next_j}) == visited.end()) {
                changeFourAdjacentCell(next_i, next_j, remaining, visited, grid, sizeOfIslands);
            }
        }

        visited.erase({i, j});
    }

    int largestIsland(vector<vector<int>>& grid) {
        unordered_map<int, int> sizeOfIslands;

        int marker = 2;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] == 1) {
                    markAndCalculateAreas(i, j, grid, marker, sizeOfIslands);
                    max_area = max(max_area, sizeOfIslands[marker]);
                    marker++;
                }
            }
        }

        // switch adjacent 3 cell from zero to one
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] == 0) {
                    set<pair<int, int>> visited;
                    changeFourAdjacentCell(i, j, 3, visited, grid, sizeOfIslands);
                }
            }
        }

        return max_area;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    vector<vector<int>> grid(n, vector<int>(n));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];
        }
    }

    Solution solution;
    cout << solution.largestIsland(grid) << '\n';

    return 0;
}