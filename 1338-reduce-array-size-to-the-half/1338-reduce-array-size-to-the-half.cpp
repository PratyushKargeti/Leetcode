class Solution {
public:
    int minSetSize(vector<int>& arr) {
        unordered_map<int,int>m;
        for(int i=0;i<arr.size();i++)
        {
            m[arr[i]]++;
        }
        priority_queue<int>pq; //create max heap (descending order)
        for(auto i:m)
        {
            pq.push(i.second);
        }
        int count=0;
        int sumofsizes=0;
        while(!pq.empty())
        {
            sumofsizes+=pq.top();
            if(sumofsizes<(arr.size()/2))
                count++;
            else
            {
                count++; //breakpoint will also be included
                break;
            }
            pq.pop();
        }
        return count;
        // sort(v.begin(),v.end(),greater<int>());
        // //set<int>S;
        // int sum=0;
        // int c=0;
        // for(int i=0;i<v.size();i++)
        // {   
        //     sum+=v[i];
        //     if(sum<(arr.size()/2))
        //     {
        //         c++;
        //     }
        //     else
        //     {
        //         c++;
        //         break;
        //     }
        // }
        // return c;
    }
};