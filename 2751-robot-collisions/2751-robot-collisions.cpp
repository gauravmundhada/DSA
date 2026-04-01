class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) {
        int n = positions.size();

        // Step 1: Store indices and sort by position
        vector<int> idx(n);
        for (int i = 0; i < n; i++) {
            idx[i] = i;
        }

        sort(idx.begin(), idx.end(), [&](int a, int b) {
            return positions[a] < positions[b];
        });

        stack<int> stk; // stores indices

        // Step 2: Process robots in sorted order
        for (int i : idx) {
            // Only handle collisions when current is 'L'
            while (!stk.empty() && 
                   directions[stk.top()] == 'R' && 
                   directions[i] == 'L') {

                int j = stk.top();

                // Case 1: Equal health → both destroyed
                if (healths[j] == healths[i]) {
                    stk.pop();
                    healths[j] = 0;
                    healths[i] = 0;
                    break;
                }
                // Case 2: Stack robot stronger
                else if (healths[j] > healths[i]) {
                    healths[j] -= 1;
                    healths[i] = 0;
                    break;
                }
                // Case 3: Current robot stronger
                else {
                    healths[i] -= 1;
                    healths[j] = 0;
                    stk.pop();
                }
            }

            // If still alive, push to stack
            if (healths[i] > 0) {
                stk.push(i);
            }
        }

        // Step 3: Collect survivors in original order
        vector<int> result;
        for (int i = 0; i < n; i++) {
            if (healths[i] > 0) {
                result.push_back(healths[i]);
            }
        }

        return result;
    }
};