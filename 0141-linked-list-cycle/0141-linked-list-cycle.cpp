/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode* head) {
        unordered_set<ListNode*> nodeMap;
        ListNode* temp = head;

        // Traverse the linked list
        while (temp != nullptr) {
            // If the node is already in the
            // Map, there is a loop
            if (nodeMap.find(temp) != nodeMap.end()) {
                return true;
            }
            // Store the current node
            // In the map
            nodeMap.insert(temp);
            ;

            // Move to the next node
            temp = temp->next;
        }

        // If the list is successfully traversed
        // Without a loop, return false
        return false;
    }
};