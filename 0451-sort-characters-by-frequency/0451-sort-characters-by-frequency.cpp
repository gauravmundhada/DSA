typedef pair<int, char> P;
class Solution {
public:
    string frequencySort(string s) {
        int n = s.length();

        // auto cmp = [](P &a, P &b) {
        //     return a.second < b.second;
        // };

        unordered_map<char, int> mpp; // store the freq of chars
        priority_queue<P, vector<P>> pq; // store the char in asc order and desc in freq

        for (char c : s) {
            mpp[c]++;
        }

        for (auto &entry : mpp) {
            pq.push({entry.second, entry.first});
        }

        string res = "";
        while (!pq.empty()) {
            P p = pq.top();
            pq.pop();
            res.append(p.first, p.second);
        }
        return res;
    }
};