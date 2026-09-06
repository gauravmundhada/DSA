/*
idea is to match characters rather than complete string
*/

public class Solution {
    private int Solve(int i, int j, int[,] dp, string t, string s) {
        if (j == t.Length) 
            return 1;

        if (i == s.Length) 
            return 0;

        if (dp[i, j] != -1)
            return dp[i, j];

        if (s[i] == t[j]) {
            dp[i, j] = Solve(i+1, j+1, dp, t, s) + Solve(i+1, j, dp, t, s);
        }
        else {
            dp[i, j] = Solve(i+1, j, dp, t, s);
        }

        return dp[i, j];
    }

    public int NumDistinct(string s, string t) {
        int n = s.Length, m = t.Length;

        int[,] dp = new int[n+1, m+1];

        for (int i = 0; i <= n; i++) {
            for (int j = 0; j <= m; j++) {
                dp[i, j] = -1;
            }
        }

        return Solve(0, 0, dp, t, s);
    }
}