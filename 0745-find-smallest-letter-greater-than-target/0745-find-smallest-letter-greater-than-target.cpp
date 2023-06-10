class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        vector<int>ans;
        for(int i=0;i<letters.size();i++)
        {
            int x=letters[i]-'a';
            int y=target-'a';
            if(x>y)
                ans.push_back(letters[i]-'a');
        }
        if(ans.size()==0)
            return letters[0];
        return ans[0]+'a';
    }
};