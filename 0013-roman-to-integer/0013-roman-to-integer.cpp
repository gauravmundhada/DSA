class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char, int> mpp{
            {'I', 1},
            {'V', 5},
            {'X', 10},
            {'L', 50},
            {'C', 100},
            {'D', 500},
            {'M', 1000}
        };

        int res = 0;

        for (int i = 0; i < s.size(); i++) {
            char ch  = s[i];
            int cur  = mpp[s[i]];
            int next = (i+1 < s.size()) ? mpp[s[i+1]] : 0;

            if (next > cur) {
                res -= cur;
            } else {
                res += cur;
            }
        }
        return res;
    }
};