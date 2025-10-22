class Solution {
public:
    string myMethod(string &s, string &sub){
        string res = "";
        int index = 0;
        for(int i=0;i<s.length();i++){
           
            res.push_back(s[i]);
            int resLength = res.length();
            int subLength = sub.length();
            if(resLength>=subLength && res.substr(resLength-subLength,subLength)==sub){
                res.erase(resLength-subLength);
                // res.push_back(s[i]);
            }
            // else{
            //     // res[index++] = s[i];
            //     res.push_back(s[i]);
            // }
        }
        return res;
    }
    string courseSoln(string &s,string sub){
        while(s.find(sub)!=string::npos){
            s.erase(s.find(sub),sub.length());
        }
        return s;
    }
    void recursiveMethod(string &s, string &part){
        


        int found = s.find(part);
        if(found!=string::npos){
            string left_part = s.substr(0,found);
            string right_part = s.substr(found+part.length(),s.length());
            s = left_part + right_part;
            recursiveMethod(s,part);
        }
        else{
            //All part is  removed from main string 
            return;
        }
    }
    string removeOccurrences(string s, string part) {
        // return courseSoln(s,part); //O(N*M)
        // return myMethod(s,part); //O(N*M)
        recursiveMethod(s,part);
        return s;
    }
};