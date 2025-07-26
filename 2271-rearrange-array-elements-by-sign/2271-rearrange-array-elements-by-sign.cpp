// Single pass solution
class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n = nums.size();

        vector<int> ans(n); // final output vector
        int p = 0, m = 1;
        for (int i = 0; i < n; i++) {
            if (nums[i] > 0) { // place at the positive - even index
                ans[p] = nums[i];
                p += 2;
            } else {
                ans[m] = nums[i];
                m += 2;
            }
        }        
        return ans;
    }
};