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
        ListNode* temp = head;
        int count = 0;
        while(temp){
            temp = temp->next;
            count++;
        }
        return count;
    }
    ListNode* reverseKGroup(ListNode* head, int k) { //T.C->O(N^2/k) to make it O(N), remove calling getLength Function alwasys send one Length variable and keep subtracting it in every recursion call keep substracting it
        //Base Cases
        if(!head) return NULL;
        if(!head->next) return head;

        //1 case hum krange baki recursion sambhal lega

        ListNode* prev = NULL;
        ListNode* curr = head;
        ListNode* fut = head->next;

        int position = 0;

        int len = getLength(head);
        if(len<k){
            return head;
        }
        while(position<k){
            curr->next = prev;
            prev = curr;
            curr = fut;
            if(fut!=NULL) fut = fut->next;
            position++;
        }
        ListNode* recursionKaHead = reverseKGroup(curr, k);
        head->next = recursionKaHead;
        return prev;
    }
};