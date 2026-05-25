class Solution {
public:

    bool canReach(string s,
                  int minJump,
                  int maxJump) {

        int n = s.size();

        vector<bool> dp(n, false);

        dp[0] = true;

        int reachable = 0;

        for (int i = 1; i < n; i++) {

            // include new element entering window
            if (i - minJump >= 0 &&
                dp[i - minJump]) {

                reachable++;
            }

            // remove old element leaving window
            if (i - maxJump - 1 >= 0 &&
                dp[i - maxJump - 1]) {

                reachable--;
            }

            dp[i] =
                (s[i] == '0' && reachable > 0);
        }

        return dp[n - 1];
    }
};