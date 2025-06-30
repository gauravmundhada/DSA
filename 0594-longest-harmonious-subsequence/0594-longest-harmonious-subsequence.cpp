class Solution {
public:
    int findLHS(vector<int>& nums) {
        unordered_map<int, int> mp; // {num, freq}
        int result = 0;

        for (int num : nums) {
            mp[num]++;
        }        

        for (int &num : nums) {
            int minN = num;
            int maxN = num + 1;

            if (mp.find(maxN) != mp.end()) {
                result = max(result, mp[minN] + mp[maxN]);
            }
        }
        return result;
    }
};