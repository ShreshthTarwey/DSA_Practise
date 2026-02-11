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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        int length = getLength(head);
        vector<ListNode*>ans(k, nullptr);

        int partSize = length / k;
        int extraNodes = length % k;

        auto it = head;
        for(int i=0;i<k && it; i++){
            ans[i] = it;
            int currPartSize = partSize + (extraNodes-->0 ? 1 : 0);
            int counter = 0;
            while(it && counter<currPartSize-1){
                counter++;
                it = it->next;
            }
            if(it){
                ListNode* nextPart = it->next;
                it->next = NULL;
                it = nextPart;

            }
        }
        return ans;
    }
};