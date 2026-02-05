class Solution {
public:
    vector<int> constructTransformedArray(vector<int>& nums) {
        int n = (int)nums.size();
        vector<int> result(n);

        for (int i = 0; i < n; i++) {
            int move = nums[i];

            if (move == 0) {
                result[i] = nums[i];
            } else {
                int j = (i + move) % n;
                if (j < 0) j += n;   // handle negative modulo
                result[i] = nums[j];
            }
        }
        return result;
    }
};
