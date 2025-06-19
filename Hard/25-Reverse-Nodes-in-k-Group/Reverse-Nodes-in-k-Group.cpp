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
    //Start points to the 1st node and end points to one node after last node
    ListNode* reverseList(ListNode* head) {
        ListNode* rHead = nullptr;
        while(head) {
            ListNode* tmp = head;
            head = head->next;
            tmp->next = rHead;
            rHead = tmp;
        }
        return rHead;
    }

    ListNode* getKthNode(ListNode* head, int k) {
        while((--k > 0) && (head)) {
            head = head->next;
        }
        return head;
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode dummy(0,head);
        ListNode* prevEnd = &dummy;
        while(true) {
            //find kth node
            ListNode* kthNode = getKthNode(prevEnd->next,k);
            if(!kthNode) break;
            //set next group to kth node next
            ListNode* nextGroup = kthNode->next;
            //set kth node next to null
            kthNode->next = nullptr;
            //reverse list that starts at prevEnd->next
            ListNode* tmpPrevEnd = prevEnd->next;
            prevEnd->next = reverseList(prevEnd->next);
            //set prevEnd to be 1st node prior to reversing list
            prevEnd = tmpPrevEnd;
            prevEnd->next = nextGroup;
        }
        return dummy.next;
    }
};