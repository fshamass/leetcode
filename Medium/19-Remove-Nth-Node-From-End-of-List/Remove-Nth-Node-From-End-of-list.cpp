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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        // Strategy is to use a dummy node to simplify edge cases and a two-pointer technique
        // to find the nth node from the end of the list.
        if(!head || n <= 0) return head; // Handle edge cases where head is null or n is non-positive
        ListNode dummy(0,head);
        ListNode* tail = &dummy;
        // Move the tail pointer n steps ahead
        while((n-->=0) && (tail)) {
            tail = tail->next;
        }
        // If n is positive and tail is null, it means n is larger than the length of the list        
        if(n<0) {
            ListNode* delNode = &dummy;
            // Move both pointers until tail reaches the end of the list
            while(tail) {
                tail = tail->next;
                delNode = delNode->next;
            }
            // Now delNode points to the node before the one we want to delete since we started with a dummy node
            // If delNode is the dummy node, it means we are deleting the head
            ListNode* tmp = delNode->next;
            delNode->next = tmp->next;
            delete tmp;
        }
        return dummy.next;
    }
};