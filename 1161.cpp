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
    int maxLevelSum(TreeNode* root) 
    {
        int level = 1;
        int maxSum = -INT_MAX;
        int minLevel = 1;
        queue<TreeNode*> q;

        q.push(root);
        while(!q.empty())
        {
            int size = q.size();
            int tempSum = 0;
            while(size != 0)
            {
                TreeNode* tempNode = q.front();
                q.pop();
                if(tempNode->left != nullptr)
                {
                    q.push(tempNode->left);
                }
                if(tempNode->right != nullptr)
                {
                    q.push(tempNode->right);
                }
                tempSum += tempNode->val;
                size--;
            }
            if(tempSum > maxSum)   //不取等号，相等的值取层数小的
            {
                maxSum = tempSum;
                minLevel = level;
            }
            level++;
        }
        return minLevel;
    }
};