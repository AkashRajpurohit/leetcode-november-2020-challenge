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
    ListNode* insertionSortList(ListNode* head) {
        ListNode* dummy = new ListNode(-1);
        ListNode* curr = head;
        
        while(curr != NULL) {
            
            ListNode* temp = curr->next;
            ListNode* prev = dummy;
            ListNode* next = dummy->next;
            
            while(next != NULL && next->val < curr->val) {
                prev = next;
                next = next->next;
            }
            
            curr->next = next;
            prev->next = curr;
            curr = temp;
            
        }
        
        return dummy->next;
    }
};