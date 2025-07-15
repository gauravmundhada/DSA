class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int total_sum = (n * (n+1))/2; // Sum of n natural numbers

        int current_sum = nums[0]; // sum of all elements in array
        for (int i = 1; i < n; i++) {
            current_sum += nums[i];
        }

        return total_sum - current_sum;
    }
};