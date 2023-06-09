//{ Driver Code Starts
// Program to find the maximum profit job sequence from a given array 
// of jobs with deadlines and profits 
#include<bits/stdc++.h>
using namespace std; 

// A structure to represent a job 
struct Job 
{ 
    int id;	 // Job Id 
    int dead; // Deadline of job 
    int profit; // Profit if job is over before or on deadline 
}; 


// } Driver Code Ends
/*
struct Job 
{ 
    int id;	 // Job Id 
    int dead; // Deadline of job 
    int profit; // Profit if job is over before or on deadline 
};
*/

class Solution 
{
    public:
   static bool compare(pair<int,int>a,pair<int,int>b)
{
    return a.first>b.first;
}
    //Function to find the maximum profit and the number of jobs done.
    vector<int> JobScheduling(Job arr[], int n) 
    { 
        vector<pair<int,int>>job;
        for(int i=0;i<n;i++)
        {
            int p=arr[i].profit;
            int d=arr[i].dead;
            job.push_back(make_pair(p,d));
        }
         sort(job.begin(),job.end(),compare);
    int max_dead=INT_MIN;
    //size of fill array = maxdeadline //so finding max deadline
    for(int i=0;i<n;i++)
    {
        if(job[i].second>max_dead)
            max_dead=job[i].second;
    } 
    vector<int> fill(max_dead,-1);
    int max_profit=0;
    int count=0;
    for(int i=0;i<n;i++)
    {
        //finding appropriate jth index in fill array for job i
        int j=job[i].second-1; // starting from ith job's deadline
        while(j>=0 && fill[j]!=-1) //job present at index j..
            j--; // finding earliest available slot
        
        if(j>=0)
        {
            fill[j]=i;
            count++;
            max_profit+=job[i].first;
        }
    }
    return {count,max_profit};
    } 
};

//{ Driver Code Starts.
// Driver program to test methods 
int main() 
{ 
    int t;
    //testcases
    cin >> t;
    
    while(t--){
        int n;
        
        //size of array
        cin >> n;
        Job arr[n];
        
        //adding id, deadline, profit
        for(int i = 0;i<n;i++){
                int x, y, z;
                cin >> x >> y >> z;
                arr[i].id = x;
                arr[i].dead = y;
                arr[i].profit = z;
        }
        Solution ob;
        //function call
        vector<int> ans = ob.JobScheduling(arr, n);
        cout<<ans[0]<<" "<<ans[1]<<endl;
    }
	return 0; 
}



// } Driver Code Ends