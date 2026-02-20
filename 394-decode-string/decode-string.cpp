class Solution {
public:
    string recFun(string s, int &i){
        if(i>=s.length()) return "";
        // int index = 0;
        string res = "";
        
        while(i<s.length() && s[i]!=']'){
            if(!isdigit(s[i])) res+=s[i++];
            else{
                int num = 0;
                while(isdigit(s[i]))
                    num = num*10 + s[i++]-'0';
                i++;
                //Start decoding string
                string decoded = recFun(s, i);
                //Skipping ]
                i++;
                while(num--){
                    res+=decoded;
                }
            }
            // i++;
        }
        return res;
    }
    string stackMethod(string &s){
        stack<char>st;
        for(int i=0;i<s.length();i++){
            if(s[i] != ']'){
                st.push(s[i]);
                continue;
            }
            string str = "";
            while(!st.empty() && st.top()!='['){
                str+=st.top();
                st.pop();
            }
            reverse(str.begin(), str.end());
            st.pop(); //Popping extra [ bracket
            //Fetching number
            int num = 0;
            string numstr = "";
            while(!st.empty() && isdigit((unsigned char)st.top())){
                numstr+=st.top();
                st.pop();
            }
            reverse(numstr.begin(), numstr.end());
            if(numstr!=""){
                num = stoi(numstr);
                string expanded = "";
                for(int i=0;i<num;i++){
                    expanded+=str;
                }
                for(char c : expanded)
                    st.push(c);
            }
        }
        string res = "";
        while(!st.empty()){
            res+=st.top();
            st.pop();
        }
        reverse(res.begin(), res.end());
        return res;
    }
    string decodeString(string s) {
        // int index = 0;
        // return recFun(s,index);// Done with recursion

        return stackMethod(s);
    }
};