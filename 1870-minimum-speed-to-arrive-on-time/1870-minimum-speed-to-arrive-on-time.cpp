class Solution {
public:
    double timefn(vector<int>& dist,int speed)
    {
        double time=0.0;
        for(int i=0;i<dist.size();i++)
        {
            double t=(double)dist[i]/double(speed);
            if(i==dist.size()-1) time+=t;
            else time+=ceil(t);
        }
        return time;
    }
    int minSpeedOnTime(vector<int>& dist, double hour) {
        int low=1;
        int high=1e7;
        int minSpeed=-1;
        while(low<=high)
        {
            int mid=low+(high-low)/2;
            if(timefn(dist,mid)<=hour)
            {
                minSpeed=mid;
                high=mid-1;
            }
            else
            {
                low=mid+1;
            }
        }
        return minSpeed;
    }
};