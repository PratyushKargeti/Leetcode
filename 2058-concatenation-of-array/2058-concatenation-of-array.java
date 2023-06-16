class Solution {
    public int[] getConcatenation(int[] nums) {
        ArrayList<Integer> v= new ArrayList(2*nums.length);  
        for(int i=0;i<nums.length;i++)
        {
            v.add(nums[i]);
        }
        for(int i=0;i<nums.length;i++)
        {
            v.add(nums[i]);
        }
        int x=2*nums.length;
        int[] ans=new int[x];
        for(int i=0;i<v.size();i++)
        {
            ans[i]=v.get(i);
        }
        return ans;
    }
}