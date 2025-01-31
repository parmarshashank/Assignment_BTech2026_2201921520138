class Solution {
private:
    const int mod= 1337;
    int pow(int a, int b){
        if(b==1)
            return a%mod;
        if(b==0)
            return 1;
        if(b%2==0)
            return (pow(a, b/2)%mod)*(pow(a, b/2)%mod)%mod;
        return (a%mod)*pow(a, b-1)%mod;
    }
public:
    int superPow(int a, vector<int>& b) {
        int res=1;
        for(int i=b.size()-1; i>=0; i--){
            res= (res*pow(a, b[i]))%mod;
            a= pow(a, 10);
        }
        return res;
    }
};