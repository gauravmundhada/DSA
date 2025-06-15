// every point 2 options are there -> either plus lagao ya minus
// when there are options at every point -> think of recursion
// go with recursion first then memo it
// then tabulation and space optimization


class Solution {
public:
    int n;
    unordered_map<int, unordered_map<int, int>> dp;

    int helper(vector<int>& nums, int target, int i) {
        if (i == n) {
            return target == 0 ? 1 : 0;
        }

        if (dp[i].count(target)) return dp[i][target];

        int plus = helper(nums, target - nums[i], i + 1);
        int minus = helper(nums, target + nums[i], i + 1);

        return dp[i][target] = plus + minus;
    }

    int findTargetSumWays(vector<int>& nums, int target) {
        n = nums.size();
        return helper(nums, target, 0);
    }
};
