class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int firstOcc = getFirstOccurence(nums, target, 0, nums.size()-1);
        int lastOcc = getLastOccurence(nums, target, 0, nums.size()-1);

        return {firstOcc, lastOcc};
    }

    int getFirstOccurence(vector<int>& nums, int target, int l, int r) {

        while (l <= r) {
            int m = l + (r-l)/2;

            if (nums[m] == target) {
                if (m > 0 && nums[m-1] == target) {
                    return getFirstOccurence(nums, target, l, m-1);
                } else {
                    return m;
                }
            }

            if (nums[m] > target) {
                r = m-1;
            } else {
                l = m + 1;
            }
        }
        return -1;
    }

    int getLastOccurence(vector<int>& nums, int target, int l, int r) {

        while (l <= r) {
            int m = l + (r-l)/2;

            if (nums[m] == target) {
                if (m < nums.size()-1 && nums[m+1] == target) {
                    return getLastOccurence(nums, target, m+1, r);
                } else {
                    return m;
                }
            }

            if (nums[m] > target) {
                r = m-1;
            } else {
                l = m + 1;
            }
        }
        return -1;
    }
};