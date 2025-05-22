/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int data;
 *     TreeNode *left;
 *     TreeNode *right;
 *      TreeNode(int val) : data(val) , left(nullptr) , right(nullptr) {}
 * };
 **/

class Codec {
public:

    string serialize(TreeNode* root) {
        if(!root) return "";

        stringstream ss;
        queue<TreeNode*>q;
        q.push(root);

        while(!q.empty()){
            TreeNode* node = q.front();
            q.pop();

            if(node == nullptr){
                ss << "#,";
            }else{
                ss << node->val << ",";
                q.push(node->left);
                q.push(node->right);
            }
        }
        return ss.str();
    }

    TreeNode* deserialize(string data) {
        if(data.empty()) return nullptr;
        stringstream s(data);
        string str;
        getline(s,str,',');

        TreeNode* root = new TreeNode(stoi(str));
        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()){
            TreeNode* node = q.front();
            q.pop();

            getline(s,str,',');

            if(str != "#"){
                
             TreeNode* leftnode = new TreeNode(stoi(str));
             node->left = leftnode;
             q.push(leftnode);
            }

            getline(s,str,',');
            if(str != "#"){
            TreeNode* rightnode = new TreeNode(stoi(str));
             node->right = rightnode;
             q.push(rightnode);
            }
        }
        return root;
    }
};


/*
* Your Codec object will be instantiated and called as such:
* Codec* ser = new Codec();
* Codec* deser = new Codec();
* string tree = ser->serialize(root);
* TreeNode* ans = deser->deserialize(tree);
* return ans;
*/