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
    int carry = 0;
    void recFun(ListNode* head){
        if(!head) return;
        recFun(head->next);
        int num = (head->val*2) + carry;
        carry = num/10;
        int newVal = num%10;
        head->val = newVal;
    }
    ListNode* doubleIt(ListNode* head) {
        // int carry = 0;
        recFun(head);
        if(carry>0){
            ListNode* newHead = new ListNode(carry);
            newHead->next = head;
            return newHead;
        }
        return head;
    }
};