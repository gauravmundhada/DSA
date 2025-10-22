// difference array technique
class Solution {
public:
    int maxFrequency(vector<int>& nums, int k, int numOperations) {
        int n = nums.size();

        int maxV = *max_element(nums.begin(), nums.end());
        maxV += k;

        map<int, int> diff;

        unordered_map<int, int> freq;

        for (int i = 0; i < n; i++) {
            freq[nums[i]]++;

            int l = max(nums[i]-k, 0);
            int r = min(maxV, nums[i]+k);

            diff[l]++;
            diff[r+1]--;

            diff[nums[i]] += 0;
        }

        int res = 1;
        int cumSum = 0;

        for (auto it = diff.begin(); it != diff.end(); it++) {
            int target = it->first;
            it->second += cumSum;
            

            int targetFreq     = freq[target];
            int needConversion = it->second - targetFreq;

            int maxConversionPoss = min(numOperations, needConversion);

            int tempAns = maxConversionPoss + targetFreq;
            res = max(res, tempAns);

            cumSum = it->second;
        }
        return res;
    }
};