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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* dummy = new ListNode();
        /*Temp pointer to build
        the result list*/
        ListNode* temp = dummy;
        // Initialize carry
        int carry = 0;

        /*Iterate while there are nodes in l1 or l2,
        or there's a carry to process*/
        while ((l1 != NULL || l2 != NULL) || carry) {
            int sum = 0;

            /*Add the value from l1
            if available*/
            if (l1 != NULL) {
                sum += l1->val;
                l1 = l1->next;
            }

            /*Add the value from l2
            if available*/
            if (l2 != NULL) {
                sum += l2->val;
                l2 = l2->next;
            }

            // Add the carry
            sum += carry;
            // Update the carry
            carry = sum / 10;

            /* Create a new node with the digit value
            and attach it to the result list*/
            ListNode* node = new ListNode(sum % 10);
            temp->next = node;
            /*Move to the
            next position in the result list*/
            temp = temp->next;
        }
        /*Return the result list
        skipping the dummy node*/
        return dummy->next;
    }
};

// Function to print the linked list
void printList(ListNode* head) {
    while (head != NULL) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}