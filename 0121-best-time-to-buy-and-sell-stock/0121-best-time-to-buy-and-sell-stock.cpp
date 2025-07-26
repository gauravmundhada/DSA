// Greedy approach
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();

        int buy_price = prices[0]; 
        int maxP = 0;
        
        for (int i = 1; i < n; i++) {
            if (prices[i] <= buy_price) { // aur saste mein mil rha maal
                buy_price = prices[i];
            } else {
                maxP = max(maxP, prices[i] - buy_price);
            }
        }
        return maxP;
    }
};