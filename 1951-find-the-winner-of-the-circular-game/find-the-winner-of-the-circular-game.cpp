class Solution {
public:
    int findTheWinner(int n, int k) {
        queue<int>q;
        for(int i=1;i<=n;i++){
            q.push(i);
        }
        while(q.size()>1){
            int count = k;
            while(!q.empty()){
                int ele = q.front();
                q.pop();
                count--;
                if(count==0){
                    // cout<<ele<<endl;
                    break;
                }
                q.push(ele);
            }
        }
        return q.front();
    }
};