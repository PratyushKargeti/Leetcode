class Solution {
public:
    int countPrimes(int n) {
        int count=0;
        vector<bool> prime(n+1,true);//include all numbers from 0 to n
        prime[0]=prime[1]=false;
        for(int i=2;i<n;i++)
        {
            if(prime[i]==true)
            {
                count++;
                for(int j=2*i;j<n;j+=i)
                {
                    prime[j]=false;
                }//iterate through all multiples of i starting from 2*i up to n with a step size of i. For each multiple, set prime[j] to 'false' since it is a composite number. This is because all multiples of a prime number are composite numbers.
            }
        }  
        return count;
    }
};
