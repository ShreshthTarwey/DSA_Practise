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
    void insert(ListNode* &ans, int data){
        if(!ans){
            ListNode* temp = new ListNode(data);
            ans = temp;
            return;
        }
        ListNode* temp = ans;
        while(temp->next){
            temp = temp->next;
        }
        ListNode* newNode = new ListNode(data);
        temp->next = newNode;
        return;
    }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry = 0;
        // int len1 = length(l1);
        // int len2 = length(l2);
        int i=0;
        ListNode* p1 = l1;
        ListNode* p2 = l2;
        ListNode* ans = NULL;
        while(p1 && p2){
            int sum = p1->val+p2->val+carry;
            int num = sum%10;
            carry = sum/10;
            insert(ans,num);
            p1 = p1->next;
            p2 = p2->next;
        }
        while(p1){
            int sum = p1->val+carry;
            int num = sum%10;
            carry = sum/10;
            insert(ans,num);
            p1 = p1->next;
        }
        while(p2){
            int sum = p2->val+carry;
            int num = sum%10;
            carry = sum/10;
            insert(ans,num);
            p2 = p2->next;
        }
        if(carry!=0){
            insert(ans,carry);
        }
        return ans;
    }
};