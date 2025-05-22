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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        unordered_map<int,int>inMap;

        for(int i=0; i<inorder.size();i++){
            inMap[inorder[i]] = i;
        }

        TreeNode* root = buildtree(postorder,0,postorder.size()-1,inorder,0,inorder.size()-1,inMap);
        return root;
    }

    TreeNode* buildtree(vector<int>&postorder,int postStart, int postEnd,vector<int>&inorder,int inStart,int inEnd,unordered_map<int,int>&inMap){
        if(inStart > inEnd || postStart > postEnd){
            return nullptr;
        }

        TreeNode* root = new TreeNode(postorder[postEnd]);
        int inRoot = inMap[root->val];
        int numleft = inRoot - inStart;

        root->left=buildtree(postorder,postStart,postStart+numleft-1,inorder,inStart,inRoot-1,inMap);
        root->right=buildtree(postorder,postStart+numleft,postEnd-1,inorder,inRoot+1,inEnd,inMap);

        return root;
    }
};