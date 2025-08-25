class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();

        bool up = true;
        int i = 0, j = 0;

        vector<int> res;

        while (res.size() < n * m) {
            if (up) {
                while (i >= 0 && j < m) {   // ✅ fixed condition
                    res.push_back(mat[i][j]);
                    i--;
                    j++;
                }
                if (j >= m) {   // ✅ went past last column
                    i += 2;
                    j = m - 1;
                } else {        // ✅ went past top row
                    i = 0;
                }
                up = false;
            } else {
                while (i < n && j >= 0) {   // ✅ fixed condition
                    res.push_back(mat[i][j]);
                    i++;
                    j--;
                }
                if (i >= n) {   // ✅ went past last row
                    j += 2;
                    i = n - 1;
                } else {        // ✅ went past left column
                    j = 0;
                }
                up = true;
            }
        }
        return res;
    }
};
