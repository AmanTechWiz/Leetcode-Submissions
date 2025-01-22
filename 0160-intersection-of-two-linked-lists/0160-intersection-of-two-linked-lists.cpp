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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
          ListNode *d1 = headA;
        ListNode *d2 = headB;

        //Traverse both lists until the pointers meet
        while (d1 != d2) {
            //Move pointer d1 to the head 
            //Of the second list if it reaches 
            //The end of the first list
            d1 = d1 == NULL ? headB : d1->next;
            //Move pointer d2 to the head 
            //Of the first list if it reaches 
            //The end of the second list
            d2 = d2 == NULL ? headA : d2->next;
        }

        //Return the intersection node
        return d1;
    }
};