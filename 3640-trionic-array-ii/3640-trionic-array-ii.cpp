class Solution {
public:
    int n;
    typedef long long ll;
    vector<vector<ll>> memo;
    ll solve(vector<int>& nums, int i, int trend) {
        if (i == n) {
            if (trend == 3) {
                return 0;
            }
            else {
                return LONG_MIN/2;
            }
        }

        if (memo[i][trend] != LONG_MIN) {
            return memo[i][trend];
        }

        // recursive cases
        ll take = LONG_MIN/2;
        ll skip = LONG_MIN/2;

        if (trend == 0) {
            skip = solve(nums, i+1, trend);
        }

        if (trend == 3) {
            take = nums[i];
        }

        if (i+1 < n) {
            int curr = nums[i];
            int next = nums[i+1];

            if (trend == 0 && next > curr) {
                take = max(take, curr + solve(nums, i+1, 1));
            } else if (trend == 1) {
                if (next > curr) {
                    take = max(take, curr + solve(nums, i+1, 1));
                } else if (next < curr) {
                    take = max(take, curr + solve(nums, i+1, 2));
                }
            } else if (trend == 2) {
                if (next < curr) {
                    take = max(take, curr + solve(nums, i+1, 2));
                } else if (next > curr) {
                    take = max(take, curr + solve(nums, i+1, 3));
                }
            } else if (trend == 3 && next > curr) {
                take = max(take, curr + solve(nums, i+1, 3));
            }
        }
        return memo[i][trend] = max(take, skip);
    }

    long long maxSumTrionic(vector<int>& nums) {
        n = nums.size();
        int trend = 0;
        memo.assign(n+1, vector<ll>(4, LONG_MIN));
        return solve(nums, 0, trend);
    }
};