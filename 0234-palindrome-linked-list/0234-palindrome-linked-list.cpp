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
    bool isPalindrome(ListNode* head) {
         ListNode* slow= head;
 
    // Declare a stack 
    stack <int> s; 
 
    // Push all elements of the list 
    // to the stack 
    while(slow != NULL)
    {
        s.push(slow->val);
 
        // Move ahead 
        slow = slow->next;
    }
 
    // Iterate in the list again and 
    // check by popping from the stack
    while(head != NULL )
    {            
        // Get the top most element 
        int i=s.top();
 
        // Pop the element 
        s.pop();
 
        // Check if data is not
        // same as popped element 
        if(head -> val!= i)
        {
            return false;
        }
 
        // Move ahead 
        head=head->next;
        }
        return true;
    }
};