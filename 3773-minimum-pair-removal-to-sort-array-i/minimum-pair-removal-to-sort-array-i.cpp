class Node {
    public:
    int val;
    Node* next;
    Node(int val) {
        this->val = val;
        next = NULL;
    }
};
class Solution {
public:
    int minimumPairRemoval(vector<int>& nums) {
        if (nums.size() <= 1)
            return 0;
        if (nums.size() == 2) {
            if (nums[0] <= nums[1])
                return 0;
            return 1;
        }
        // Simulation
        // int sum = 0;
        // Creating Linked List
        Node* head = new Node(nums[0]);
        Node* tail = head;
        for (int i = 1; i < nums.size(); i++) {
            Node* temp = new Node(nums[i]);
            tail->next = temp;
            tail = tail->next;
        }
        // LL created now time to
        int count = 0;
        while (true) {
            Node* prev = NULL;
            Node* curr = head;
            Node* nextCurr = head->next;
            int minSum = INT_MAX;
            Node* prevP = NULL;
            Node* currP = head;
            Node* nextCurrP = head->next;
            bool flag = true;
            while (nextCurrP != NULL) {
                int sum = currP->val + nextCurrP->val;
                if (sum < minSum) {
                    
                    // if(prevP==NULL)
                    prev = prevP;
                    curr = currP;
                    nextCurr = nextCurrP;
                    minSum = sum;
                }
                if(currP->val>nextCurrP->val){
                    flag = false;
                }
                prevP = currP;
                currP = nextCurrP;
                nextCurrP = nextCurrP->next;
            }
            if(flag == true){
                return count;
            }
            //Handeling adjaccent starts from head case
            if(prev==NULL){
                Node* temp = new Node(minSum);
                head = temp;
                temp->next = nextCurr->next;
                count++;
                continue;
            }
            Node* temp = new Node(minSum);
            prev->next = temp;
            temp->next = nextCurr->next;
            count++;
        }
        return 0;
    }
};