class Solution {
public:
    string rankTeams(vector<string>& votes) {

        int n = votes[0].size();

        vector<vector<int>> rank(26, vector<int>(n, 0));

        // count votes
        for (string& vote : votes) {

            for (int pos = 0; pos < n; pos++) {

                char team = vote[pos];

                rank[team - 'A'][pos]++;
            }
        }

        vector<char> teams(votes[0].begin(), votes[0].end());

        sort(teams.begin(), teams.end(),
            [&](char a, char b) {

                for (int i = 0; i < n; i++) {

                    if (rank[a - 'A'][i] != rank[b - 'A'][i]) {

                        return rank[a - 'A'][i] > rank[b - 'A'][i];
                    }
                }

                return a < b;
            });

        return string(teams.begin(), teams.end());
    }
};