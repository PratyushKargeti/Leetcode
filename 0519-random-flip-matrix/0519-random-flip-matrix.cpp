class Solution {
public:
    set<pair<int,int>>s; 
    int M,N;
    Solution(int m, int n) {
        M=m;
        N=n;
    }
    
    vector<int> flip() {
        int i=rand()%M;
        int j=rand()%N;
        while(s.count(make_pair(i,j))>0) //finding first random(i,j) absent from set
        {
            i=rand()%M;
            j=rand()%N;
        }
        s.insert(make_pair(i,j));
        return{i,j};
    }
    
    void reset() {
        s.clear();
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(m, n);
 * vector<int> param_1 = obj->flip();
 * obj->reset();
 */