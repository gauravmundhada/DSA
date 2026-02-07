class Solution {
public:
    int minimumDeletions(string s) {
        int n = s.length();

        stack<int> st;
        int deletions = 0;

        for (int i = 0; i < n; i++) {
            if (s[i] == 'a') {
                if (st.size() > 0 && s[st.top()] == 'b') {
                    st.pop();
                    deletions++;
                }
            } else {
                st.push(i);
            }
        }

        return deletions;
    }
};