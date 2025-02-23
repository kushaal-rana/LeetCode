// TC: O(N)
class TrieNode
{
public:
    bool endOfWord = false;
    TrieNode *children[26];
};
class Trie
{
public:
    TrieNode *root;
    Trie()
    {
        root = getNode();
    }
    TrieNode *getNode()
    {
        TrieNode *newNode = new TrieNode();
        newNode->endOfWord = false;
        for (int i = 0; i < 26; i++)
        {
            newNode->children[i] = NULL;
        }
        return newNode;
    }
    void insert(string word)
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
        crawler->endOfWord = true;
    }

    bool search(string word)
    {
        TrieNode *crawler = root;
        for (char &ch : word)
        {
            int idx = ch - 'a';
            if (crawler->children[idx] != NULL)
            {
                crawler = crawler->children[idx];
            }
            else
                return false;
        }
        // if(crawler!=NULL && crawler->endOfWord==true) return true;
        if (crawler->endOfWord == true)
            return true;
        return false;
    }

    bool startsWith(string prefix)
    {
        TrieNode *crawler = root;
        for (char &ch : prefix)
        {
            int idx = ch - 'a';
            if (crawler->children[idx] == NULL)
            {
                return false;
            }
            crawler = crawler->children[idx];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */