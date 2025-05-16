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
      int diameterOfBinaryTree(TreeNode* root) {
        int diameter = 0;
        heightchecker(root,diameter);
        return diameter;   
    }

    int heightchecker(TreeNode* root, int &diameter){
        if(root == nullptr) return 0;

        int leftheight = heightchecker(root->left, diameter);
        int rightheight = heightchecker(root->right,diameter);

        diameter = max(diameter , leftheight + rightheight);

        return 1 + max(leftheight,rightheight);
    }
};