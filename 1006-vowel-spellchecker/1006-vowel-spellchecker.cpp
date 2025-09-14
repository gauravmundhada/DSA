class Solution {
public:
    unordered_set<string> exactMatch; // for exact match
    unordered_map<string, string> capMap; // for capitalization
    unordered_map<string, string> vowelMap; // vowel error

    string vowelError(string str) {
        string res = "";
        for (char ch : str) {
            if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u') {
                res.push_back('*');
            } else {
                res.push_back(ch);
            }
        }
        return res;
    }

    string toLower(string str) {
        string res = ""; 
        for (char ch : str) {
            res.push_back(tolower(ch));
        }
        return res;
    }

    vector<string> spellchecker(vector<string>& wordlist, vector<string>& queries) {
        for (string &word : wordlist) {
            exactMatch.insert(word); 

            string lowerWord = toLower(word);
            if (capMap.find(lowerWord) == capMap.end()) {
                capMap[lowerWord] = word;
            }

            string vowelErrorStr = vowelError(lowerWord);
            if (vowelMap.find(vowelErrorStr) == vowelMap.end()) {
                vowelMap[vowelErrorStr] = word; 
            }
        }

        vector<string> result; // for output
        for (string &query : queries) {
            if (exactMatch.find(query) != exactMatch.end()) {
                result.push_back(query);
                continue;
            }

            string lowerQuery = toLower(query);
            string vowelErrorQuery = vowelError(lowerQuery);

            if (capMap.find(lowerQuery) != capMap.end()) {
                result.push_back(capMap[lowerQuery]);
                continue;
            }

            if (vowelMap.find(vowelErrorQuery) != vowelMap.end()) {
                result.push_back(vowelMap[vowelErrorQuery]);
                continue;
            }

            result.push_back("");
        }
        return result;
    }
};