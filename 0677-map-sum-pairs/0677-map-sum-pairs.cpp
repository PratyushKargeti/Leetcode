class MapSum {
public:
    unordered_map<string,int>m;
    MapSum() {
        
    }
    
    void insert(string key, int val) {
        m[key]=val;
    }
    
    int sum(string prefix) {
        int ans=0;
        for(auto c:m)
        {
            string str=c.first;
            for(int j=0;j<str.size();j++)
            {
                if(str.substr(0,j+1)==prefix)
                    ans+=c.second;
            }
            
            // for(int i=0;i<1;i++)
            // {
            //     for(int j=i;j<str.size();j++)
            //     {
            //         if(str.substr(i,j-i+1)==prefix)
            //             ans+=c.second;
            //     }
            // }
        }
        return ans;
    }
};

/**
 * Your MapSum object will be instantiated and called as such:
 * MapSum* obj = new MapSum();
 * obj->insert(key,val);
 * int param_2 = obj->sum(prefix);
 */