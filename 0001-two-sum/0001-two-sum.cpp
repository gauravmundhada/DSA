class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        vector<int> ans(2);

        unordered_map<int, int> mpp;

        for (int i = 0; i < n; i++) {
            int req = target - nums[i];
            if (mpp.find(req) != mpp.end()) {
                ans[0] = mpp[req];
                ans[1] = i;
                break;
            }
            mpp[nums[i]] = i;
        }
        return ans;
    }
};