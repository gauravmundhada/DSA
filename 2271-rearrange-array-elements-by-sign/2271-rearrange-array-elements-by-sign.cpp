// Brute force
class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n = nums.size();

        vector<int> pos; // to store the positive elements
        vector<int> neg; // to store the negative elements
        vector<int> ans; // final output

        for (int i = 0; i < n; i++) {
            if (nums[i] < 0) neg.push_back(nums[i]);
            else pos.push_back(nums[i]);
        }

        // construct the final ans
        int p = 0, m = 0;
        for (int i = 0; i < n; i++) {
            if (i % 2 == 0) { // means positive no is to be placed
                ans.push_back(pos[p]);
                p++;
            } else {
                ans.push_back(neg[m]);
                m++;
            }
        }
        return ans;
    }
};