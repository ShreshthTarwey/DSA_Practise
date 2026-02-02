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
    void sanitizeMan(ListNode* curr, int csum, unordered_map<int, ListNode*>&mp){
        int temp = csum;
        while(true){
            temp+=curr->val;
            if(temp==csum) break;
            mp.erase(temp);
            curr = curr->next;
        }
    }
    ListNode* removeZeroSumSublists(ListNode* head) {
        if(!head || (!head->next && head->val==0)) return 0;
        unordered_map<int, ListNode*>mp;
        auto it = head;
        int csum = 0;
        while(it){
            csum += it->val;
            if(csum == 0){
                head = it->next;
                mp.clear();
            }
            else if(mp.find(csum)!=mp.end()){
                sanitizeMan(mp[csum]->next, csum, mp);
                mp[csum]->next = it->next;
            }
            else
            mp[csum] = it;
            it = it->next;
        }
        return head;
    }
};