class Solution {
public:
    int minimumCost(vector<int>& cost) {
        int n = cost.size();
        int ans = 0;
        sort(cost.begin(), cost.end());
        for (int i = n-1; i >= 0; i-=3) {
            ans += cost[i] + ((i-1>=0) ? cost[i-1] : 0);
        }
        return ans;
    }
};

/*
cost = [6,5,7,9,2,2]
[2,2,5,6,7,9]
*/