class Solution {

  public:
  int helper(vector<int>&arr,int n,int target,vector<vector<int>>&help){
      if(n>=arr.size()){
          return target;
      }
      if(help[n][target]!=-1){
          return help[n][target];
      }
    //   pick
    int a=INT_MAX;
    if(arr[n]<=target){
        a=helper(arr,n+1,target-arr[n],help);
        
    }
    int b=helper(arr,n+1,target,help);
    
    return help[n][target]=min(a,b);
      
  }
    int minDifference(vector<int>& arr) {
       
        int sum=0;
        for(int i=0;i<arr.size();i++){
            sum+=arr[i];
        }
        int truesum=sum;
        sum=sum/2;
         vector<vector<int>>help(arr.size(),vector<int>(sum+1,-1));
        int a=helper(arr,0,sum,help);
        a=sum-a;
       int b=truesum-a;
       return b-a;
        // Your code goes here
    }
};


