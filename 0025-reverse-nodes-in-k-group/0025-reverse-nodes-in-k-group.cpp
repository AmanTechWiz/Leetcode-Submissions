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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* temp = head;
        ListNode* prev = NULL;

        while (temp != NULL) {
            ListNode* Kthnode = find(temp, k);

            if (Kthnode == NULL) {
                if (prev) {
                    prev->next = temp;
                }
                break;
            }

            ListNode* nextnode = Kthnode->next;
            Kthnode->next = NULL;
            reverseLinkedList(temp);

            if (temp == head) {
                head = Kthnode;
            } else {
                prev->next = Kthnode;
            }
            prev = temp;
            temp = nextnode;
        }
        return head;
    }

    ListNode* find(ListNode* temp, int k) {
        // Decrement K
        // as we already start
        // from the 1st node
        k -= 1;

        // Decrement K until it reaches the desired position
        while (temp != NULL && k > 0) {
            // Decrement k as temp progresses
            k--;

            // Move to the next node
            temp = temp->next;
        }

        // Return the Kth node
        return temp;
    }

    ListNode* reverseLinkedList(ListNode* head) {
        /* Initialize 'temp' at
         * head of linked list */
        ListNode* temp = head;

        /* Initialize pointer 'prev'
         * to NULL, representing
         * the previous node */
        ListNode* prev = NULL;

        // Continue till 'temp'
        // reaches the end (NULL)
        while (temp != NULL) {
            /* Store the next node in 'front'
             * to preserve the reference */
            ListNode* front = temp->next;

            /* Reverse the direction of the
             * current node's 'next' pointer
             * to point to 'prev' */
            temp->next = prev;

            /* Move 'prev' to the current
             * node for the next iteration */
            prev = temp;

            /* Move 'temp' to the 'front' node
             * advancing the traversal */
            temp = front;
        }

        // Return the new head
        // of the reversed linked list
        return prev;
    }
};