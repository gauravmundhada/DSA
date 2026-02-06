class Solution {
public:
    int minRemoval(vector<int>& nums, int k) {
        int n = nums.size();

        sort(nums.begin(), nums.end()); // 1, 2, 5

        int i = 0, j = 0;
        //int ans = 0;
        int maxWindow=0;

        for (; j < n; j++) {
            while ((long long)nums[j] > (long long)nums[i] * k) i++; // shrink from left

            maxWindow = max(maxWindow, j - i + 1);
        }

        return n - maxWindow;
    }
};