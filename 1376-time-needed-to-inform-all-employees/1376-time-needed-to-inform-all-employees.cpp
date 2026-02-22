class Solution {
public:
    void dfs(int idx, unordered_map<int, vector<int>>& mpp, int curSum, int& ans, vector<int>& informTime) {
        if (mpp.find(idx) == mpp.end()) { // this means end of the path - no more employees to inform
            ans = max(ans, curSum);
            return;
        }

        curSum += informTime[idx];
        for (int emp : mpp[idx]) {
            dfs(emp, mpp, curSum, ans, informTime);
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
        dfs(headID, mpp, 0, ans, informTime);
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