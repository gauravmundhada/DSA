class Solution {
public:
    int findGCD(vector<int>& nums) {
        int smallest = *min_element(nums.begin(), nums.end());
        int largest = *max_element(nums.begin(), nums.end());

        for (int i = smallest; i >= 2; i--) {
            if (smallest % i == 0 && largest % i == 0)
                return i;
        }
        return 1;
    }
};