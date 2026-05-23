class Solution {
public:
    int minJumps(vector<int>& arr) {
        int n = arr.size();

        unordered_map<int, vector<int>> mpp;

        for (int i = 0; i < n; i++) {
            mpp[arr[i]].push_back(i);
        }

        queue<int> q;
        vector<int> visited(n);
        visited[0] = 1;

        q.push(0); // source

        int len = 0;
        while (!q.empty()) {
            int sz = q.size();
            while (sz--) {
                int curIdx = q.front();
                q.pop();

                if (curIdx == n-1) 
                    return len;

                for (int jump : mpp[arr[curIdx]]) {
                    if (jump == curIdx) continue;
                    if (visited[jump] == 0) {
                        q.push(jump);
                        visited[jump] = 1;
                    } 
                }

                mpp[arr[curIdx]].clear();

                if (curIdx - 1 >= 0 && visited[curIdx-1] == 0) {
                    q.push(curIdx - 1);
                    visited[curIdx - 1] = 1;
                }

                if (curIdx + 1 < n && visited[curIdx+1] == 0) {
                    q.push(curIdx + 1);
                    visited[curIdx + 1] = 1;
                }
            }
            len++;
        }
        return -1;
    }
};