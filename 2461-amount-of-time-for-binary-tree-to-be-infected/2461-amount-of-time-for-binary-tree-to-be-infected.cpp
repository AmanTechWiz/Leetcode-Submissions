class Solution {
public:
    int amountOfTime(TreeNode* root, int start) {
        unordered_map<TreeNode*, TreeNode*> parent;
        queue<TreeNode*> q;
        q.push(root);
        TreeNode* startnode = nullptr;

        // getting parent map and finding start node
        while (!q.empty()) {
            TreeNode* node = q.front();
            q.pop();

            if (node->val == start) startnode = node;

            if (node->left) {
                parent[node->left] = node;
                q.push(node->left);
            }

            if (node->right) {
                parent[node->right] = node;
                q.push(node->right);
            }
        }

        unordered_set<TreeNode*> visited;
        q.push(startnode);
        visited.insert(startnode);
        int burnCount = 0;

        while (!q.empty()) {
            int size = q.size();
            bool status = false;

            for (int i = 0; i < size; i++) {
                TreeNode* nodehere = q.front();
                q.pop();

                if (nodehere->left && visited.find(nodehere->left) == visited.end()) {
                    visited.insert(nodehere->left);
                    q.push(nodehere->left);
                    status = true;
                }

                if (nodehere->right && visited.find(nodehere->right) == visited.end()) {
                    visited.insert(nodehere->right);
                    q.push(nodehere->right);
                    status = true;
                }

                if (parent.find(nodehere) != parent.end() &&
                    visited.find(parent[nodehere]) == visited.end()) {
                    visited.insert(parent[nodehere]);
                    q.push(parent[nodehere]);
                    status = true;
                }
            }

            if (status) burnCount++;
        }

        return burnCount;
    }
};
