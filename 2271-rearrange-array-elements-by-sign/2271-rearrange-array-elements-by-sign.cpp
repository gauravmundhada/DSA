// Brute force
class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n = nums.size();

        vector<int> pos; // to store the positive elements
        vector<int> neg; // to store the negative elements
        vector<int> ans(n); // final output

        for (int i = 0; i < n; i++) {
            if (nums[i] < 0) neg.push_back(nums[i]);
            else pos.push_back(nums[i]);
        }

        // construct the final ans
        for (int i = 0; i < n/2; i++) {
            ans[2*i]   = pos[i];
            ans[2*i+1] = neg[i];
        }
        return ans;
    }
};