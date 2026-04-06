class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        set<pair<int, int>>st;
        int ans = INT_MIN;
        for(auto it: obstacles){
            st.insert({it[0], it[1]});
        }
        int i = 0;
        int j = 0;
        bool incY = true;
        bool incX = false;
        bool decY = false;
        bool decX = false;
        for(auto it: commands){
            if(it == -1){
                if(incY){
                    incY = false;
                    incX = true;
                }
                else if(incX){
                    incX = false;
                    decY = true;
                }
                else if(decX){
                    decX = false;
                    incY = true;
                }
                else{
                    decY = false;
                    decX = true;
                }
            }
            else if(it == -2){
                if(incY){
                    incY = false;
                    decX = true;
                }
                else if(incX){
                    incX = false;
                    incY = true;
                }
                else if(decX){
                    decX = false;
                    decY = true;
                }
                else{
                    decY = false;
                    incX = true;
                }
            }
            else{
                for(int k=0;k<it;k++){
                    int tempi = i;
                    int tempj = j;
                    if(incY){
                        tempj++;
                    }
                    else if(incX){
                        tempi++;
                    }
                    else if(decY){
                        tempj--;
                    }
                    else{
                        tempi--;
                    }
                    if(st.find({tempi, tempj})!=st.end()){
                        break;
                    }
                    i = tempi;
                    j = tempj;
                }
            }
            ans = max(ans, i*i + j*j);
        }
        return ans;
    }
};