class TrieNode
{
public:
    bool isEndOfWord = false;
    TrieNode *children[26];
};
class WordDictionary
{
public:
    TrieNode *getNode()
    {
        TrieNode *newNode = new TrieNode();
        for (int i = 0; i < 26; i++)
        {
            newNode->children[i] = NULL;
        }
        newNode->isEndOfWord = false;
        return newNode;
    }
    TrieNode *root;
    WordDictionary()
    {
        root = getNode();
    }

    void addWord(string word)
    {
        TrieNode *crawler = root;
        for (char &ch : word)
        {
            int idx = ch - 'a';
            if (crawler->children[idx] == NULL)
            {
                crawler->children[idx] = getNode();
            }
            crawler = crawler->children[idx];
        }
        crawler->isEndOfWord = true;
    }
    bool searchUtil(TrieNode *root, string word)
    {
        TrieNode *crawler = root;
        for (int i = 0; i < word.length(); i++)
        {
            int idx = word[i] - 'a';
            char ch = word[i];
            if (ch == '.')
            {
                for (int j = 0; j < 26; j++)
                {
                    if (crawler->children[j] != NULL)
                    { // checking for all char which are present in trie
                        if (searchUtil(crawler->children[j], word.substr(i + 1)) == true)
                            return true;
                    }
                }
                return false;
            }
            else if (crawler->children[idx] == NULL)
                return false;
            crawler = crawler->children[idx];
        }
        return (crawler->isEndOfWord == true);
    }
    bool search(string word)
    {
        return searchUtil(root, word);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */