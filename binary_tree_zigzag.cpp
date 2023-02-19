// Problem Link https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/description/

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

class Solution
{
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode *root)
    {
        vector<vector<int>> ans;
        if (!root)
            return ans;
        queue<TreeNode *> q;
        q.push(root);
        int i = 0;
        while (!q.empty())
        {
            int sz = q.size();
            vector<int> v;
            while (sz--)
            {
                TreeNode *f = q.front();
                v.push_back(q.front()->val);
                q.pop();
                if (f->left)
                    q.push(f->left);
                if (f->right)
                    q.push(f->right);
            }
            if (i++ % 2)
                reverse(v.begin(), v.end());
            ans.push_back(v);
        }
        return ans;
    }
    // };
    // class Solution
    // {
    // public:
    //     vector<vector<int>> zigzagLevelOrder(TreeNode *root)
    //     {
    //         vector<vector<int>> res;
    //         if (!root)
    //             return res;

    //         queue<TreeNode *> q;
    //         q.push(root);

    //         int level = 1;
    //         while (!q.empty())
    //         {
    //             vector<int> res1;
    //             int n = q.size();

    //             for (int i = 0; i < n; i++)
    //             {
    //                 TreeNode *temp = q.front();
    //                 q.pop();
    //                 res1.push_back(temp->val);
    //                 cout << temp->val << " ";
    //                 if (level % 2 == 0)
    //                 {
    //                     if (temp->left)
    //                         q.push(temp->left);
    //                     if (temp->right)
    //                         q.push(temp->right);
    //                 }
    //                 else
    //                 {
    //                     if (temp->right)
    //                         q.push(temp->right);
    //                     if (temp->left)
    //                         q.push(temp->left);
    //                 }
    //             }

    //             level++;
    //             res.push_back(res1);
    //         }
    //         return res;
    //     }
    // };