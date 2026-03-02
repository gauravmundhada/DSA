class Solution {
public:
    int minSwaps(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<int> maxRight(n, -1);

        // Find rightmost 1 in each row
        for (int i = 0; i < n; i++) {
            for (int j = n - 1; j >= 0; j--) {
                if (grid[i][j] == 1) {
                    maxRight[i] = j;
                    break;
                }
            }
        }

        int swapCount = 0;

        // Instead of full sort, fix position by position
        for (int i = 0; i < n; i++) {

            int j = i;

            // Find row that satisfies condition
            while (j < n && maxRight[j] > i) {
                j++;
            }

            if (j == n)
                return -1;  // No valid row found

            // Bubble it up to position i
            while (j > i) {
                swap(maxRight[j], maxRight[j - 1]);
                swapCount++;
                j--;
            }
        }

        return swapCount;
    }
};