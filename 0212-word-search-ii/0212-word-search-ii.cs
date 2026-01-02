public class Solution {
    public class TrieNode {
        public bool IsEndOfWord { get; set; }
        public TrieNode[] children { get; set; }
        public string word { get;set; }

        public TrieNode() {
            children = new TrieNode[26];
            IsEndOfWord = false;
            word = "";
        }
    }

    private TrieNode root;

    public Solution() {
        root = new TrieNode();
    }

    public void Insert(string word) {
        TrieNode crawler = root;

        for(int i = 0; i < word.Length; i++) {
            int idx = word[i] - 'a';
            if(crawler.children[idx] == null)
                crawler.children[idx] = new TrieNode();

            crawler = crawler.children[idx];
        }
        crawler.IsEndOfWord = true;
        crawler.word = word;
    }

    int[][] directions = new int[][]
    {
        new int[] {1, 0},
        new int[] {-1, 0},
        new int[] {0, 1},
        new int[] {0, -1}
    };

    public void FindWords(char[][] board, int row, int col, TrieNode node) {
        int m = board.Length;
        int n = board[0].Length;

        if(row < 0 || row >= m || col < 0 || col >= n) return;
        if(board[row][col] == '$' || node.children[board[row][col] - 'a'] == null) return;

        node = node.children[board[row][col] - 'a'];

        if(node.IsEndOfWord) {
            res.Add(node.word);
            node.IsEndOfWord = false; // Mark as visited
        }

        char temp = board[row][col];
        board[row][col] = '$'; // Mark as visited

        foreach(var dir in directions) {
            int newRow = row + dir[0];
            int newCol = col + dir[1];
            FindWords(board, newRow, newCol, node);
        }

        board[row][col] = temp; // Backtrack
    }

    List<string> res = new List<string>();

    public IList<string> FindWords(char[][] board, string[] words) {
        int m = board.Length;
        int n = board[0].Length;

        foreach(string word in words) {
            Insert(word);
        }

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                FindWords(board, i, j, root);
            }
        }
        return res;
    }
}
