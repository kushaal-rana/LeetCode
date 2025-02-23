// Time Complexity:
// Building the Trie: O(k * L), where k is the number of words and L is the average length of a word.
// DFS Traversal: O(m * n * 4^L), where m and n are the dimensions of the board, and L is the maximum length of a word.

// Space Complexity:
// Trie: O(k * L).
// DFS Recursion Stack: O(L).

class Solution
{
public:
    vector<string> result;
    int n, m;
    // Node struct for TRIE;
    struct TrieNode
    {
        bool endOfWord;
        string word;
        TrieNode *children[26];
    };
    TrieNode *getNode()
    {
        TrieNode *newNode = new TrieNode();
        newNode->endOfWord = false;
        newNode->word = "";
        for (int i = 0; i < 26; i++)
        {
            newNode->children[i] = NULL;
        }
        return newNode;
    }
    void insert(TrieNode *root, string &word)
    {
        TrieNode *crawler = root;
        // check for each character of word
        for (int i = 0; i < word.length(); i++)
        {
            char ch = word[i];
            if (crawler->children[ch - 'a'] == NULL)
            {                                            // check if letter is there or not
                crawler->children[ch - 'a'] = getNode(); // add the letter
            }
            crawler = crawler->children[ch - 'a']; // move the pointer to next letter
        }
        crawler->endOfWord = true;
        crawler->word = word;
    }
    vector<vector<int>> directions = {{-1, 0}, {0, 1}, {0, -1}, {1, 0}};
    void findWordsDFS(vector<vector<char>> &board, int i, int j, TrieNode *root)
    {
        if (i < 0 || i >= n || j < 0 || j >= m)
            return;
        char ch = board[i][j];
        if (board[i][j] == '$' || root->children[ch - 'a'] == NULL)
            return;
        root = root->children[ch - 'a'];
        if (root->endOfWord == true)
        {
            result.push_back(root->word);
            root->endOfWord = false; // Avoid Duplicates
        }
        char temp = board[i][j];
        board[i][j] = '$'; // marking visited
        for (vector<int> &dir : directions)
        {
            int newI = dir[0] + i;
            int newJ = dir[1] + j;
            findWordsDFS(board, newI, newJ, root);
        }
        board[i][j] = temp; // marking unvisited Now
    }
    vector<string> findWords(vector<vector<char>> &board, vector<string> &words)
    {
        n = board.size();
        m = board[0].size();
        // create root
        TrieNode *root = getNode();
        // insert words in trie
        for (string &word : words)
        {
            insert(root, word);
        }
        // traverse in the grid(just once) and find all the words in trie if present
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                char ch = board[i][j];
                if (root->children[ch - 'a'] != NULL)
                {
                    findWordsDFS(board, i, j, root);
                }
            }
        }
        return result;
    }
};