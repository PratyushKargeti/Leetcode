class Solution {
public:
    vector<long long> sumOfThree(long long num) {
        if(num%3!=0)
            return {};
        vector<long long>v;
        v.push_back((num/3)-1); 
        v.push_back((num/3));
        v.push_back((num/3)+1);
        return v;
    }
};