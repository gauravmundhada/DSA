class Solution {
public:
    vector<int> findAllPeople(int n, vector<vector<int>>& meetings, int firstPerson) {
        sort(meetings.begin(), meetings.end(),
             [](auto &a, auto &b) {
                 return a[2] < b[2];
             });

        vector<bool> knows(n, false);
        knows[0] = true;
        knows[firstPerson] = true;

        int i = 0;
        while (i < meetings.size()) {

            int time = meetings[i][2];

            unordered_map<int, vector<int>> adj;
            unordered_set<int> people;

            // collect all meetings at same time
            while (i < meetings.size() && meetings[i][2] == time) {
                int u = meetings[i][0];
                int v = meetings[i][1];

                adj[u].push_back(v);
                adj[v].push_back(u);

                people.insert(u);
                people.insert(v);

                i++;
            }

            // BFS only inside this time group
            queue<int> q;
            unordered_set<int> visited;

            for (int p : people) {
                if (knows[p]) {
                    q.push(p);
                    visited.insert(p);
                }
            }

            while (!q.empty()) {
                int curr = q.front();
                q.pop();

                for (int nei : adj[curr]) {
                    if (!visited.count(nei)) {
                        visited.insert(nei);
                        q.push(nei);
                        knows[nei] = true;
                    }
                }
            }
        }

        vector<int> result;
        for (int i = 0; i < n; i++) {
            if (knows[i])
                result.push_back(i);
        }

        return result;
    }
};