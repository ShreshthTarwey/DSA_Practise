class Solution {
public:
    int maxProduct(int n) {
        priority_queue<int, vector<int>>pq;
        while(n){
            pq.push(n%10);
            n/=10;
        }
        int num1 = pq.top();
        pq.pop();
        int num2 = pq.top();
        pq.pop();
        return num1 * num2;
    }
};