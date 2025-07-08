class Solution {
public:
    bool canDistribute(vector<int>& position, int m, int mid) {
        int count = 1;  
        int lastPos = position[0];

        for (int i = 1; i < position.size(); ++i) {
            if (position[i] - lastPos >= mid) {
                count++;
                lastPos = position[i];
            }
            if (count >= m) return true;  
        }

        return false;
    }


    int maxDistance(vector<int>& position, int m) {
        int n = position.size();
        sort(position.begin(), position.end());
        int l = 0; 
        int r = position[n-1] - position[0];
        int ans = 0;

        while (l <= r) {
            int mid = l + (r - l)/2;

            if (canDistribute(position, m, mid)) {
                ans = mid;
                l = mid + 1;   
            } else {
                r = mid - 1;
            }
        }
        return ans;
    }
};