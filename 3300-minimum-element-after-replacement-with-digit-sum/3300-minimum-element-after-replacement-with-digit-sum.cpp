class Solution {
public:
    int getSum(int x) {
        int sum = 0;

        while (x) {
            sum += x%10;
            x /= 10;
        }
        return sum;
    }

    int minElement(vector<int>& nums) {
        int n = nums.size();
        int ans = INT_MAX;
        for (int i = 0; i < n; i++) {
            ans = min(ans, getSum(nums[i]));
        }
        return ans;
    }
};