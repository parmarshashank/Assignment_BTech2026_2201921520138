class Solution {
public:
    int maxTurbulenceSize(vector<int>& arr) {
        int n= arr.size();
        if(n==0)
            return 0;
        int curr1= 1, curr2= 1, max1= 1, max2= 1;
        for(int k=0; k<n-1; k++){
            if(k%2){
                if(arr[k]>arr[k+1])
                    curr1++;
                else
                    curr1=1;
            }
            else{
                if(arr[k]<arr[k+1])
                    curr1++;
                else
                    curr1=1;
            }
            max1= max(max1, curr1);
        }

        for(int k=0; k<n-1; k++){
            if(k%2){
                if(arr[k]<arr[k+1])
                    curr2++;
                else
                    curr2=1;
            }
            else{
                if(arr[k]>arr[k+1])
                    curr2++;
                else
                    curr2=1;
            }
            max2= max(max2, curr2);
        }
    return max(max1, max2);
    }
};