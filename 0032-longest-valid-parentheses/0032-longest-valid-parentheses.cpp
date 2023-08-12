class Solution
{
public:
//idea:
// traverse string and push into stack the position of each '(', then when we meet ')' and stack is not empty, pop stack and place 1 at position of both ')' and '(' in one assumed array (which has size same as string and initially intialized to 0)
//then this question becomes finding longest continuous 1 in a 01 array
int longestValidParentheses(string s)
{
    int n=s.size();
    vector<int>nums(n,0); 
    stack<int> st; // stack to store the index of opening parentheses
    for(int i=0;i<n;i++) 
    {
        if (s[i]=='(') 
        {
            st.push(i); 
        } 
        else if(s[i]==')' && !st.empty()) 
        {
            nums[i] = 1; 
            nums[st.top()] = 1; 
            st.pop();
        }
    }

    vector<int>v;
    int cnt=0;
    for(int i=0;i<nums.size();i++)
    {
        if(nums[i]==1)
        {
                cnt++;
        }
        else
        {
            v.push_back(cnt);
            cnt=0;
        }
    }
    v.push_back(cnt);
    return *max_element(begin(v),end(v));
}
};