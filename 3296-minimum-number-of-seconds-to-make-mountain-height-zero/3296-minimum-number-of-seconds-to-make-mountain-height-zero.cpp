class Solution {
    typedef long long ll;
public:
    bool canMakeZero(int mountainHeight, vector<int>& workerTimes, ll m) {
        int totalRemoved = 0;

        for (int i = 0; i < workerTimes.size(); i++) {
            int t = workerTimes[i];
            ll k = m / t;

            ll removed =(ll)((-1 + sqrt(1.0 + 8.0 * k)) / 2);
            totalRemoved += removed;        
        }
        return totalRemoved >= mountainHeight;
    }

    long long minNumberOfSeconds(int mountainHeight, vector<int>& workerTimes) {
        int n = workerTimes.size();

        ll l = 1;
        ll maxTime = *max_element(workerTimes.begin(), workerTimes.end());
        ll r =  maxTime * ((ll)mountainHeight * (ll)(mountainHeight+1))/2;

        ll ans = 0;

        while (l <= r) {
            ll m = l + (r-l)/2;

            if (canMakeZero(mountainHeight, workerTimes, m)) {
                ans = m;
                r = m-1;
            }
            else {
                l = m+1;
            }
        }
        return ans;
    }
};

/*
minimize the maximum pattern dikh rha => bs on ans => ans ko max ki taraf push krna hai

formua redefined => workerTimes[i] + workerTimes[i] * 2 + ... + workerTimes[i] * x => workerTimes[i] * (x * (x+1))/2

in check function we need to see how many heights can each worker remove in time m?
using above formula 
for ex worker removes x height in time m

workerTimes[i] * (x * (x+1))/2 = m
let workerTimes[i] = t;

(x * (x+1))/2 = m/t;
let m/t = k;

(x * (x+1))/2 = k;

x^2 + x - 2k = 0 => quadratic equation
after solving positive root is x = (-1 + sqrt(1 + 8k)) / 2
so worker remove roughly x = floor((-1 + sqrt(1 + 8k)) / 2) heights
*/