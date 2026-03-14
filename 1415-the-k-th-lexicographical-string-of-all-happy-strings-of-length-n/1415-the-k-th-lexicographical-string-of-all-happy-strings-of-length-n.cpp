class Solution {
public:
    string ans = "";
    int cnt = 0;
    void solve(int idx, string& temp, int n, int k) {
        if (idx == n) {
            cnt+=1;
            if (cnt == k) ans = temp;
            return;
        }

        for (char c : {'a', 'b', 'c'}) {
            if (temp.empty() || temp.back() != c) {
                temp.push_back(c);
                solve(idx+1, temp, n, k);
                temp.pop_back();
            }
        }
    }

    string getHappyString(int n, int k) {
        string temp = "";
        solve(0, temp, n, k);
        return ans;
    }
};