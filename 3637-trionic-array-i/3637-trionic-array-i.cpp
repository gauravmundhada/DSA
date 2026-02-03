class Solution {
public:
    bool isTrionic(vector<int>& nums) {
        int n = nums.size();

        int i = 0;

        // increasing check
        while (i+1 < n && nums[i] < nums[i+1]) 
            i++;

        if (i == n-1 || i == 0)
            return false;

        // decreasing check
        while (i+1 < n && nums[i] > nums[i+1]) 
            i++;

        if (i == n-1) return false;

        // increasing check
        while (i+1 < n && nums[i] < nums[i+1])
            i++;

        return i == n-1;
    }
};