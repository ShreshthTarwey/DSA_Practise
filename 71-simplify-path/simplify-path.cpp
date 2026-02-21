class Solution {
public:
    string simplifyPath(string path) {
        stack<string>st;
        for(int i=0;i<path.length();i++){
            if(st.empty()){
                st.push(string(1, path[i]));
            }
            else if(st.top()=="/" && path[i] == '/'){
                continue;
            }
            else if(st.top()=="/"){
                string str = "";
                while(i<path.length() && path[i]!='/'){
                    str+=path[i];
                    i++;
                }
                i--;
                if(str == ".."){
                    if(!st.empty()) st.pop(); // popping first /
                    if(!st.empty()) st.pop(); // Popping the dir name
                    if(!st.empty()) st.pop(); //Popping last /
                }
                else if(str == "."){
                    if(!st.empty()) st.pop();
                    continue;
                }
                else{
                    st.push(str);
                }

            }
            else{
                st.push(string(1, path[i]));
            }
        }
        string result = "";
        vector<string>temp;
        while(!st.empty()){
            // result += st.top();
            temp.push_back(st.top());
            st.pop();
        }
        for(int i=temp.size()-1;i>=0;i--){
            result += temp[i];
        }
        // reverse(result.begin(), result.end());
        if(result.length()==1) return result;
        if(result == "") return "/";
        if(!result.empty() && result[result.length()-1]=='/'){
            return result.substr(0, result.length()-1);
        }
        return result;
    }
};