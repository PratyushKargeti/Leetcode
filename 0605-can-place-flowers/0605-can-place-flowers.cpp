class Solution {
public:
    bool canPlaceFlowers(vector<int>& fb, int n) {
        int count=0; 
        int size=fb.size();
        if( (size==1 && fb[0]==0) || (fb[0]==0 && fb[1]==0) )
        {
            fb[0]=1;  
            count++;
        }
        if(fb[size-1]==0 && fb[size-2]==0)
        {
            fb[size-1]=1;
            count++;
        }
        for(int i=1;i<size-1;i++) // handling middle element case
        {
            if(fb[i]==0 && fb[i-1]==0 && fb[i+1]==0)
            {
                    fb[i]=1;
                    count++;
            }
        }
        end:
        if(count>=n)
            return true;
        return false;
    }
};