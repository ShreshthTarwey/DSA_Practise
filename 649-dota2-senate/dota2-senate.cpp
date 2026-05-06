class Solution {
public:
    string predictPartyVictory(string senate) {
        queue<pair<char, int>>q1, q2;
        for(int i=0;i<senate.length();i++){
            if(senate[i] == 'R'){
                q1.push({senate[i], i});
            }
            else{
                q2.push({senate[i], i});
            }
        }
        int index = senate.length();
        while(true){
            if(q1.empty()){
                return "Dire";
            }
            if(q2.empty()){
                return "Radiant";
            }
            auto it = q1.front();
            auto it2 = q2.front();
            if(it.second<it2.second){
                q1.push({it.first, index++});
            }
            else{
                q2.push({it2.first, index++});
            }
            q1.pop();
            q2.pop();
        }
        return "";
    }
};