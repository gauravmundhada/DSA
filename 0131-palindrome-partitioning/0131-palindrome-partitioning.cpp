class Solution {
public:
    void solve(string& s, int i, vector<string>& curr, vector<vector<string>>& result, vector<vector<bool>>& t) {
        if (i == s.length()) {
            result.push_back(curr);
            return;
        }

        for (int x = i; x < s.length(); x++) {
            if (t[i][x]) {
                curr.push_back(s.substr(i, x-i+1));
                solve(s, x+1, curr, result, t);
                curr.pop_back();
            }
        }
    }

    vector<vector<string>> partition(string s) {
        int n = s.length();

        // blue print code
        vector<vector<bool>> t(n, vector<bool>(n, false));
        // t[i][j] = t/f - s[i...j] is palindrome or not

        // length 1 string is always palindrome
        for (int i = 0; i < n; i++) {
            t[i][i] = true;
        }

        // for length >= 2
        for (int L = 2; L <= n; L++) { // Length 
            for (int i = 0; i < n-L+1; i++) {
                int j = i+L-1;
                if (L == 2) { // for string with length 2
                    t[i][j] = (s[i] == s[j]); 
                } else { // for string with length > 2
                    t[i][j] = (s[i] == s[j]) && t[i+1][j-1];
                }
            }
        }

        vector<vector<string>> result;
        vector<string> curr;

        solve(s, 0, curr, result, t);

        return result;
    }
};