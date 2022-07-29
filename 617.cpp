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
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) 
    {
        if(root1 == nullptr && root2 == nullptr)
        {
            return nullptr;
        }

        //下面有三种情况，依次讨论
        //1. root1空，root2不空
        if(root1 == nullptr && root2 != nullptr)
        {
            return new TreeNode(root2->val, mergeTrees(nullptr, root2->left), 
            mergeTrees(nullptr, root2->right));
        }
        //2. root1不空，root2空
        else if(root1 != nullptr && root2 == nullptr)
        {
            return new TreeNode(root1->val, mergeTrees(root1->left, nullptr), 
            mergeTrees(root1->right, nullptr));
        }
        //3. 两个都非空
        else
        {
            return new TreeNode(root1->val + root2->val, mergeTrees(root1->left, root2->left),
            mergeTrees(root1->right, root2->right));
        }
    }
};