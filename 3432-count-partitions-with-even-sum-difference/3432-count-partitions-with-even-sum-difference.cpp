class Solution {
public:
    int countPartitions(vector<int>& nums) {
        int n = nums.size();

        int sum = 0;

        for (int num : nums) {
            sum += num;
        }

        if (sum % 2 != 0) return 0;

        return n-1;
    }
};


// how can i get even
// even - even
// odd - odd
// if total sum is odd then no partition