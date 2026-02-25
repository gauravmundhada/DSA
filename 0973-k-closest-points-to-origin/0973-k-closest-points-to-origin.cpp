class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {

        priority_queue<pair<long long, vector<int>>> pq;

        for (auto &p : points) {
            long long x = p[0];
            long long y = p[1];
            long long dist = x*x + y*y;

            pq.push({dist, p});      // always push

            if (pq.size() > k)       // keep only k elements
                pq.pop();
        }

        vector<vector<int>> result;

        while (!pq.empty()) {
            result.push_back(pq.top().second);
            pq.pop();
        }

        return result;
    }
};