class Solution {
public:
    int minimumCost(vector<int>& nums) {
        int n = nums.size();

        int ans = nums[0];


        int element2 = 51;
        int element3 = 51;
        for (int i = 1; i < n; i++) {
            if (nums[i] < element2) {
                element3 = element2;
                element2 = nums[i];
            } else if (nums[i] < element3) {
                element3 = nums[i];
            }
        }

        return ans + element2 + element3;
    }
};