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
    ListNode* mergeNodes(ListNode* head) {
        if(!head) return NULL;
        ListNode* fast = head->next;
        ListNode* slow = head;
        int sum = 0;
        ListNode* prev = NULL;
        while(fast){
            if(fast->val==0){
                slow->val = sum;
                sum=0;
                prev = slow;
                slow = slow->next;
            }
            sum+=fast->val;
            fast = fast->next;
        }
        prev->next = NULL;
        return head;
    }
};