#include <iostream>
#include <vector>

using namespace std;
const int MOD = 1e9 + 7;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // row, column, vent
    int r, c, v;
    cin >> r >> c >> v;

    vector<vector<int>> grid(r, vector<int>(c));

    // vents[i] = vector of starting cells which ends with cell i
    vector<vector<int>> vents(c * r, vector<int>(0));

    // fill the grid
    // -1 for blocked cells
    //  0 for unblocked cells
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            cin >> grid[i][j];
            grid[i][j]--;
        }
    }
    // If starting cell or ending cell is blocked, the answer will be 0
    if (grid[0][0] == -1 || grid[r - 1][c - 1] == -1) {
        cout << "0\n";
        return 0;
    }

    // Initialize starting cell as 1
    grid[0][0] = 1;

    // vent entrance = [row1, col1]
    // vent exit     = [row2, col2]
    for (int i = 0; i < v; i++) {
        int row1, col1, row2, col2;
        cin >> row1 >> col1 >> row2 >> col2;
        vents[row2 * c + col2].push_back(row1 * c + col1);
    }

    // iterate over all cells
    // 0     1     ... (c - 1)
    // c  (c + 1)  ... (2c - 1)
    //             ...
    // ((r-1) * c) ... (rc - 1)
    for (int i = 0; i < r * c; i++) {
        int row = i / c;
        int col = i % c;
        // if blocked continue to next cell
        if (grid[row][col] == -1) {
            continue;
        }
        // if there is a upper cell and if it is unblocked add it
        if (row > 0 && grid[row - 1][col] != -1) {
            grid[row][col] += grid[row - 1][col];
            grid[row][col] %= MOD;
        }
        // if there is a cell at left and if it is unblocked add it
        if (col > 0 && grid[row][col - 1] != -1) {
            grid[row][col] += grid[row][col - 1];
            grid[row][col] %= MOD;
        }

        // take vent entrances which are ended with cell i = [row, col]
        // add the total ways of reaching entrance to the exit
        for (auto vent : vents[i]) {
            int ventCol = vent % c;
            int ventRow = vent / c;
            grid[row][col] += grid[ventRow][ventCol];
            grid[row][col] %= MOD;
        }
    }
    cout << grid[r - 1][c - 1] << "\n";
    return 0;
}