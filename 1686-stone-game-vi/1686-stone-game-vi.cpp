class Solution {
public:
    //player strategy would be maximising his score but at the same time
    //minimising opponent's score that he can attain in next move
    //so we pick index with largest sum of alicevalues & bobvalues
    int stoneGameVI(vector<int>& a, vector<int>& b) {
        int n=a.size();
        priority_queue<pair<int,int>>pq;//max heap(descending order)
        for(int i=0;i<n;i++)
        {
            pq.push(make_pair(a[i]+b[i],i));
        }
        int player=0; //for current player Alice
        int as=0,bs=0;//alicescore & bobscore
        while(!pq.empty())
        {
            int ind=pq.top().second; //optimal index for current player
            if(player==0)
                as+=a[ind];
            else
                bs+=b[ind];
            pq.pop();
            player=1-player;
        }
        if(as>bs) return 1;
        else if(bs>as) return -1;
        else return 0;
    }
};