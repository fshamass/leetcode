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
    // Function to reverse the linked list in place
    ListNode* reverseLinkList(ListNode* root) {
        if(!root) return nullptr; // Handle empty list case
        ListNode* rHead = nullptr;
        while(root) {
            ListNode* tmp = root;
            root = root->next;
            tmp->next = rHead;
            rHead = tmp;
        }
        return rHead;
    }

    void insertNode(ListNode* root, ListNode* node) {
        ListNode* tmp = root->next;
        root->next = node;
        node->next = tmp;
    } 

    void reorderList(ListNode* head) {
        // Strategy is to find the middle of the list, reverse the second half,
        // and then merge the two halves together in the required order.
        if(!head->next) return;
        //Find middle of the list using the slow and fast pointer technique
        //With this tenique, slow will end up at the moddle of the list for odd number of nodes
        //and at the last node of the first half for even number of nodes
        ListNode* fast = head->next;
        ListNode* slow = head;
        while(fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        //Reverse the second half of the list starting from slow->next
        ListNode* rHead = reverseLinkList(slow->next);
        //Reset slow->next to null to split the list into two halves
        slow->next = nullptr;
        ListNode* newHead = head;
        //now we have two halves: head (first half) and rHead (reversed second half)
        //We will now merge these two halves together
        while(rHead) {
            ListNode* tmp = rHead->next;
            insertNode(newHead, rHead);
            newHead = newHead->next->next;
            rHead = tmp;
        }
    }
};