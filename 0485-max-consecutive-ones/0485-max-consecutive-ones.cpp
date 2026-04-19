class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int n = nums.size();
        long long cnt = 0;
        long long ans = 0;

        int i = 0;

        while (i < n) {
            while (i < n && nums[i] == 1) {
                cnt += 1;
                i++;
            }
            ans = max(ans, cnt);
            cnt = 0;
            i++;
        }
        return (int)ans;
    }
};