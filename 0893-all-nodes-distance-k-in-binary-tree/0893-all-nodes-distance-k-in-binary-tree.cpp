class Solution {
   public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode*, TreeNode*> parent;
        queue<TreeNode*> q;
        q.push(root);

        // first run for getting parent

        while (!q.empty()) {
            TreeNode* node = q.front();
            q.pop();

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
        vector<int> result;

        q.push(target);
        visited.insert(target);

        int currdist = 0;

        // second run to get the distance

        while (!q.empty()) {
            if (currdist == k) {
                while (!q.empty()) {
                    result.push_back(q.front()->val);
                    q.pop();
                }
                return result;
            }

            int size = q.size();

            for (int i = 0; i < size; i++) {
                TreeNode* node = q.front();
                q.pop();

                if (node->left && visited.find(node->left) == visited.end()) {
                    q.push(node->left);
                    visited.insert(node->left);
                }

                if (node->right && visited.find(node->right) == visited.end()) {
                    q.push(node->right);
                    visited.insert(node->right);
                }

                if (parent.find(node) != parent.end() &&
                    visited.find(parent[node]) == visited.end()) {
                    q.push(parent[node]);
                    visited.insert(parent[node]);
                }
            }
            currdist++;
        }

        return result;
    }
};