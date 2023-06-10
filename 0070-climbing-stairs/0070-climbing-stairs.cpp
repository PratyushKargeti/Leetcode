class Solution {
public:
    // int fib(int n)
    // {
    //     if(n<=1)
    //     return n;
    //     else
    //     return fib(n-1)+fib(n-2);
    // }
    int climbStairs(int n) {
        // int x=n+1;
        // return fib(x);

       int arr[n+1];
       arr[0]=1;
       arr[1]=1;
       for(int i=2;i<=n;i++)
       {
           arr[i]=arr[i-1]+arr[i-2];
       } 
       return arr[n];
    
    }
};