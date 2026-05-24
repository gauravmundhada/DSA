class Solution {
public:

    vector<int> dp;

    int DFS(unordered_map<int, vector<int>>& mpp,
            int idx) {

        if (dp[idx] != -1)
            return dp[idx];

        int jump = 0;

        for (int j : mpp[idx]) {

            jump = max(jump,
                       1 + DFS(mpp, j));
        }

        return dp[idx] = jump;
    }

    int maxJumps(vector<int>& arr, int d) {

        int n = arr.size();

        unordered_map<int, vector<int>> mpp;

        // build graph
        for (int i = 0; i < n; i++) {

            // right side
            for (int x = 1; x <= d; x++) {

                if (i + x >= n)
                    break;

                // FIXED
                if (arr[i + x] >= arr[i])
                    break;

                mpp[i].push_back(i + x);
            }

            // left side
            for (int x = 1; x <= d; x++) {

                if (i - x < 0)
                    break;

                // FIXED
                if (arr[i - x] >= arr[i])
                    break;

                mpp[i].push_back(i - x);
            }
        }

        dp.resize(n, -1);

        int ans = 0;

        for (int i = 0; i < n; i++) {

            ans = max(ans,
                      1 + DFS(mpp, i));
        }

        return ans;
    }
};