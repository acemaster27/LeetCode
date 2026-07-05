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

        auto custom = [](ListNode* a, ListNode* b) {
            return a->val > b->val;
        };

        priority_queue<ListNode*, vector<ListNode*>, decltype(custom)> heap;
        for(auto list : lists) {
            if(list) heap.push(list);
        }

        ListNode* dummy = new ListNode(0);
        ListNode* current = dummy;

        while(!heap.empty()) {
            auto node = heap.top();
            heap.pop();

            current -> next = node;
            current = current -> next;
            if(node -> next) heap.push(node -> next);
        }
        return dummy -> next;
    }
};