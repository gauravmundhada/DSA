public class TrieNode {
    public TrieNode[] children {get; set;}
    public int index {get; set;}

    public TrieNode() {
        children = new TrieNode[26];
        index = -1;
    }
}

public class Trie {
    private TrieNode root;

    public TrieNode GetTrieNode() {
        root = new TrieNode();
        return root;
    }

    public void Insert(int x, string[] wordContainer) {
        string str = wordContainer[x];
        int n = str.Length;
        TrieNode crawler = root;

        for (int i = n-1; i >= 0; i--) {
            int idx = str[i] - 'a';
            if (crawler.children[idx] == null) {
                crawler.children[idx] = new TrieNode();
            }
            crawler = crawler.children[idx];
            if (crawler.index == -1 || wordContainer[crawler.index].Length > wordContainer[x].Length) { // this means better answer
                crawler.index = x;
            }
        }
    }

    public int Search(string word, int smallestIdx) {
        int n = word.Length;
        TrieNode crawler = root;
        int ans = -1;

        for (int i = n-1; i >= 0; i--) {
            int idx = word[i] - 'a';
            // edge case what if string terminates from between like kuch chars same ho then nahi ho
            if (crawler.children[idx] == null) {
                // smallest string idx if first char not matches otherwise current index
                return (i == n-1) ? smallestIdx : ans;
            }
            crawler = crawler.children[idx];
            ans = crawler.index;
        }
        return ans;
    }
}



public class Solution {
    public int[] StringIndices(string[] wordContainer, string[] wordsQuery) {
        int n = wordContainer.Length;
        var trie = new Trie();
        var trieNode = trie.GetTrieNode();

        int smallest = int.MaxValue;
        int smallestIdx = -1;
        for (int i = 0; i < n; i++) {
            string word = wordContainer[i];
            if (smallest > word.Length) {
                smallestIdx = i;
                smallest = word.Length;
            }

            trie.Insert(i, wordContainer);
        }

        int m = wordsQuery.Length;
        int[] response = new int[m];

        for (int i = 0; i < m; i++) {
            response[i] = trie.Search(wordsQuery[i], smallestIdx);
        }
        return response;
    }
}