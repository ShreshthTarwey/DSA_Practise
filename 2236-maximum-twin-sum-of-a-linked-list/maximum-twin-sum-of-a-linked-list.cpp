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
        ListNode* temp = head;
        int count = 0;
        while(temp){
            temp = temp->next;
            count++;
        }
        return count;
    }
    ListNode* rev(ListNode* head){
        if(!head) return NULL;
        ListNode* prev = NULL;
        ListNode* curr = head;
        ListNode* nxt = curr->next;
        while(curr){
            curr->next = prev;
            prev = curr;
            curr = nxt;
            if(!nxt) break;
            nxt = nxt->next;
        }
        return prev;
    }
    int pairSum(ListNode* head) {
        int length = findLength(head);
        ListNode* mid = head;
        int idx = 0;
        while(idx<length/2){
            idx++;
            mid = mid->next;
        }
        mid = rev(mid);
        int ans = INT_MIN;
        ListNode* temp = head;
        while(mid){
            int sum = mid->val + temp->val;
            temp = temp->next;
            mid = mid->next;
            ans = max(ans, sum);
        }
        return ans;
    }
};