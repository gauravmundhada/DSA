class Solution {
public:
    const int MOD = 1e9+7;
    int assignEdgeWeights(vector<vector<int>>& edges) {
        int n = edges.size();
        // create a tree
        unordered_map<int, vector<int>> tree;

        for (auto& edge : edges) {
            int u = edge[0];
            int v = edge[1];

            tree[u].push_back(v);
            tree[v].push_back(u); // undirected
        }

        // find the max depth
        // root is (1)
        int depth = 0;
        queue<int> q;
        vector<int> visited(n+2, 0); // as it is undirected we need to keep track of visited nodes
        q.push(1);
        visited[1] = 1;

        while (!q.empty()) {
            int sz = q.size();
            while (sz--) {
                int cur = q.front();
                q.pop();
                for (int v : tree[cur]) {
                    if (visited[v] == 0) {
                        visited[v] = 1;
                        q.push(v);
                    }
                }
            }
            depth++;
        }
        long long ans = 1;

        for (int i = 0; i < depth - 2; i++) {
            ans = (ans * 2) % MOD;
        }

        return (int)ans;
    }
};

/*
Step 1 : create a tree
Observations : 
I feel the no of ways will depend on the depth 
and if it does I will simply calculate the depth and then use the derived formula that's it

check the notebook how I derived formula

no of ways = 2^depth
*/