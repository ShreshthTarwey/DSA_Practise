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
    void recursion(ListNode*head, vector<int>& forward, vector<int>& backward){
        if(!head) return;
        forward.push_back(head->val);
        recursion(head->next, forward, backward);
        backward.push_back(head->val);
    }
    bool isPalindrome(ListNode* head) {
        vector<int>forward;
        vector<int>backward;
        recursion(head, forward, backward);
        return forward == backward;
    }
};