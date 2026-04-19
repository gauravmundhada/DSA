class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();
        int cnt1 = 0, cnt2 = 0;
        int candidate1 = 0, candidate2 = 1; // Initialize to different values

        for (int num : nums) {
            if (num == candidate1) {
                cnt1++;
            } else if (num == candidate2) {
                cnt2++;
            } else if (cnt1 == 0) {
                candidate1 = num;
                cnt1 = 1;
            } else if (cnt2 == 0) {
                candidate2 = num;
                cnt2 = 1;
            } else {
                cnt1--;
                cnt2--;
            }
        }

        cnt1 = cnt2 = 0;
        for (int num : nums) {
            if (num == candidate1) cnt1++;
            else if (num == candidate2) cnt2++;
        }

        vector<int> result;
        if (cnt1 > n / 3) result.push_back(candidate1);
        if (cnt2 > n / 3) result.push_back(candidate2);

        return result;
    }
};
