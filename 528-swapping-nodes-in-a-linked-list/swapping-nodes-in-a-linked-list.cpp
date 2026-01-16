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
    int findLength(ListNode* head){
        int length = 0;
        ListNode* temp = head;
        while(temp){
            temp = temp->next;
            length++;
        }
        return length;
    }
    ListNode* swapNodes(ListNode* head, int k) {
        int length = findLength(head);
        ListNode* pointer1 = head;
        ListNode* pointer2 = head;
        int target1 = k;
        int target2 = length-k+1;
        ListNode* temp = head;
        int counter = 1;
        while(temp){
            if(counter== target1){
                pointer1 = temp;
            }
            if(counter == target2){
                pointer2 = temp;
                // break;
            }
            temp=temp->next;
            counter++;

        }
        int val1 = pointer2->val;
        pointer2->val = pointer1->val;
        pointer1->val = val1;
        return head;
    }
};