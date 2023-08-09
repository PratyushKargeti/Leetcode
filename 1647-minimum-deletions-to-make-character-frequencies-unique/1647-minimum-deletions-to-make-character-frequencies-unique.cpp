class Solution {
public:
    int minDeletions(string s) {
        unordered_map<char,int> m;
        for(int i=0;i<s.size();i++) 
        {
            m[s[i]]++;
        }
        priority_queue<int> pq; //max heap
        for(auto i : m) 
        {
            pq.push(i.second);
        }
        
        int cnt = 0;
        while(!pq.empty()) 
        {
            int maxfreq = pq.top();
            pq.pop();

            if(pq.empty()) break;

            // If the current frequency is the same as the next one,
            // we decrease the current frequency and add it back to the queue   
            if(pq.top()==maxfreq)
            {
                cnt++;
                if(maxfreq>1) 
                {
                    pq.push(maxfreq-1);
                }   
            }
        }
        return cnt;
    }
};
