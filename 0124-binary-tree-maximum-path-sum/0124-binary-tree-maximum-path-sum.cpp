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
    int maxPathSum(TreeNode* root) {
            int maxsum = INT_MIN;
        sumfinder(maxsum,root);
        return maxsum;
    }

    int sumfinder(int &maxsum, TreeNode* root){
        if(root == nullptr){
            return 0;
        }

        int leftmax = max(0,sumfinder(maxsum,root->left));
        int rightmax = max(0,sumfinder(maxsum,root->right));

        maxsum = max(maxsum , leftmax + rightmax + root->val);    
        return root->val + max(leftmax , rightmax);

    }
};