class Solution {
public:
    int numSpecial(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        int ans = 0;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (mat[i][j] == 1) {
                    if (isSpecial(i, j, mat))
                        ans++;
                }
            }
        }  
        return ans;
    }

    bool isSpecial(int i, int j, vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();

        for (int x = 0; x < n; x++) {
            if (x != j && mat[i][x] == 1) return false;
        }

        for (int x = 0; x < m; x++) {
            if (x != i && mat[x][j] == 1) return false;
        }
        return true;
    }
};