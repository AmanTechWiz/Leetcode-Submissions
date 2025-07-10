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
private:
    bool foundPathSum(TreeNode* root, int currSum) {
        if (!root) return false;

        currSum -= root->val;

        if (!root->left && !root->right) {
            return (currSum == 0);
        }

        return foundPathSum(root->left, currSum) || foundPathSum(root->right, currSum);
    }

public:
    bool hasPathSum(TreeNode* root, int targetSum) {
        return foundPathSum(root, targetSum);
    }
};