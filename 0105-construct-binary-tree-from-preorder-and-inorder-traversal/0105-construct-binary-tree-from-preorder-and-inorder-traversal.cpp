/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int data;
 *     TreeNode *left;
 *     TreeNode *right;
 *      TreeNode(int val) : data(val) , left(nullptr) , right(nullptr) {}
 * };
 **/

class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int,int>inMap;

        for(int i=0; i<inorder.size();i++){
            inMap[inorder[i]] = i;
        }

        TreeNode* root = buildtree(preorder,inorder,0,preorder.size()-1,0,inorder.size()-1,inMap);
        return root;
    }

    TreeNode* buildtree(vector<int>& preorder,vector<int>& inorder,int preStart,int preEnd,int inStart,int inEnd,unordered_map<int,int>&inMap){
        
        if(preStart>preEnd || inStart>inEnd) return nullptr;
        
        TreeNode* root = new TreeNode(preorder[preStart]);
        int inRoot = inMap[root->val];
        int numsLeft = inRoot - inStart;

        root->left =  buildtree(preorder,inorder,preStart+1,preStart+numsLeft,inStart,inRoot-1,inMap);
        root->right = buildtree(preorder,inorder,preStart+numsLeft+1,preEnd,inRoot+1,inEnd,inMap);

        return root;
    }
};