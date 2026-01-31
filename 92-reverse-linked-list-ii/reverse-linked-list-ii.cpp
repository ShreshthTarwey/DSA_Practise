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
    ListNode* revFun(ListNode* head, int left, int right){
        ListNode* prev = NULL;
        ListNode* curr = head;
        if(curr->next==NULL){
            head->next = NULL;
            return head;
        }
        ListNode* currNext = curr->next;
        int count = left;
        while(curr && count<=right){
            curr->next = prev;
            prev = curr;
            curr = currNext;
            if(currNext!=NULL){
                currNext = currNext->next;
            }
            count++;
        }
        return prev;
    }
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode* leftPointer = NULL;
        ListNode* rightPointer = NULL;
        ListNode* temp = head;
        ListNode* prev = NULL;
        int count = 1;
        while(temp){
            if(count==left){
                leftPointer = temp;
            }
            if(count<left){
                prev = temp;
            }
            if(count==right){
                rightPointer = temp;
            }
            temp = temp->next;
            count++;
        }
        ListNode* r = rightPointer->next;
        ListNode* newHead = NULL;
        if(left==1){
            newHead = revFun(head, left, right);
            leftPointer->next = r;
            return newHead;
        }
        else{
            prev->next = revFun(leftPointer, left, right);
            leftPointer->next = r;
            return head;
        }
    }
};