/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* method1(Node* head){
        unordered_map<Node*, Node*>mp;
        Node* dummy = new Node(0);
        Node* tailNew = dummy;
        Node* temp = head;
        while(temp){
            Node* newNode = new Node(temp->val);
            mp[temp] = newNode;
            temp = temp->next;
            tailNew->next = newNode;
            tailNew = tailNew->next;
        }
        //Filling randoms

        Node* newNode = dummy->next;
        Node* oldNode = head;
        while(newNode && oldNode){
            if(!oldNode->random){
                newNode->random = NULL;
            }
            else{
                newNode->random = mp[oldNode->random];
            }
            oldNode = oldNode->next;
            newNode = newNode->next;
        }
        return dummy->next;
    }
    Node* copyRandomList(Node* head) {
        return method1(head); //O(n) T.C, O(n) S.C
        // return spaceOptimizedMethod(head);
    }
};