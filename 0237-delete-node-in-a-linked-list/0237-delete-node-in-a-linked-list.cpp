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
    void deleteNode(ListNode* node) {
       

        ListNode* nextNode = node->next;
        node->next = nextNode->next;
        node->val= nextNode->val;
        delete nextNode; 
    }
};