// simple simulation as said in the problem
class Solution {
public:
    int rotatedDigits(int n) {
        int cnt = 0;
        for (int i = 1; i <= n; i++) {
            if (isGood(i)) 
                cnt++;
        }
        return cnt;
    }

    bool isGood(int x) {
        bool isGood = false;
        while (x) {
            int digit = x%10;
            if (digit == 3 || digit == 7 || digit == 4) return false; // invalid case
            if (digit == 2 || digit == 5 || digit == 6 || digit == 9) isGood = true; // changes value
            x/=10;
        }
        return isGood;
    }
};