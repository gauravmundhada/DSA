class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size(); 
        if (n == 1) return 1;

        int i = 0, j = 1;

        while (j < n) {
            while (j < n && nums[i] == nums[j]) {
                j++;
            }

            if (j < n && i+1 < n) nums[i+1] = nums[j];
            i++;
        }  
        return i;
    }
};