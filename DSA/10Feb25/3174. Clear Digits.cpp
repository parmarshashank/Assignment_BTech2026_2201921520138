class Solution {
    public:
        string clearDigits(string s) {
            string ans="";
            int i=0;
            for(i=0; i<s.length(); i++){
                if(isdigit(s[i])){
                    for(int j=i; j>=0; j--){
                        if(!isdigit(s[j])){
                            s[j]='0';
                            break;
                        }
                    }
                }
            }
            for(auto c:s){
                if(!isdigit(c))
                    ans+=c;
            }
            return ans;
        }
    };
    