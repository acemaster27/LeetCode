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
        if (head == nullptr || k == 1) return head;

        ListNode dummy(0);
        dummy.next = head;
        
        ListNode* prevGroup = &dummy;
        ListNode* curr = head;
        int count = 0;

        while (curr != nullptr) {
            curr = curr->next;
            count++;
        }

        while (count >= k) {
            curr = prevGroup->next;     
            ListNode* nextNode = curr->next; 

            for (int i = 1; i < k; i++) {
                curr->next = nextNode->next;
                nextNode->next = prevGroup->next;
                prevGroup->next = nextNode;
                nextNode = curr->next;
            }
            
            prevGroup = curr;
            count -= k;
        }

        return dummy.next;
    }
};