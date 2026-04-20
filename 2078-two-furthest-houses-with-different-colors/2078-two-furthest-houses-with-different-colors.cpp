class Solution {
public:
    int maxDistance(vector<int>& colors) {
        int n = colors.size();
        int ans = 0;

        int i = 0, j = n-1;

        for (; i < n; i++) {
            while (j >= 0 && colors[i] == colors[j]) {
                j--;
            }
            ans = max(ans, abs(i-j));
            j = n-1; // reset
        }
        return ans;
    }
};