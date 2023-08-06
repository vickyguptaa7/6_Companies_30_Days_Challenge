void insert(struct TrieNode *root, string key)
{
    // code here
    TrieNode *curr = root;
    for (int i = 0; i < key.size(); i++)
    {
        if (!curr->children[key[i] - 'a'])
        {
            TrieNode *node = new TrieNode();
            curr->children[key[i] - 'a'] = node;
        }
        curr = curr->children[key[i] - 'a'];
    }
    curr->isLeaf = true;
}

// Function to use TRIE data structure and search the given string.
bool search(struct TrieNode *root, string key)
{
    TrieNode *curr = root;
    for (int i = 0; i < key.size(); i++)
    {
        if (!curr->children[key[i] - 'a'])
        {
            return false;
        }
        curr = curr->children[key[i] - 'a'];
    }
    return curr->isLeaf;
}