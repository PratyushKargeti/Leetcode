class Solution {
public:
    int maxPower(string s) {
        int power=1;
        int currp=1;
        for(int i=1;i<s.size();i++)
        {
            if(s[i]==s[i-1])
            {
                currp++;
            }
            else
            {
                power=max(power,currp);
                currp=1;
            }
        }
        power=max(power,currp);
        return power;
    }
};