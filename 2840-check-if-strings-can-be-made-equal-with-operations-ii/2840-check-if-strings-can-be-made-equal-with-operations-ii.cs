public class Solution {
    public bool CheckStrings(string s1, string s2) {
        int n = s1.Length;

        int[] even = new int[26];
        int[] odd  = new int[26];

        for (int i = 0; i < n; i++) {
            if (i%2 == 0) {
                even[s1[i] - 'a']++;
                even[s2[i] - 'a']--;
            }
            else {
                odd[s1[i] - 'a']++;
                odd[s2[i] - 'a']--;
            }
        }

        for (int i = 0; i < 26; i++) {
            if (even[i] != 0 || odd[i] != 0)
                return false;
        }
        return true;
    }
}