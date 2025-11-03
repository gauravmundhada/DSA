class Solution {
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        // Step 1: Create a graph.
        unordered_map<string, vector<string>> graph;

        for (auto& ticket : tickets) {
            string u = ticket[0];
            string v = ticket[1];
            graph[u].push_back(v); // Directed graph => u->v
        }
        
        // Sort neighbors in descending lexicographical order.
        for (auto& [key, neighbors] : graph) {
            sort(neighbors.rbegin(), neighbors.rend()); // Sort in descending order
        }

        // Step 2: Find Euler path.
        stack<string> st;
        vector<string> itinerary; // Euler path
        st.push("JFK"); // Start from "JFK"

        while (!st.empty()) {
            string curr = st.top();

            if (!graph[curr].empty()) {
                string nbr = graph[curr].back(); // Take the last (smallest lexicographically) neighbor
                graph[curr].pop_back();
                st.push(nbr);
            } else { // If no neighbors, add to Euler path and backtrack
                itinerary.push_back(curr);
                st.pop();
            }
        }

        reverse(itinerary.begin(), itinerary.end());
        return itinerary;
    }
};
