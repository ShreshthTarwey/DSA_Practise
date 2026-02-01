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
    Node* spaceOptimizedMethod(Node* head){
        Node* temp = head;
        //Creating interweave list A->A'->B->B'....
        while(temp){
            Node* newNode = new Node(temp->val);
            newNode->next = temp->next;
            temp->next = newNode;
            temp = newNode->next;
        }
        //Now handeling random pointers
        Node* oldPointer = head;
        if(!head) return NULL;
        Node* newPointer = head->next;
        while(oldPointer && newPointer){
            if(!oldPointer->random){
                newPointer->random = NULL;
            }
            else{
                newPointer->random = oldPointer->random->next;
            }
            oldPointer = oldPointer->next->next;
            if(!newPointer->next) break;
            newPointer = newPointer->next->next;
        }
        //Splliting Lists
        Node* dummy = new Node(0);
        Node* tail = dummy;
        Node* it = head;
        Node* newList = head->next;
        Node* it2 = newList;
        while(it && it2){
            it->next = it2->next;
            if(!it2->next) break;
            it2->next = it2->next->next;
            it = it->next;
            it2 = it2->next;
        }
        return newList;
    }
    
    Node* copyRandomList(Node* head) {
        // return method1(head); //O(n) T.C, O(n) S.C
        return spaceOptimizedMethod(head);
    }
};