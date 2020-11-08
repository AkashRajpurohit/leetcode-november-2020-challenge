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
private:
    ListNode* reverseList(ListNode* head) {
        ListNode *curr = head, *prev = NULL, *next = NULL;
        
        while(curr != NULL) {
            next = curr->next;
            curr->next = prev;
            
            prev = curr;
            curr = next;
        }
        
        return prev;
    }
    
    ListNode* addList(ListNode* l1, ListNode* l2) {
        int sum = 0, carry = 0;
        ListNode *dummy = new ListNode(-1);
        ListNode *curr = dummy;
        
        while(l1 != NULL || l2 != NULL || carry != 0) {
            sum = carry;
            
            if(l1 != NULL) {
                sum += l1->val;
                l1 = l1->next;
            }
            
            if(l2 != NULL) {
                sum += l2->val;
                l2 = l2->next;
            }
            
            ListNode* newNode = new ListNode(sum % 10);
            curr->next = newNode;
            curr = curr->next;
            
            carry = sum / 10;
        }
        
        return dummy->next;
    }
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        l1 = reverseList(l1);
        l2 = reverseList(l2);
        
        return reverseList(addList(l1, l2));
    }
};