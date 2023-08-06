class TrieNode
{
    TrieNode *child[26];
    int end_count;

public:
    TrieNode()
    {
        for (int i = 0; i < 26; i++)
            child[i] = nullptr;
        end_count = 0;
    }

    TrieNode *get(char ch)
    {
        return child[ch - 'a'];
    }

    bool isContainChar(char ch)
    {
        return child[ch - 'a'] != nullptr;
    }

    void addNode(char ch, TrieNode *node)
    {
        child[ch - 'a'] = node;
    }

    void incrementEnd()
    {
        end_count++;
    }

    bool isEnd()
    {
        return end_count;
    }
};

class Solution
{
    TrieNode *trie;
    void add(string word)
    {
        TrieNode *cur = trie;
        for (int i = 0; i < word.size(); i++)
        {
            if (!cur->isContainChar(word[i]))
            {
                TrieNode *node = new TrieNode();
                cur->addNode(word[i], node);
            }
            cur = cur->get(word[i]);
        }
        cur->incrementEnd();
    }

    bool search(string word)
    {
        TrieNode *cur = trie;
        for (int i = 0; i < word.size(); i++)
        {
            if (!cur->isContainChar(word[i]))
            {
                return false;
            }
            cur = cur->get(word[i]);
        }
        return cur->isEnd();
    }

public:
    // A : given string to search
    // B : vector of available strings
    Solution()
    {
        trie = new TrieNode();
    }

    int wordBreak(string A, vector<string> &B)
    {
        for (auto &word : B)
        {
            add(word);
        }
        return helper(0, A);
    }

    int helper(int indx, string &s)
    {
        if (indx == s.size())
            return 1;
        TrieNode *curr = trie;
        for (int i = indx; i < s.size(); i++)
        {
            if (!curr->isContainChar(s[i]))
            {
                return false;
            }
            curr = curr->get(s[i]);
            if (curr->isEnd() && helper(i + 1, s))
            {
                return true;
            }
        }
        return false;
    }
};