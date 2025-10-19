public class Solution {
    public string ReverseWords(string s) {
        string[] splits = s.Split(' ', StringSplitOptions.RemoveEmptyEntries);

        string ans = "";

        for (int i = splits.Length - 1; i >= 0; i--) {
            ans += splits[i];
            if (i != 0) ans += " ";
        }

        return ans;
    }
}
