/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void inorderTraversal(TreeNode* root,vector<int>&inorder)
    {
        if(!root)
            return;
        inorderTraversal(root->left,inorder);
        inorder.push_back(root->val);
        inorderTraversal(root->right,inorder);
        
    }
    vector<int>mergeSortedList(vector<int>&arr1,vector<int>&arr2)
    {
        vector<int>combine;
        int it1=0,it2=0;
        int size1=arr1.size(),size2=arr2.size();
        while(it1<size1&&it2<size2)
        {
            if(arr1[it1]<arr2[it2])
                combine.push_back(arr1[it1++]);
            else
                combine.push_back(arr2[it2++]);
        }
        while(it1<size1)
            combine.push_back(arr1[it1++]);
        while(it2<size2)
            combine.push_back(arr2[it2++]);
        return combine;
    }
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        vector<int>inorder1,inorder2;
        inorderTraversal(root1,inorder1);
        inorderTraversal(root2,inorder2);
        return mergeSortedList(inorder1,inorder2);
    }
};