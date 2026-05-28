public class TrieNode
{
    public TrieNode[] children { get; set; }
    public int index { get; set; }

    public TrieNode()
    {
        children = new TrieNode[26];
        index = -1;
    }
}

public class Trie
{
    private TrieNode root;

    public Trie()
    {
        root = new TrieNode();
    }

    public void Insert(int x, string[] wordContainer)
    {
        string str = wordContainer[x];

        TrieNode crawler = root;

        // also maintain best answer at root
        if (crawler.index == -1 ||
            wordContainer[crawler.index].Length >
            wordContainer[x].Length)
        {
            crawler.index = x;
        }

        for (int i = str.Length - 1; i >= 0; i--)
        {
            int idx = str[i] - 'a';

            if (crawler.children[idx] == null)
            {
                crawler.children[idx] = new TrieNode();
            }

            crawler = crawler.children[idx];

            // update AFTER moving
            if (crawler.index == -1 ||
                wordContainer[crawler.index].Length >
                wordContainer[x].Length)
            {
                crawler.index = x;
            }
        }
    }

    public int Search(string word)
    {
        TrieNode crawler = root;

        for (int i = word.Length - 1; i >= 0; i--)
        {
            int idx = word[i] - 'a';

            if (crawler.children[idx] == null)
            {
                return crawler.index;
            }

            crawler = crawler.children[idx];
        }

        return crawler.index;
    }
}

public class Solution
{
    public int[] StringIndices(string[] wordContainer,
                               string[] wordsQuery)
    {
        Trie trie = new Trie();

        for (int i = 0; i < wordContainer.Length; i++)
        {
            trie.Insert(i, wordContainer);
        }

        int[] response = new int[wordsQuery.Length];

        for (int i = 0; i < wordsQuery.Length; i++)
        {
            response[i] = trie.Search(wordsQuery[i]);
        }

        return response;
    }
}