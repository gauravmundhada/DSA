class Solution {
public:
    int minimumDeletions(string word, int k) {
        int n = word.length();
        int ans = INT_MAX;

        vector<int> freq(26);


        for (char ch : word) {
            freq[ch - 'a']++;
        }

        int minFreq = freq[word[0] - 'a']; // suppose min freq is of first char

        for (int i = 0; i < 26; i++) {
            int deletions = 0;
            if (freq[i] == 0) continue;

            for (int j = 0; j < 26; j++) {
                if (freq[j] == 0) continue;

                if (freq[j] < freq[i]) {
                    deletions += freq[j];
                } else if (freq[j] > freq[i]+k) {
                    deletions += freq[j] - freq[i] - k;
                }
            }
            ans = min(ans, deletions);
        }
        return ans;
    }
};