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
    int getDecimalValue(ListNode* head) {
        if(head == NULL) return 0;
        int len = 0;
        ListNode* curr = head;
        
        while(curr != NULL) {
            curr = curr->next;
            len++;
        }
        
        curr = head;
        int num = 0;
        
        while(curr != NULL) {
            num += curr->val * pow(2, len - 1);
            curr = curr->next;
            len--;
        }
        
        return num;
    }
};