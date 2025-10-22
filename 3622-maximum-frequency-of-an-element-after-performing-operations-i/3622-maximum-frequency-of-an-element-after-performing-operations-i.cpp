// difference array technique
class Solution {
public:
    int maxFrequency(vector<int>& nums, int k, int numOperations) {
        int n = nums.size();

        int maxV = *max_element(nums.begin(), nums.end());
        maxV += k;

        vector<int> diff(maxV+2, 0);

        unordered_map<int, int> freq;

        for (int i = 0; i < n; i++) {
            freq[nums[i]]++;

            int l = max(nums[i]-k, 0);
            int r = min(maxV, nums[i]+k);

            diff[l]++;
            diff[r+1]--;
        }

        int res = 1;

        for (int i = 0; i < diff.size(); i++) {
            diff[i] += (i > 0 ? diff[i-1] : 0) ;

            int targetFreq     = freq[i];
            int needConversion = diff[i] - targetFreq;

            int maxConversionPoss = min(numOperations, needConversion);

            int tempAns = maxConversionPoss + targetFreq;
            res = max(res, tempAns);
        }
        return res;
    }
};