class Solution {
public:
    const int MOD = 1e9+7;
    typedef long long LL;
    int countTrapezoids(vector<vector<int>>& points) {
        int n = points.size();
        LL ans = 0;

        unordered_map<int, int> mpp; // store no of x points for a certain y point
        for (vector<int>& point : points) {
            int y = point[1];
            mpp[y]++; // increase the count for no of x point
        }

        LL count = 0; // no of lines seen till now
        for (auto& entry : mpp) {
            int a = entry.second; //no_of_points

            LL lines_count = 1LL * a * (a-1)/2; // no of lines possible from the no of points (aC2)

            ans += count * lines_count;
            count += lines_count;             
        }
        return ans%MOD;
    }
};