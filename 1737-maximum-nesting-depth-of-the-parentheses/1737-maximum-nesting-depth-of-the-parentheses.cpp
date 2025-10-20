class Solution {
public:
    int maxDepth(string s) {
        int counter = 0;
        int ans = 0;

        for (char ch : s) {
            if (ch == '(') {
                counter++;
                ans = max(ans, counter);
            } else if (ch == ')') {
                counter--;
            }
        }
        return ans;
    }
};