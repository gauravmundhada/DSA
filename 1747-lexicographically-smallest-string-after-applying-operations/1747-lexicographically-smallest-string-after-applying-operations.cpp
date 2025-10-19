class Solution {
public:
    string findLexSmallestString(string s, int a, int b) {
        int n = s.length();
        unordered_set<string> visited; // keep track of visited string

        string ans = s; // answer to return

        // bfs approach
        queue<string> q;
        q.push(s);
        visited.insert(s);

        while (!q.empty()) {
            string cur = q.front();
            q.pop();

            if (cur < ans) ans = cur;

            string op1 = cur;
            // operation 1
            for (int i = 1; i < n; i+=2) {
                op1[i] = ((op1[i]-'0'+a)%10) + '0';
            }
            if (!visited.count(op1)) {
                q.push(op1);
                visited.insert(op1);
            }

            // operation 2
            string rotate = cur.substr(cur.size()-b)+cur.substr(0, cur.size()-b);
            if (!visited.count(rotate)) {
                q.push(rotate);
                visited.insert(rotate);
            }
        }
        return ans;
    }
};
// ek point b strings repeat hogi - there are finite possiblities
// string s se chalu krege and try to generate all possible strings