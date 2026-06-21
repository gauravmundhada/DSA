class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        // counting sort
        int maxE = costs[0];
        int n = costs.size();

        for (int c : costs) {
            if (maxE < c)
                maxE = c;
        }

        vector<int> freq(maxE+1, 0);

        // store freq
        for (int c : costs) {
            freq[c]++;
        }

        for (int i = 1; i <= maxE; i++) {
            freq[i] += freq[i - 1];
        }

        vector<int> sortedArr(n);
        for (int i = n-1; i >= 0; i--) {
            int v = costs[i];
            sortedArr[freq[v]-1] = v;
            freq[v]--;
        }

        int ans = 0;
        for (int i = 0; i < n; i++) {
            if (coins < sortedArr[i])
                return ans;

            coins -= sortedArr[i];
            ans++;
        }
        return ans;
    }
};