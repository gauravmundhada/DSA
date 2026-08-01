class Solution {
public:
    int solve(vector<int>& nums, int left, int right) {
        // Only one number left
        if (left == right)
            return nums[left];

        // Pick left
        int pickLeft = nums[left] - solve(nums, left + 1, right);

        // Pick right
        int pickRight = nums[right] - solve(nums, left, right - 1);

        return max(pickLeft, pickRight);
    }

    bool predictTheWinner(vector<int>& nums) {
        return solve(nums, 0, nums.size() - 1) >= 0;
    }
};