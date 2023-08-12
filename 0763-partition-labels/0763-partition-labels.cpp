class Solution {
public:
//"ababcbacadefegdehijhklij"
//a->8
// b->5
// c->7
// d->14 
// e->15
// f->11
// g->13
// h->19
// i->22
// j->23
// k->20
// l->21
    vector<int> partitionLabels(string s) {
        map<char, int> m;
        for (int i = 0; i < s.length(); i++) 
        {
            m[s[i]] = i;
        }
        vector<int> result;
        int partition_start = 0;        
        int partition_end = 0;
        for (int i = 0; i < s.length(); i++) 
        {
            partition_end = max(partition_end, m[s[i]]);
            if(i == partition_end) 
            {
                result.push_back(partition_end - partition_start + 1);
                partition_start = i + 1;
            }
        }
        return result;
    }
};