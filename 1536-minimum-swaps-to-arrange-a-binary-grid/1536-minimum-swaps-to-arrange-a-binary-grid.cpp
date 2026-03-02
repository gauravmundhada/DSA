class Solution {
public:
    int minSwaps(vector<vector<int>>& grid) {
        int n = grid.size();

        vector<int> trailingZeroes(n);

        for (int i = 0; i < n; i++) {
            int count = 0;
            for (int j = n-1; j >= 0; j--) {
                if (grid[i][j] == 0) count++;
                else break;
            }
            trailingZeroes[i] = count;
        }

        int swaps = 0;

        for (int i = 0; i < n; i++) {
            int zeroNeed = n - i - 1;

            int j = i;
            while (j < n && trailingZeroes[j] < zeroNeed) j++;
            if (j == n) return -1;

            while (j > i) {
                swap(trailingZeroes[j], trailingZeroes[j-1]);
                j--;
                swaps++;
            }
        }
        return swaps;
    }
};