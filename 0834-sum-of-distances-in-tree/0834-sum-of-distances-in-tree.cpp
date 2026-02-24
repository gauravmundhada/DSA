class Solution {
public:
    vector<vector<int>> adj;
    long long root_result; // the answer for root node
    vector<int> no_of_nodes_in_Subtree;
    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
        adj.resize(n);

        for (vector<int> e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        
        no_of_nodes_in_Subtree.resize(n);

        dfs(0, -1, 0);

        vector<int> result(n, 0);
        result[0] = root_result;

        DFS(0, -1, result, n);
        return result;
    }

    void DFS(int parent_node, int prev_node, vector<int>& result, int n) {
        for (auto u : adj[parent_node]) {
            if (u == prev_node) continue;
            result[u] = result[parent_node] - no_of_nodes_in_Subtree[u] + (n-no_of_nodes_in_Subtree[u]);
            DFS(u, parent_node, result, n);
        }
    }

    void dfs(int node, int prev, int cur_depth) {
        no_of_nodes_in_Subtree[node] = 1;
        root_result += cur_depth;
        for (auto u : adj[node]) {
            if (u == prev)
                continue;

            dfs(u, node, cur_depth+1);
            no_of_nodes_in_Subtree[node] += no_of_nodes_in_Subtree[u];   
        }
    }
};

/*
one to track all path sums for all subtrees (note that all leaves will have path sum of 0, since they have no subtrees and thus no children edges); the other state array tracks the size of each subtree (note that all leaves will have a size of 1, which is itself). 

n = 6, edges = [[0,1],[0,2],[2,3],[2,4],[2,5]]
Output: [8,12,6,10,10,10]


*/