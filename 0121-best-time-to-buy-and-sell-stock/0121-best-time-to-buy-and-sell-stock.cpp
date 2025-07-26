// we will find the greatest value to the right for each element and then profit update krege whichever max we get
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<int> largestInRHS(n);
        largestInRHS[n-1] = prices[n-1]; // last element k right mein kuch nahi h

        // populate the vector
        for (int i = n-2; i >= 0; i--) {
            largestInRHS[i] = max(prices[i], largestInRHS[i+1]);
        }

        // find the profits and update the max
        int maxP = INT_MIN;
        for (int i = 0; i < n; i++) {
            int profit = largestInRHS[i] - prices[i];
            maxP = max(maxP, profit);
        }
        return maxP;
    }
};