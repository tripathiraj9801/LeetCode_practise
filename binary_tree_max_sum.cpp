// Problem Link https://leetcode.com/problems/binary-tree-maximum-path-sum/description/

class Solution
{
public:
    int ans = 0;
    int solve(TreeNode *root)
    {
        if (root == NULL)
            return 0;

        int left = solve(root->right);
        int right = solve(root->left);

        int path = root->val;
        path = max(path, path + left);
        path = max(path, path + right);

        ans = max(ans, path);
        return max(root->val, root->val + max(left, right));
    }

    int maxPathSum(TreeNode *root)
    {
        ans = root->val;
        solve(root);
        return ans;
    }
};