// Approach 1: Brute Force
//  TC: O(N*M)
class Solution
{
public:
    int prefixCount(vector<string> &words, string pref)
    {
        int count = 0;
        for (string &word : words)
        { // O(N*M) where m is pref len
            if (word.find(pref) == 0)
                count++; // find pref at index 0
            // if(word.substr(0,pref.size())==pref) count++;
        }
        return count;
    }
};
// Approach 2: Using Trie
//  TC: O(N*L + M)
class TrieNode
{
public:
    TrieNode *children[26];
    int count;
    int endOfWord;
    TrieNode()
    {
        for (int i = 0; i < 26; i++)
        {
            children[i] = NULL;
        }
        endOfWord = false;
        count = 0; // number of prefix ending at this node
    }
};

class PrefixTree
{
private:
    TrieNode *root;

public:
    PrefixTree()
    {
        root = new TrieNode();
    }

    void insert(string &word)
    { // O(L)
        TrieNode *crawl = root;
        for (char &ch : word)
        {
            int idx = ch - 'a';
            if (crawl->children[idx] == NULL)
            {
                crawl->children[idx] = new TrieNode();
            }
            crawl = crawl->children[idx];
            crawl->count++; // count increased for prefix ending at this character node
        }
        crawl->endOfWord = true;
    }

    int searchPrefixCount(string &pref)
    {
        TrieNode *crawler = root;
        for (char &ch : pref)
        {
            int idx = ch - 'a';
            if (crawler->children[idx] == NULL)
            {
                return 0; // no word is having this as prefix
            }
            crawler = crawler->children[idx];
        }
        return crawler->count; // count of Prefix ending at last character of the pref wala Node;
    }
};
class Solution
{
public:
    int prefixCount(vector<string> &words, string pref)
    {
        PrefixTree tree;
        // O(N*L)
        for (string &word : words)
        {                      // O(N)
            tree.insert(word); // O(L)
        }
        // O(M)
        return tree.searchPrefixCount(pref);
        // TC: O(N*L + M)
    }
};