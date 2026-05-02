class Solution {
public:
    int bruteForce(vector<int>& gas, vector<int>& cost){
        // int deficit = 0;
        int n = gas.size();
        for(int i=0;i<gas.size();i++){
            int balance = 0;
            if(gas[i]>=cost[i]){
                balance += (gas[i] - cost[i]);
                int j = (i+1)%n;
                while(j != i){
                    if(balance + gas[j] < cost[j]){
                        break;
                    }   
                    balance += (gas[j] - cost[j]);
                    j = (j+1) %n;
                }
                if(j == i) return i;
            }
        }
        return -1;
    }
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        // return bruteForce(gas, cost);
        int deficit = 0;
        int balance = 0;
        int start = 0;
        int n = gas.size();
        for(int i=0;i<n;i++){
            if(balance + gas[i] < cost[i]){
                deficit += balance + gas[i] - cost[i];
                balance = 0;
                start = i+1;
            }
            else{
                balance += gas[i] - cost[i];
            }
        }
        if(balance + deficit < 0){
            return -1;
        }
        else{
            return start;
        }
    }
};