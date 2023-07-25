class Solution {
public:
//     Input: s = "lEetcOde"
// Output: "lEOtcede"

    string sortVowels(string s) {
        string ans(s);
        priority_queue<char,vector<char>,greater<char>>pq; //min heap
        for(int i=0;i<ans.size();i++)
        {
            if(ans[i]=='A' || ans[i]=='E' || ans[i]=='I' || ans[i]=='O' || ans[i]=='U' || ans[i]=='a' || ans[i]=='e' || ans[i]=='i' || ans[i]=='o' || ans[i]=='u')
            {
                pq.push(ans[i]); 
               ans[i]='0'; //setting markers         
            }
        }
        if(pq.empty()) return ans; //no need to update
        
        // cout<<ans<<endl;
        // while(!pq.empty())
        // {
        //     cout<<pq.top()<<" ";
        //     pq.pop();
        // }

        for(int i=0;i<ans.size();i++)
        {
            if(ans[i]=='0')
            {
                ans[i]=pq.top();
                pq.pop();
            }     
        }
        return ans;
    }
};