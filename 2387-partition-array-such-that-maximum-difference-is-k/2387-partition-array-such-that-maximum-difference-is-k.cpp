class Solution {
public:
    int partitionArray(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end()); // Sort the array
        int ans = 1; // At least one subsequence is needed
        int start = nums[0]; // Starting element of current subsequence

        for (int i = 1; i < nums.size(); ++i) {
            // If current number cannot be included in current subsequence
            if (nums[i] - start > k) {
                ans++;           // Start a new subsequence
                start = nums[i]; // Update the new start
            }
        }
        return ans;
    }
};
