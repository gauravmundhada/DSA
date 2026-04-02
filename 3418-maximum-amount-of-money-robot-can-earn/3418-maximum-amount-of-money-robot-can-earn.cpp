class Solution {
public:
    int n, m;
    int t[501][501][3];
    int solve(vector<vector<int>>& coins, int i, int j, int neuCount) {
        if (i == m-1 && j == n-1) {
            if (coins[i][j] < 0 && neuCount > 0) {
                return 0;
            }
            return coins[i][j];
        }

        if (t[i][j][neuCount] != INT_MIN) return t[i][j][neuCount];

        if (i >= m || j >= n) {
            return INT_MIN;
        }

        int take = coins[i][j] + max(solve(coins, i+1, j, neuCount), solve(coins, i, j+1, neuCount));

        int skip = INT_MIN;
        if (coins[i][j] < 0 && neuCount > 0) {
            int skip_right = solve(coins, i, j+1, neuCount-1);
            int skip_down = solve(coins, i+1, j, neuCount-1);
            skip = max(skip_right, skip_down);
        }

        return t[i][j][neuCount] = max(skip, take);
    }

    int maximumAmount(vector<vector<int>>& coins) {
        m = coins.size();
        n = coins[0].size();
        int neuCount = 2;

        for (int i = 0; i < 501; i++) {
            for (int j = 0; j < 501; j++) {
                for (int k = 0; k < 3; k++) {
                    t[i][j][k] = INT_MIN;
                }
            }
        }

        return solve(coins, 0, 0, neuCount);
    }
};

/*
start -> (0, 0) end -> (m-1, n-1)
movement -> right(0, 1), down(1, 0)

If coins[i][j] >= 0, the robot gains that many coins.
If coins[i][j] < 0, the robot encounters a robber, and the robber steals the absolute value of coins[i][j] coins.

neutralize robbers in at most 2 cells 

0  1  -1
1  -2  3
2  -3  4
*/