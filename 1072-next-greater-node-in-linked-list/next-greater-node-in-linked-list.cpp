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
        int length = 0;
        while(temp){
            temp = temp->next;
            length++;
        }
        return length;
    }
    vector<int> nextLargerNodes(ListNode* head) {
        stack<pair<int, int>>st;
        vector<int>ans(getLength(head), 0);
        ListNode* temp = head;
        // cout<<getLength(head);
        int index = 0;
        while(temp){
            while(!st.empty() && st.top().first<temp->val){
                ans[st.top().second] = temp->val;
                st.pop();
            }
            st.push({temp->val, index});
            index++;
            temp = temp->next;
        }
        return ans;
    }
};