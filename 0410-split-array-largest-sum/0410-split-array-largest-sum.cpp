class Solution {
private:    
    bool isPossibleToSplit(vector<int>& nums, int k, int m) {
        int count = 1; // subarray count
        int sum   = 0;

        for (int i = 0; i < nums.size(); i++) {
            if (sum + nums[i] <= m) {
                sum += nums[i];
            } else {
                count++;
                sum = nums[i];
            }
        }

        return count <= k; // as we need k splits
    }

public:
    int splitArray(vector<int>& nums, int k) {
        int n = nums.size();
        int ans;
        int l = *max_element(nums.begin(), nums.end()); // min sum possible
        int r = 0;
        for (int num : nums) {
            r += num; // max sum possible
        }

        while (l <= r) {
            int m = l + (r - l)/2;

            if (isPossibleToSplit(nums, k, m)) {
                ans = m;
                r = m-1;
            } else {
                l = m+1;
            }
        }
        return ans;
    }
};