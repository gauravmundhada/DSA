class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int n = nums.size();

        unordered_map<int, int> mp;

        for (int i = 0; i < n; i++) {
            mp[nums[i]]++;
        }

        int ans = -1;
        for (auto& entry : mp) {
            if (entry.second == 1) {
                ans = entry.first;
                break;
            }
        }
        return ans;
    }
};