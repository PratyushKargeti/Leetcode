class Solution {
public:
    typedef long long ll;
    Solution() {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
    }
    long long putMarbles(vector<int>& weights, int k) {
        int n=weights.size();
        vector<ll>v;
        for(int i=0;i<n-1;i++) //put sum of adjacent pairs in vector
        {
            v.push_back(weights[i]+weights[i+1]);
        }
        priority_queue<ll>pq1; //max heap (descending)
        priority_queue<ll,vector<ll>,greater<ll>>pq2; //min heap (ascending)
        for(int i=0;i<v.size();i++) 
        {
            pq1.push(v[i]); 
            pq2.push(v[i]);
        }
        ll summax=0;
        ll summin=0;
        k--; //since we have k-1 splitpoints in k subarrays
        while(k--)
        {
            summax+=pq1.top();
            summin+=pq2.top();
            pq1.pop();
            pq2.pop();
        }
        ll ans=summax-summin;
        return ans;
    }
};