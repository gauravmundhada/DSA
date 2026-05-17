class Solution {
public:

    bool dfs(vector<int>& arr, int curr, vector<bool>& visited) {
        int n = arr.size();
        
        // out of bounds
        if (curr < 0 || curr >= n)
            return false;

        // already visited
        if (visited[curr])
            return false;

        // found zero
        if (arr[curr] == 0)
            return true;

        visited[curr] = true;

        return dfs(arr, curr + arr[curr], visited) ||
               dfs(arr, curr - arr[curr], visited);
    }

    bool canReach(vector<int>& arr, int start) {
        vector<bool> visited(arr.size(), false);
        return dfs(arr, start, visited);
    }
};