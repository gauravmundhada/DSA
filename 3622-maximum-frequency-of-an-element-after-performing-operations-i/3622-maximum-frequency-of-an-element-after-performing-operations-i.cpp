class Solution {
public:
    int maxFrequency(vector<int>& nums, int k, int numOperations) {
        sort(nums.begin(), nums.end());

        int ans = 0;
        unordered_map<int, int> numCount;

        for (const int num: nums) {
            ++numCount[num];
        }

        for (int i = nums.front(); i <= nums.back(); i++) {
            int l = lower_bound(nums.begin(), nums.end(), i - k) - nums.begin();
            int r = upper_bound(nums.begin(), nums.end(), i + k) - nums.begin();

            int tempAns = min(r - l, (numCount.count(i) ? numCount[i] : 0) + numOperations);
            ans = max(ans, tempAns);
        }

        return ans;
    }
};