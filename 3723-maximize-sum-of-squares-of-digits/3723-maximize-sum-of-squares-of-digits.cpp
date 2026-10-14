class Solution {
public:
    string maxSumOfSquares(int num, int sum) {
        string ans = "";

        while (sum) {
            if (sum > 9) {
                ans += '9';
                sum -= 9;
                num--;
            }
            else {
                ans += to_string(sum);
                sum = 0;
                num--;
            }
        }
        if (num < 0) return "";

        while (num > 0) {
            ans += '0';
            num--;
        }

        return ans;
    }
};