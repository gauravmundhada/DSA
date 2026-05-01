class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        int n = nums.size();

        int total_sum = 0;
        int ans = 0;
        int curAns = 0;

        // calculate for F(0)
        for (int i = 0; i < n; i++) {
            curAns += (i * nums[i]);
            total_sum += nums[i];
        }

        ans = curAns;

        for (int i = n-1; i >= 1; i--) {
            curAns = curAns - (nums[i]*(n-1)) + (total_sum - nums[i]);
            if (curAns > ans) ans = curAns;
        }
        return ans;
    }
};