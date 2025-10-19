// with stack
class Solution {
public:
    string removeOuterParentheses(string s) {
        // stack<char> st;
        string ans;
        int counter = 0;

        for (char ch : s) {
            if (ch == '(') {
                if (counter > 0) {
                    ans += '(';
                }
                //st.push('(');
                counter++;
            } else {
                if (counter > 1) {
                    ans += ')';
                }
                //st.pop();
                counter--;
            }
        }
        return ans;
    }
};