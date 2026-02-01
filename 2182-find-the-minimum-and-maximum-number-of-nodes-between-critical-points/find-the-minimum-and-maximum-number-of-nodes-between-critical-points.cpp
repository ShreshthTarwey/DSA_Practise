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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        int first = -1;
        int last = -1;
        int between = -1;
        ListNode* prev = head;
        ListNode* curr = head->next;
        if(!head->next) return {-1, -1};
        ListNode* currNext = head->next->next;
        if(!currNext) return {-1, -1};
        int counter = 2;
        int minVal = INT_MAX;
        while(currNext){
            int val1 = prev->val;
            int val2 = curr->val;
            int val3 = currNext->val;

            if((val2>val1 && val2>val3) || (val2<val1 && val2<val3)){
                if(first==-1){
                    first = counter;
                }
                last = counter;
                if(between != -1)
                minVal = min(minVal, abs(counter-between));
                between = counter;
            }
            counter++;
            prev = curr;
            curr = currNext;
            currNext = currNext->next;
        }
        if(between==-1) return {-1, -1};
        return {(minVal==INT_MAX ? -1 : minVal), (last==first)? -1 : last-first};
    }
};