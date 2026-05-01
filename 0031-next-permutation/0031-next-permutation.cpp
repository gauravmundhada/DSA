class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();

        int idx_to_be_swapped = -1;

        // Step 1
        for (int i = n-1; i >= 1; i--) {
            if (nums[i] > nums[i-1]) {
                idx_to_be_swapped = i-1;
                break;
            }
        }
         
        // desc order case
        if (idx_to_be_swapped == -1) {
            reverse(nums.begin(), nums.end());
            return;
        }

        for (int i = n-1; i > idx_to_be_swapped; i--) {
            if (nums[i] > nums[idx_to_be_swapped]) {
                swap(nums[idx_to_be_swapped], nums[i]);
                break;
            }
        }

        reverse(nums.begin()+idx_to_be_swapped+1, nums.end());
    }
};