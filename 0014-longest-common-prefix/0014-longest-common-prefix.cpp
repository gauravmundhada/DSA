struct TrieNode {
    TrieNode* children[26];
    bool isEnd;

    TrieNode() {
        for (int i = 0; i < 26; i++) {
            children[i] = nullptr;
        }
        isEnd = false;
    }
};

class Trie {
private:
    TrieNode* root;

public:
    Trie() {
        root = new TrieNode();
    }

    void insert(string& word) {
        TrieNode* crawler = root;
        for (char ch : word) {
            int idx = ch - 'a';
            if (!crawler->children[idx]) {
                crawler->children[idx] = new TrieNode();
            }
            crawler = crawler->children[idx];
        }
        crawler->isEnd = true;
    }

    bool search(string &word) {
        TrieNode* crawler = root;
        for (char ch : word) {
            int idx = ch - 'a';
            if (!crawler->children[idx]) {
                return false;
            }
            crawler = crawler->children[idx];
        }
        return crawler->isEnd;
    }

    TrieNode* getRoot() {
        return root;
    }

    bool startsWith(string &prefix) {
        TrieNode* crawler = root;
        int i = 0, n = prefix.length();
        for (; i < n; i++) {
            int idx = prefix[i] - 'a';
            if (!crawler->children[idx]) {
                return false;
            }
            crawler = crawler->children[idx];
        }
        return i == n;
    }
};

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        Trie trie;
        string prefix;

        TrieNode* node = trie.getRoot();

        for (string& str : strs) {
            trie.insert(str);
        }

        while (true) {
            int count = 0;
            int nextIdx = -1;

            for (int i = 0; i < 26; i++) {
                if (node->children[i]) {
                    count++;
                    nextIdx = i;
                }
            }
            if (count != 1 || node->isEnd) break;

            prefix += ('a' + nextIdx);
            node = node->children[nextIdx];
        }
        return prefix;
    }
};