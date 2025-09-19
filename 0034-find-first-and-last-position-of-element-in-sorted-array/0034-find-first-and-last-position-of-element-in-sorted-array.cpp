class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int l = 0, r = nums.size()-1;

        while (l <= r) {
            int m = l + (r-l)/2;

            if (nums[m] == target) {
                // first check for first occ
                int first = m;
                int last  = m;
                while (first > 0 && nums[m] == nums[first-1]) {
                    first--;
                }

                while (last < nums.size()-1 && nums[m] == nums[last+1]) {
                    last++;
                }
                return {first, last};
            }

            if (nums[m] > target) {
                r = m-1;
            } else {
                l = m+1;
            }
        }
        return {-1, -1};
    }
};