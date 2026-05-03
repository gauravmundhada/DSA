// simple simulation as said in the problem
class Solution {
public:
    int rotatedDigits(int n) {
        unordered_map<int, int> rotated =   {
            {0, 0},
            {1, 1},
            {8, 8},
            {2, 5},
            {5, 2},
            {6, 9},
            {9, 6}
        };
        int cnt = 0;
        for (int i = 2; i <= n; i++) {
            if (isGood(i, rotated)) 
                cnt++;
        }
        return cnt;
    }

    bool isGood(int x, unordered_map<int, int>& rotated) {
        string s;
        int org = x;
        while (x) {
            int digit = x%10;
            if (rotated.find(digit) == rotated.end()) return false; 
            int rotated_digit = rotated[digit];
            s += to_string(rotated_digit);
            x /= 10;
        }

        reverse(s.begin(), s.end());

        return org != stoi(s);
    }
};