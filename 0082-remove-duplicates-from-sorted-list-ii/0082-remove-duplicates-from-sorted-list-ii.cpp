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
    ListNode* deleteDuplicates(ListNode* head) {
        if(head == nullptr) return nullptr;
        ListNode* dummy = new ListNode(0);
        dummy -> next = head;
        ListNode* temp = head;
        unordered_map<int, bool> m;
        while(temp -> next) {
            if(temp -> val == temp -> next -> val) {
                m[temp -> val] = true;
            }
            temp = temp -> next;
        }
        temp = head;
        ListNode* current = dummy;
        while(temp != NULL) {
            if(!m[temp -> val]) {
                current -> next = temp;
                current = current -> next;
            }
            temp = temp -> next;
        }
        current -> next = temp;
        return dummy -> next;
    }
};