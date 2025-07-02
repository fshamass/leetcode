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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        // Strategy is to use a priority queue to keep track of the smallest elements from each list
        // and then build the merged list from these elements.
        // We will need a min-heap (priority queue) to efficiently get the smallest element
        // from the lists. Since C++'s priority queue is a max-heap by default, we will store negative values
        ListNode* head = nullptr;
        ListNode* tail = nullptr;
        priority_queue<int> prioQueue;
        if(lists.size() == 0) {
            return nullptr;
        }
        //Flag to ensure that at least one lists is not null
        bool valAdded = true;
        while(valAdded) {
            //Set flag to false to check if we have added any value in this iteration
            valAdded = false;
            for(int i=0;i<lists.size();++i) {
                if(lists[i]) {
                    //We found at least one non-null list
                    valAdded = true;
                    //push negative value into priority queue
                    prioQueue.push(-lists[i]->val);
                    lists[i] = lists[i]->next;
                }
            }
        }
        //Pop elements from priority queue and add them to result linklist
        while(!prioQueue.empty()) {
            if(head == nullptr) {
                //negate the value to get the original value
                head = new ListNode(-prioQueue.top());
                tail = head;
            } else {
                //negate the value to get the original value
                tail->next = new ListNode(-prioQueue.top());
                tail=tail->next;
            }
            prioQueue.pop();
        }
        return head;
    }
};
