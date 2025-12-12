class Solution {
public:
    void fill(unordered_map<string, string>& mp, string ids, int t){
        vector<string>s;
        string temp = "";
        for(auto it:ids){
            if(it==' '){
                s.push_back(temp);
                temp = "";
            }
            else
            temp+=it;
        }
        s.push_back(temp);
        for(auto it: s){
            mp[it] = to_string(t);
        }
    }

    void increase(vector<int>& ans){
        for(int i=0;i<ans.size();i++){
            ans[i]++;
        }
    }

    void increase2(unordered_map<string,string>& mp, int ts, vector<int>& ans){
        for(int i=0;i<ans.size();i++){
            string key = to_string(i);
            int last = stoi(mp[key]);
            if(last<=ts){
                mp[key] = "0";
                ans[i]++;
            }
        }
    }

    void increase3(string s, vector<int>& ans){
        vector<string> st;
        string temp = "";
        for(auto it: s){
            if(it==' '){
                st.push_back(temp.substr(2));
                temp = "";
            }
            else
            temp+=it;
        }
        st.push_back(temp.substr(2));
        for(auto it:st){
            ans[stoi(it)]++;
        }
    }

    vector<int> countMentions(int numberOfUsers, vector<vector<string>>& events) {
        vector<int>ans(numberOfUsers,0);
        unordered_map<string, string>mp;
        sort(events.begin(), events.end(), [](auto& a, auto& b){
            int t1 = stoi(a[1]);
            int t2 = stoi(b[1]);
            if(t1==t2){
                string type1 = a[0];
                string type2 = b[0];
                return type1>type2;
            }
            else{
                return t1<t2;
            }
        });
        for(int i=0;i<numberOfUsers;i++){
            mp[to_string(i)] = "0";
        }
        for(auto it: events){
            if(it[0] == "OFFLINE"){
                int timeStp = 60 + stoi(it[1]);
                fill(mp, it[2], timeStp);
            }
            if(it[0] == "MESSAGE"){
                int ts = stoi(it[1]);
                if(it[2] == "ALL"){
                    increase(ans);
                }
                else if(it[2] == "HERE"){
                    increase2(mp, ts, ans);
                }
                else{
                    increase3(it[2], ans);
                }
            }
        }
        return ans;
    }
};