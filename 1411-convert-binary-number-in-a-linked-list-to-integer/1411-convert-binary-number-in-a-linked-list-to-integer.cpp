/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:

    ListNode* reverseLL(ListNode* head) {
        ListNode* current = head; 
        ListNode *prev = NULL, *next = NULL; 
          while (current != NULL) { 
            next = current->next; 
            current->next = prev;  
            prev = current; 
            current = next; 
        } 
        head = prev; 
        return head;
    }

    int getDecimalValue(ListNode* head) {
        int ans = 0 , i=0;
        ListNode* temp = reverseLL(head);

        while(temp!=NULL){
            ans += pow(2,i)*temp->val;
            i++;
            temp = temp->next;
        }
        return ans;
    }
};