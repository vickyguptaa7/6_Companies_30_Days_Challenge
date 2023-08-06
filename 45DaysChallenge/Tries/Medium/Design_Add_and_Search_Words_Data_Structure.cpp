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

    int getEndCount()
    {
        return end_count;
    }
};

class WordDictionary
{
    TrieNode *trie;

public:
    WordDictionary()
    {
        trie = new TrieNode();
    }

    void addWord(string word)
    {
        TrieNode *curr = trie;
        for (int i = 0; i < word.size(); i++)
        {
            if (!curr->isContainChar(word[i]))
            {
                TrieNode *node = new TrieNode();
                curr->addNode(word[i], node);
                curr = node;
            }
            else
            {
                curr = curr->get(word[i]);
            }
        }
        curr->incrementEnd();
    }
    bool searchHelper(int indx, string word, TrieNode *curr)
    {
        for (int i = indx; i < word.size(); i++)
        {
            if (word[i] == '.')
            {
                for (int j = 0; j < 26; j++)
                {
                    if (curr->isContainChar(j + 'a'))
                    {
                        if (searchHelper(i + 1, word, curr->get(j + 'a')))
                        {
                            return true;
                        }
                    }
                }
                return false;
            }
            else if (!curr->isContainChar(word[i]))
            {
                return false;
            }
            else
            {
                curr = curr->get(word[i]);
            }
        }
        return curr->getEndCount() > 0;
    }
    bool search(string word)
    {
        TrieNode *curr = trie;
        return searchHelper(0, word, curr);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */