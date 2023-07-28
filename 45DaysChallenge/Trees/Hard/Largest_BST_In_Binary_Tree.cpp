
class Solution
{

    Info checkLargestBST(Node *root)
    {
        // nullptr gives valid always so max
        if (!root)
            return Info(0, INT_MAX, INT_MIN);

        Info left = checkLargestBST(root->left);
        Info right = checkLargestBST(root->right);

        if (left.mx < root->data && root->data < right.mn)
        {
            return Info(left.size + right.size + 1, min(root->data, left.mn), max(root->data, right.mx));
        }
        return Info(max(left.size, right.size), INT_MIN, INT_MAX);
    }

public:
    /*You are required to complete this method */
    // Return the size of the largest sub-tree which is also a BST
    int largestBst(Node *root)
    {
        return checkLargestBST(root).size;
    }
};