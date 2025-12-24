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
    ListNode* stackMethod(ListNode* l1, ListNode* l2){
        stack<int>s1,s2;
        while(l1){
            s1.push(l1->val);
            l1 = l1->next;
        }
        while(l2){
            s2.push(l2->val);
            l2 = l2->next;
        }
        int carry = 0;
        int sum = 0;
        ListNode* head = NULL;
        while(!s1.empty() || !s2.empty() || carry){
            sum = carry;
            if(!s1.empty()){
                sum+=s1.top();
                s1.pop();
            }
            if(!s2.empty()){
                sum+=s2.top();
                s2.pop();
            }
            ListNode* newNode = new ListNode(sum%10);
            newNode->next = head;
            head = newNode;
            carry = sum/10;
        }
        return head;
    }
    ListNode* rev(ListNode* head){
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
    ListNode* reverseListMethod(ListNode* l1, ListNode* l2){
        ListNode* newl1 = rev(l1);
        ListNode* newl2 = rev(l2);
        int carry = 0;
        ListNode* result = new ListNode(0);
        ListNode* tail = result;
        while(newl1 || newl2 || carry){
            int sum = carry;
            if(newl1){
                sum+=newl1->val;
                newl1 = newl1->next;
            }
            if(newl2){
                sum+=newl2->val;
                newl2 = newl2->next;
            }
            
            ListNode* newNode = new ListNode(sum%10);
            carry = sum/10;
            tail->next = newNode;
            tail = tail->next;
        }
        if(!newl1){
            tail->next = newl1;
        }
        if(!newl2){
            tail->next = newl2;
        }
        return rev(result->next);
    } 
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        // return stackMethod(l1, l2); //O(n), O(N) -> Maintains data integrety
        return reverseListMethod(l1, l2);
    }
};