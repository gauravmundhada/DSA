class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int n = nums.size();
        sort(begin(nums), end(nums));

        for (int i = 0; i < n; i++) {
            if (i < n-1 && nums[i] != nums[i+1]) return nums[i];
            if (i == n-1) return nums[i];
            i++;
        }
        return -1;
    }
};