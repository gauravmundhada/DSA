class Solution {
public:
    string reverseWords(string s) {
        istringstream iss(s);

        vector<string> words;
        string word;

        while (iss >> word) {
            words.push_back(word);
        }

        string res;

        for (int i = words.size()-1; i >= 0; i--) {
            res += words[i];
            if (i > 0) {
                res += " ";
            }
        }
        return res;
    }
};