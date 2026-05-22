class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = 0, r = nums.size() - 1;

        while (l <= r) {
            int m = l + (r - l) / 2;

            if (nums[m] == target) return m;

            // Left half is sorted
            if (nums[l] <= nums[m]) {
                if (nums[l] <= target && target < nums[m]) { // {l,...., target,...., m}
                    r = m - 1;
                } else {
                    l = m + 1;
                }
            }
            // Right half is sorted
            else {
                if (nums[m] < target && target <= nums[r]) { // {m, ....., target, ...., r}
                    l = m + 1;
                } else {
                    r = m - 1;
                }
            }
        }
        return -1;
    }
};
