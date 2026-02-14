/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:
    Node* flatten(Node* head) {
        if(!head) return NULL;
        //Saving next;
        if(head->child){
            //Saving next of head to connect
            Node* save = head->next;
            head->next = flatten(head->child);
            if(head->next)
                head->next->prev = head;
            head->child = NULL;
            //Go To tail of flattend child
            Node* temp = head;
            while(temp->next){
                temp = temp->next;
            }

            // if(temp){
                // if(temp->next)
                    temp->next = save;
                    if(save)
                        save->prev = temp;

                flatten(save);
            // }
        }
        else{
            flatten(head->next);
        }
        return head;
    }
};