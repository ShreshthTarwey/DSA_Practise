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

    ListNode* reverseNode(ListNode* head){
        if(!head) return NULL;
        ListNode* prev = NULL;
        ListNode* curr = head;
        ListNode* fut = head->next;
        while(curr){
            curr->next = prev;
            prev = curr;
            curr = fut;
            if(fut!=NULL)
            fut = fut->next;
        }
        return prev;
    }
    bool sirMethod(ListNode* head){
        //First finding the middle pointer, or node
        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* prev = slow;
        while(fast && fast->next){
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        prev->next = NULL;
        ListNode* head2 = reverseNode(slow);
        ListNode* pointer = head;
        while(pointer){
            if(pointer->val != head2->val) return false;
            pointer = pointer->next;
            head2 = head2->next;
        }

        return true;
        
    }


    bool isPalindrome(ListNode* head) {
        //My Method --------------------------------------------------------------------------------------------
        // vector<int>forward;
        // vector<int>backward;
        // recursion(head, forward, backward);
        // return forward == backward;
        // --------------------------------------------------------------------------------------------------------
        // SirMethod, one of the application of 2 pointer
        return sirMethod(head);
    }
};