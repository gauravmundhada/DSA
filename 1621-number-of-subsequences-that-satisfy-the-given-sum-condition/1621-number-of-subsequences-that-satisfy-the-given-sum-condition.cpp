class Solution {
public:
    const int MOD = 1e9+7;
    int numSubseq(vector<int>& nums, int target) {
        int n = nums.size();
        int result = 0;

        sort(nums.begin(), nums.end());

        vector<int> power(n);

        power[0] = 1;
        for (int i = 1; i < n; i++) {
            power[i] = (power[i-1]*2)%MOD;
        }

        int r = n-1, l = 0;

        while (l <= r) {
            if (nums[r] + nums[l] > target) {
                r--; 
                continue;
            }
                    
            result = (result + power[r-l]) % MOD;
            l++;
        }
        return result;
    }
};