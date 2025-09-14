class Solution {
private:
    bool isPossibleToMakeBouquet(vector<int>& bloomDay, int m, int k, int mid) {
        int b = 0;  // count of bouquet prepared;
        int count = 0;
        for (int i = 0; i < bloomDay.size(); i++) {
            if (bloomDay[i] <= mid) {
                count++;
                if (count == k) {
                    b++;
                    count = 0;
                }
            } else {
                count = 0;
            }
        }

        return b >= m;
    }

public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        int n = bloomDay.size();
        int ans;

        if ((1LL * m * k) > n) return -1; // required flowers greater than flowers available

        int l = *min_element(bloomDay.begin(), bloomDay.end()); // min day to bloom any flower
        int r = *max_element(bloomDay.begin(), bloomDay.end()); // max day to bloom any flower

        while (l <= r) {
            int mid = l + (r - l)/2;

            if (isPossibleToMakeBouquet(bloomDay, m, k, mid)) {
                ans = mid;
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        return ans;
    }
};