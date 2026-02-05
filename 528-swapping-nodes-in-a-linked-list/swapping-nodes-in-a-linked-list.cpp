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
        int length = 0;
        ListNode* temp = head;
        while(temp){
            temp = temp->next;
            length++;
        }
        return length;
    }
    ListNode* swappingValues(ListNode* head, int k){
        int length = findLength(head);
        ListNode* pointer1 = head;
        ListNode* pointer2 = head;
        int target1 = k;
        int target2 = length-k+1;
        ListNode* temp = head;
        int counter = 1;
        while(temp){
            if(counter== target1){
                pointer1 = temp;
            }
            if(counter == target2){
                pointer2 = temp;
                // break;
            }
            temp=temp->next;
            counter++;

        }
        int val1 = pointer2->val;
        pointer2->val = pointer1->val;
        pointer1->val = val1;
        return head;
    }
    int Len(ListNode* head){
        if(!head) return 0;
        return 1 + Len(head->next);
    }
    ListNode* swappingNodes(ListNode* head, int k){
        //Case 1
        if(!head ||  !head->next) return head;
        int len = Len(head);
        int lpos = k;
        int rpos = len-k+1;
        if(lpos>rpos) swap(lpos, rpos);

        //Case 2 
        if(lpos == rpos) return head;

        //Case 3

        if(len == 2){
            ListNode* newHead = head->next;
            newHead->next = head;
            head->next = NULL;
            head = newHead;
            return head;
        }

        //Case 4

        if(lpos == 1){
            ListNode* lp = NULL;
            ListNode* rp = head;
            ListNode* ln = head;
            for(int i=1;i<rpos-1;i++)
                rp = rp->next;

            ListNode* rn = rp->next;
            ListNode* rsave = NULL; //Or you can write rn->next, but in this case it will be null
            //Swapping
            rn->next = ln->next;
            rp->next = ln;
            ln->next = rsave;
            head = rn;
            return head;
        }

        //Case 5

        int noOfNodesBetweenSwapNodes = rpos-lpos-1;

        if(noOfNodesBetweenSwapNodes == 0){
            ListNode* lp = head;
            for(int i=1;i<lpos-1;i++)
                lp = lp->next;
            ListNode* ln = lp->next;
            ListNode* rp = head;
            for(int i=1;i<rpos-1;i++)
                rp = rp->next;
            ListNode* rn = rp->next;
            ListNode* rsave = rn->next;
            //Swap
            lp->next = rp->next;
            rn->next = rp;
            rp->next = rsave;
            return head;
        }
        else{
        //Case 6
            ListNode* lp = head;
            for(int i=1;i<lpos-1;i++)
                lp = lp->next;
            ListNode* ln = lp->next;
            ListNode* rp = head;
            for(int i=1;i<rpos-1;i++)
                rp = rp->next;
            ListNode* rn = rp->next;
            ListNode* rsave = rn->next;

            lp->next = rn;
            rn->next = ln->next;
            rp->next = ln;
            ln->next = rsave;

            return head; 

        }






    } 
    ListNode* swapNodes(ListNode* head, int k) {
        // return swappingValues(head, k);
        return swappingNodes(head, k);
    }
};