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
    ListNode* sortList(ListNode* head) {
      if (head == nullptr || head->next == nullptr) {
            return head;
        }

          ListNode* middle = findMiddle(head);
        
        // Divide the list into two halves
        ListNode* right = middle->next;
        middle->next = nullptr;
        ListNode* left = head;

    left = sortList(left);
        right = sortList(right);

        return mergeTwoSortedLinkedLists(left, right);

    }

    ListNode* mergeTwoSortedLinkedLists(ListNode* list1, ListNode* list2) {
        // Create dummy node to serve as head of merged list
        ListNode* dummyNode = new ListNode(-1);
        ListNode* temp = dummyNode;

        // Traverse both lists simultaneously
        while (list1 != nullptr && list2 != nullptr) {
            /*Compare elements of both lists 
            and link the smaller node 
            to the merged list*/
            if (list1->val <= list2->val) {
                temp->next = list1;
                list1 = list1->next;
            } else {
                temp->next = list2;
                list2 = list2->next;
            }
            // Move the temporary pointer to the next node
            temp = temp->next; 
        }

        /*If any list still has 
        remaining elements append 
        them to the merged list*/
        if (list1 != nullptr) {
            temp->next = list1;
        } else {
            temp->next = list2;
        }
        // Return the merged list starting 
        // from the next of the dummy node
        return dummyNode->next;
    }

      ListNode* findMiddle(ListNode* head) {
        // If the list is empty or has only one node, 
        // the middle is the head itself
       if (head == nullptr || head->next == nullptr) {
        return head;
    }

    // Two-pointer technique
    ListNode* slow = head;
    ListNode* fast = head->next;

    while (fast != nullptr && fast->next != nullptr) {
        slow = slow->next;       // Move slow pointer by 1 step
        fast = fast->next->next; // Move fast pointer by 2 steps
    }

    return slow;
    }
};

