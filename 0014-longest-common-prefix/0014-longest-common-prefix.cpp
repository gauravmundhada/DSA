class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int n = strs.size();

        if (n == 1) return strs[0];

        string pre = "";
        for (int i = 0; i < strs[0].size(); i++) {
            char ch = strs[0][i];

            for (int j = 1; j < n; j++) {
                if (strs[j][i] == ch) {
                    if (j == n-1) pre.push_back(ch);
                } else {
                    return pre;
                }
            }
        }
        return pre;
    }
};