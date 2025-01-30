#include<bits/stdc++.h>
using namespace std;

int maxSubarraySumAfterOp(vector<int> &arr, int n){
    int maxSum=INT_MIN;
    int currSum=0;
    vector<int> temp(n, 0);
    for(int i=0; i<n; i++){
        currSum+=arr[i];
        if(currSum<0)
            currSum=0;
        if(arr[i]>0){
            temp[i]=currSum+arr[i];
        }
        else{
            temp[i]=currSum;
        }
    }
    for(auto it: temp)
        maxSum= max(it, maxSum);
    return maxSum;
}
int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0; i<n; i++){
        int temp;
        cin>>temp;
        arr[i]=temp;
    }
    int maxSum= maxSubarraySumAfterOp(arr, n);
    cout<<"The max sum after modification is: "<<maxSum<<endl;
    return 0;
}