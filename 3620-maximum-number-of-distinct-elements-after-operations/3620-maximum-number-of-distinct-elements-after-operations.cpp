class Solution {
public:
    int maxDistinctElements(vector<int>& nums, int k) {
        int n = nums.size();

        sort(nums.begin(), nums.end());

        int count = 0, prev = INT_MIN;

        for (int num : nums) {
            int cur = min(max(num-k, prev+1), num+k); // min val possible
            if (cur > prev) {
                count++;
                prev = cur;
            }
        }
        return count;
    }
};