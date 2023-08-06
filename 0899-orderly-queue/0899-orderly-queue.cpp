class Solution {
public:
    //INTUITION:-
    
// Example for k > 1
// let string s = "rao", and k = 2
// the possible string that can be obtained using the given rule are, rao->aor->oar->ora->aro->roa
// which all are permutaion of the given string
    
    //for k = 1, rotate string character by character until we got original string back. At every move we put the rotated string into a vector of string. then we sort the vector and the string at index 0 will be our required string.
    
    string orderlyQueue(string s, int k) {
        if(k>1) //we can generate all permutation of string,smallest is sorted one obviously
        {
            sort(begin(s),end(s));
            return s;
        }
        //k==1 case
        vector<string>v;
        for(int i=0;i<s.size();i++)
        {
            char c=s[0];
            s.erase(begin(s));
            s+=c;
            v.push_back(s);
        }
        sort(begin(v),end(v));
        return v[0];
    }
};