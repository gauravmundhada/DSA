// Using hashmap
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();

        vector<int> freq(n+1, 0); // keep track of the numbers present

        for (int i = 0; i < n; i++) {
            freq[nums[i]]++; // mark the appearance
        }

        for (int f = 0; f <= n; f++) {
            if (freq[f] == 0) { // means number is not present
                return f;
            }
        }
        return -1; // no missing number found
    }
};