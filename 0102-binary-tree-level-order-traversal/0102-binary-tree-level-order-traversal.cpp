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
    vector<vector<int>> levelOrder(TreeNode* root) {
        queue<TreeNode*>q;
        vector<vector<int>>ans;

        if(root == nullptr) return ans;
        q.push(root);

        while(!q.empty()){
            int size = q.size();
            vector<int> level;

            for(int i=0 ; i<size; i++){
                TreeNode* visitedNode = q.front();
                q.pop();

                if(visitedNode->left != nullptr){
                    q.push(visitedNode->left);
                }

                 if(visitedNode->right != nullptr){
                    q.push(visitedNode->right);
                }

                level.push_back(visitedNode->val);
            }
            ans.push_back(level);
        }
return ans;

    }
};