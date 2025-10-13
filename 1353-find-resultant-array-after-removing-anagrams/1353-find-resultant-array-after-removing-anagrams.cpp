class Solution {
public:
    bool isAnagram(string str1, string str2) {
        if (str1.length() != str2.length()) return false;
        vector<int> freq(26);

        for (char ch : str1) {
            int idx = ch - 'a';
            freq[idx]++;
        }

        for (char ch : str2) {
            int idx = ch - 'a';
            if (freq[idx] == 0) return false;
            freq[idx]--;
        }
        return true;
    }

    vector<string> removeAnagrams(vector<string>& words) {
        int n = words.size();
        vector<string> result;
        result.push_back(words[0]);
        for (int i = 1; i < n; i++) {
            if (isAnagram(words[i-1], words[i])) {
                continue;
            } else {
                result.push_back(words[i]);
            }
        }
        return result;
    }
};