class Solution {
    public boolean isMatch(String s, String p) {
        // String[] v=s.split("\\.|*");
        // String ans="";
        // for(int i=0;i<v.length;i++)
        // {
        //     ans+=v[i];
        // }
        // if(ans==s)
        //     return true;
        // return false;
        return s.matches(p);
    }
}