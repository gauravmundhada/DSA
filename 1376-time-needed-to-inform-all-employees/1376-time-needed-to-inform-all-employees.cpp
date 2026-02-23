class Solution {
public:
    void bfs(int headID, unordered_map<int, vector<int>>& mpp, int curSum, int& ans, vector<int>& informTime) {
        queue<pair<int, int>> q; // {node, time_to_reach_that_node}
        q.push({headID, 0});

        while (!q.empty()) {
            pair<int, int> temp = q.front();
            q.pop();
            int cur_emp = temp.first;
            int cur_time = temp.second;

            ans = max(ans, cur_time);

            for (int& emp : mpp[cur_emp]) {
                q.push({emp, cur_time+informTime[cur_emp]});
            }
        }
    }

    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        unordered_map<int, vector<int>> mpp;

        for (int i = 0; i < n; i++) {
            if (i == headID) continue;
            int emp = i;
            int mng = manager[i];

            mpp[mng].push_back(emp);
        }
        int ans = 0;
        bfs(headID, mpp, 0, ans, informTime);
        return ans;
    }
};

/*
0->1, 2.                      
1->3, 4
2->5, 6
3->7, 8, 
4->9, 10
5->11, 12
6->13, 14


                   0
               /      \
              1        2
             / \      / \
            3   4    5    6
           / \  / \  / \  / \
          7  8 9 10 11 12  13 14
*/