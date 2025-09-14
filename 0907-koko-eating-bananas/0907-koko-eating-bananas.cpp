class Solution {
private:
    bool canEatAll(vector<int>& piles, int h, int m) {
        long long timeRequired = 0;

        for (int i = 0; i < piles.size(); i++) {
            timeRequired += (piles[i] + m - 1) / m;;
        }

        return timeRequired <= h;
    }


public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int n = piles.size();
        int ans;

        sort(piles.begin(), piles.end());

        int l = 1; // min speed
        int r = piles[n-1]; // max speed

        while (l <= r) {
            int m = l + (r - l)/2;

            if (canEatAll(piles, h, m)) {
                ans = m;
                r = m - 1;
            } else {
                l = m + 1;
            }
        }
        return ans;
    }
};