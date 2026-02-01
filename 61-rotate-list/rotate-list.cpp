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
        int length = 0;
        ListNode* temp = head;
        while(temp){
            temp = temp->next;
            length++;
        }
        return length;
    }
    ListNode* rotateRight(ListNode* head, int k) {
        ListNode* temp = head;
        int len = getLength(head);
        // cout<<len<<" ";
        if(len==0) return NULL;
        int noOfRotations = k%len;
        if(noOfRotations == 0) return head;
        int counter = 1;
        while(counter<len-noOfRotations && temp){
            temp = temp->next;
            counter++;
        }
        ListNode* newHead = temp->next;
        temp->next = NULL;
        ListNode* newTail = NULL;
        ListNode* temp2 = newHead;
        while(temp2->next){
            temp2 = temp2->next;
        }
        newTail = temp2;
        newTail->next = head;
        return newHead;
    }
};