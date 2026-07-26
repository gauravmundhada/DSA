class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        int n = nums.size();

        return max((nums[n-1] * nums[n-2] * nums[n-3]), (nums[0] * nums[1] * nums[n-1]));
    }
};

/*
2 cases can give us the answer
i)  product of the 3 maximum numbers -> works if all numbers are positive or the abs(negative numbers) < positive
ii) since we have to choose 3 numbers we can also choose 2 negative and 1 positive -> to chose 2 negative we will take the smallest value because it will give us the max ans after cancelling out negative.
*/