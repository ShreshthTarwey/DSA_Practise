class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) {
        int n = positions.size();
        vector<int>actualIndex(n);
        for(int i=0;i<n;i++){
            actualIndex[i] = i;
        }

        auto lambda = [&](int &i, int &j){
            return positions[i] < positions[j];
        };
        sort(actualIndex.begin(), actualIndex.end(), lambda);
        vector<int>result;
        stack<int>st;

        for(auto idx: actualIndex){
            if(directions[idx] == 'R'){
                st.push(idx);
            }
            else{
                while(!st.empty() && healths[idx]>0){
                    int top_idx = st.top();
                    st.pop();
                    if(healths[idx]>healths[top_idx]){
                        healths[idx]--; 
                        healths[top_idx] = 0;
                    }
                    else if(healths[idx]<healths[top_idx]){
                        healths[top_idx]--;
                        healths[idx] = 0;
                        
                        st.push(top_idx);
                    }
                    else{
                        healths[idx] = 0;
                        healths[top_idx] = 0;
                    }
                }
            }
        }
        for(int i=0;i<n;i++){
            if(healths[i]>0){
                result.push_back(healths[i]);
            }
        }
        return result;
    }
};