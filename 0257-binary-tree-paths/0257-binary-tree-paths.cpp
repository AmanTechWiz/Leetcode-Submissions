class Solution {
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> paths;
        string current;
        dfs(root, current, paths);
        return paths;
    }

private:
    void dfs(TreeNode* node, string& cur, vector<string>& paths) {
        if (!node) return;

        size_t len = cur.size();                
        if (!cur.empty()) cur += "->";
        cur += to_string(node->val);

        if (!node->left && !node->right) {
            paths.push_back(cur);
        } else {                                
            dfs(node->left,  cur, paths);
            dfs(node->right, cur, paths);
        }

        cur.erase(len);                         
    }
};
