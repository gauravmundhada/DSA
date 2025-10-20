class Solution {
public:
    string expand(int i, int j, string s) {
        while (i >= 0 && j < s.size() && s[i] == s[j]) {
            i--;
            j++;
        }
        return s.substr(i+1, j-i-1);
    }

    string longestPalindrome(string s) {
        string ans;

        for (int i = 0; i < s.size(); i++) {
            string odd = expand(i, i, s); // for odd length of string (center ek hi rhega)
            if (odd.size() > ans.size()) {
                ans = odd;
            }

            string even = expand(i, i+1, s); // for even length of string
            if (even.size() > ans.size()) {
                ans = even;
            }
        }   
        return ans;
    }
};