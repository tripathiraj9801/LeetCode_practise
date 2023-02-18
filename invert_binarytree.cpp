// Problem Link https://leetcode.com/problems/invert-binary-tree/description/
class Solution
{
public:
    TreeNode *invertTree(TreeNode *root)
    {
        if (!root)
        {
            return root;
        }
        TreeNode *left = root->left;
        TreeNode *right = root->right;
        root->left = invertTree(right);
        root->right = invertTree(left);
        return root;
    }
};