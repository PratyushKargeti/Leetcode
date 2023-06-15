class Solution {
    public void sortColors(int[] nums) {
        List<Integer> v= new ArrayList();
        for(int i=0;i<nums.length;i++)
        {
            v.add(nums[i]);
        }
        Collections.sort(v);
        for(int i=0;i<v.size();i++)
        {
            nums[i]=v.get(i);
        }
    }
}