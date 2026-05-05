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
    int getLength(ListNode* head){
        int count = 0;
        ListNode* temp = head;
        while(temp){
            count++;
            temp = temp->next;
        }
        return count;
    }
    ListNode* rotateRight(ListNode* head, int k) {
        int len = getLength(head);
        // cout<<len;
        // return head;
        if(!head || !head->next || !k) return head;
        k = k%len;
        if(k==0) return head;
        int target = len - k - 1;
        ListNode* newTail = head;
        ListNode* temp = head;
        int count = 0;
        while(temp && count<target){
            temp = temp->next;
            count++;
        }
        ListNode* newHead = temp->next;
        temp->next = NULL;
        ListNode* tail = newHead;
        while(tail->next){
            tail = tail->next;
        }
        tail->next = head;
        return newHead;
    }
};