class Solution {
public:
    vector<vector<int>> adj;
    vector<long long> down;   // max path sum going downward
    vector<long long> up;     // max path sum coming from parent side
    vector<int> price;
    long long res = 0;

    long long maxOutput(int n, vector<vector<int>>& edges, vector<int>& priceInput) {
        price = priceInput;

        adj.resize(n);
        down.resize(n);
        up.resize(n);

        // Build adjacency list
        for (auto &e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        // Step 1: Compute downward paths
        dfs1(0, -1);

        // Step 2: Compute upward paths (rerooting)
        up[0] = price[0];  // root initialization
        dfs2(0, -1);

        // Step 3: Compute result
        for (int i = 0; i < n; i++) {
            long long bestPath = max(down[i], up[i]);
            res = max(res, bestPath - price[i]);
        }

        return res;
    }

private:

    // First DFS: compute maximum downward path
    void dfs1(int node, int parent) {
        down[node] = price[node];

        for (int child : adj[node]) {
            if (child == parent) continue;

            dfs1(child, node);

            down[node] = max(down[node],
                             price[node] + down[child]);
        }
    }

    // Second DFS: compute upward contributions
    void dfs2(int node, int parent) {

        long long max1 = 0, max2 = 0;

        // Find top two maximum downward values among children
        for (int child : adj[node]) {
            if (child == parent) continue;

            long long val = down[child];

            if (val >= max1) {
                max2 = max1;
                max1 = val;
            } else if (val > max2) {
                max2 = val;
            }
        }

        for (int child : adj[node]) {
            if (child == parent) continue;

            long long use = (down[child] == max1) ? max2 : max1;

            // propagate rerooted value
            up[child] = price[child] + max(
                            up[node],               // go upward
                            price[node] + use       // go via sibling
                        );

            dfs2(child, node);
        }
    }
};