class Solution {
private:
    bool canShip(vector<int>& weights, int days, int m) {
        int d = 1;
        int w = 0;

        for (int i = 0; i < weights.size(); i++) {
            if (w + weights[i] <= m) {
                w += weights[i];
            } else {
                d++;
                w = weights[i];
            }
        }
        return d <= days;
    }

public:
    int shipWithinDays(vector<int>& weights, int days) {
        int n = weights.size();
        int ans;
        int l = *max_element(weights.begin(), weights.end()); // min capacity to load all the packages
        int r = 0;
        for (int w : weights) {
            r += w; // max capacity to load all the packages
        }

        while (l <= r) {
            int m = l + (r - l)/2;

            if (canShip(weights, days, m)) {
                ans = m;
                r = m-1;
            } else {
                l = m+1;
            }
        }
        return ans;
    }
};