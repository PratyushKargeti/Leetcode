class Solution {
public:
    int solve(vector<int>&cookies,vector<int>&sums,int k,int ind,int zerocount)
    {
        //zerocount stores no. of children with no cookie
        if(zerocount > cookies.size()-ind) 
            return INT_MAX; //invalid distribution
        if(ind==cookies.size())
            return *max_element(sums.begin(),sums.end()); //fair answer return
        int res=INT_MAX;
        for(int i=0;i<k;i++) 
        { //ith child
            if(sums[i]==0) //if sum of cookies for this child is zero
                zerocount--; //we will give this child cookie
            sums[i]+=cookies[ind]; 
            res=min(res,solve(cookies,sums,k,ind+1,zerocount));
            sums[i]-=cookies[ind]; //backtrack 
            if(sums[i]==0) // if sum again becomes zero after backtrack
                zerocount++; //no of child with zero cookie increased again
        }
        return res;
    }
    int distributeCookies(vector<int>& cookies, int k) {
        vector<int> sums(k,0);
        return solve(cookies,sums,k,0,k);
    }
};