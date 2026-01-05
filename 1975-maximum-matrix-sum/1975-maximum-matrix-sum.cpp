class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        long long sum = 0;
        int negativeCount = 0;
        int smallest = INT_MAX;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                sum += abs(matrix[i][j]);
                if (matrix[i][j] < 0) {
                    negativeCount++;
                }
                smallest = min(smallest, abs(matrix[i][j]));
            }
        }

        if (negativeCount % 2 == 0) return sum;

        long long diff = 2 * smallest; // agar odd count h to 1 -ve value rhegi so sum mein se wo minus hoga and wo include b nahi ho rha so 2 times
        return sum - diff;
    }
};