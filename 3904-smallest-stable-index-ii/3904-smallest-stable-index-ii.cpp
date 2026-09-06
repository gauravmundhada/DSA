// O(n) space
class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n = nums.size();
        int maxel = INT_MIN;
        vector<int> minel(n);
        int instability_score = k+1;

        for (int i = n-1; i >= 0; i--) {
            if (i == n-1) minel[i] = nums[i];
            else minel[i] = min(minel[i+1], nums[i]);
        }

        for (int i = 0; i < n; i++) {
            maxel = max(maxel, nums[i]);
            instability_score = maxel - minel[i];

            if (instability_score <= k)
                return i;
        }
        return -1;
    }
};