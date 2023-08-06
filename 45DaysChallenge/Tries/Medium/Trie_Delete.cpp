class Solution
{
public:
    void deleteKey(trie_node_t *root, char key[])
    {
        trie_node_t *curr = root;
        for (int i = 0; key[i] != '\0'; i++)
        {
            if (!curr->children[key[i] - 'a'])
                return;

            curr = curr->children[key[i] - 'a'];
        }
        curr->value = 0;
    }
};