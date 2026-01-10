class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        // step 1 := set mein daldo wordList
        unordered_set<string> st(wordList.begin(), wordList.end()); 

        // if end word is not in wordlist then no path possible
        // immediately return 0
        if (!st.count(endWord)) return 0;

        // step 2 := BFS
        queue<string> q;
        //unordered_set<string> visited; // to keep track of visited states
        q.push(beginWord);
        //visited.insert(beginWord);
        int ans = 1;
        while (!q.empty()) {
            int size = q.size();

            while (size--) {
                string currWord = q.front();
                q.pop();

                if (currWord == endWord) return ans;

                for (int i = 0; i < currWord.length(); i++) {
                    char ch = currWord[i];
                    for (int j = 0; j < 26; j++) {
                        currWord[i] = 'a' + j;

                        if (st.count(currWord)) {
                            q.push(currWord);
                            st.erase(currWord);
                            //visited.insert(currWord);
                        }
                    }
                    currWord[i] = ch; // retain the original state
                }
            }
            ans++;
        }
        return 0;
    }
};


/*
Observations =: you have to go from start to end
return the number of words in the shortest transformation sequence - indicates BFS

wordlist ko set mein dal dege
ab main start word k characters change kruga and check kruga mere set mein h kya - O(26) * O(len(word))
if present then usko queue mein dal duga
*/