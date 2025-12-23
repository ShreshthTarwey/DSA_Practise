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
    ListNode* deleteDuplicates(ListNode* head) {
        if(!head) return NULL;
        ListNode* future = head->next;
        ListNode* curr = head;
        while(future){
            if(curr->val == future->val){
                curr->next = future->next;
                if(curr->next!=NULL && curr->next->val == curr->val){
                    future = curr->next;
                    continue;
                }
            }
            curr = curr->next;
            if(curr==NULL || curr->next==NULL) break;
            future = curr->next;
        }
        return head;
    }
};