class Solution {
public:

    bool canFinishAllTasks(vector<vector<int>>& tasks, int energy) {

        for (auto& task : tasks) {

            int actual = task[0];
            int minimum = task[1];

            if (energy < minimum)
                return false;

            energy -= actual;
        }

        return true;
    }

    int minimumEffort(vector<vector<int>>& tasks) {

        // sort by (minimum - actual) descending
        sort(tasks.begin(), tasks.end(),
            [](vector<int>& a, vector<int>& b) {

                return (a[1] - a[0]) >
                       (b[1] - b[0]);
            });

        int l = 1;
        int r = 1e9;
        int ans = r;

        while (l <= r) {

            int m = l + (r - l) / 2;

            if (canFinishAllTasks(tasks, m)) {

                ans = m;
                r = m - 1;
            }
            else {
                l = m + 1;
            }
        }

        return ans;
    }
};