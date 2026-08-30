class Solution {
public: 
    bool ispalindrome(string s,int i,int j){
        string temp="";
        for(int k=i; k<=j; k++){
            temp=temp+s[k];
        }
        string nt=temp;
        reverse(temp.begin(),temp.end());
        return temp==nt;
    }
    int solve(string s,int i, int j ){
        if(i>=j)return 0;
        if(ispalindrome(s,i,j)==true)return 0;
        int mn=INT_MAX;
        for(int k=i; k<j; k++){
            int ta=solve(s,i,k)+solve(s,k+1,j)+1;
            if(ta<mn){
                mn=ta;
            }
        }
        return mn;
    }
    int minCut(string s) {
        int i=0; 
        int j=s.length()-1;
        int ans=solve(s,i,j);
        return ans;
    }
};