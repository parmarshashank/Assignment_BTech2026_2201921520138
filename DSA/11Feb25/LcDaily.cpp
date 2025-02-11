class Solution {
    public:
        string removeOccurrences(string s, string part) {
            string st="";
            int n= part.size();
            char endWith= part[n-1];
            for(auto c: s){
                st+=c;
                if(c==endWith && st.size()>=n){
                    if(st.substr(st.size()-n)==part)
                        st.erase(st.size()-n);
                }
            }
            return st;
        }
    };