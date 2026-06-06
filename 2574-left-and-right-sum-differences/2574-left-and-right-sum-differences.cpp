class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        int n = nums.size();
        int total_sum = 0;
        int right_sum = 0;

        for (int i = 0; i < n; i++) {
            total_sum += nums[i];
        }

        vector<int> ans(n);
        for (int i = n-1; i >= 0; i--) {
            ans[i] = abs((total_sum - nums[i]) - right_sum);
            total_sum -= nums[i];
            right_sum += nums[i];
        }
        return ans;
    }
};