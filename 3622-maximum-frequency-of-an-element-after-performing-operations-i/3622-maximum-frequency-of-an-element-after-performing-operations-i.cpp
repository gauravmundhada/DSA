class Solution {
public:
    int maxFrequency(vector<int>& nums, int k, int numOperations) {
        int maxEl = *max_element(nums.begin(), nums.end());

        vector<int> freq(maxEl+k+1, 0);

        for (int num : nums) {
            freq[num]++;
        }

        for (int i = 1; i < freq.size(); i++) {
            freq[i] += freq[i-1];
        }

        int res = 0;
        for (int target = *min_element(nums.begin(), nums.end()); target <= maxEl; target++) {
            if (freq[target] == 0) continue;

            int leftBound  = target-k;
            int rightBound = target+k;

            int totalCount  = freq[rightBound] - (leftBound > 0 ? freq[leftBound-1] : 0);
            int targetCount = freq[target] - (target > 0 ? freq[target-1] : 0);  

            int needConversion = totalCount - targetCount;

            int maxPossible = targetCount +  min(needConversion, numOperations);

            res = max(res, maxPossible);
        }
        return res;
    }
};