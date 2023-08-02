class MyCalendarTwo {
private:
    vector<pair<int,int>>events; //will store no triple booking events
    vector<pair<int,int>>doubleBookings; //will store double bookings
public:
    MyCalendarTwo() {}

    bool book(int start, int end) {
        //new event to check is [start,end)
        
        for(auto event:doubleBookings) //will not be executed untill doublebookings is empty
        {
            if(start<event.second && end>event.first) //new event causes triple booking
                return false;
        }

        for(auto event:events) 
        {
            if(start<event.second && end>event.first) //double booking occured
            {
                // we founded an overlap, add overlap event region to doubleBookings
                
                // A: [10, 20)
                // B:    [15, 25) ---> overlap from A and B is [15,20)
                // C:      [18, 30) new event will be checked with [15,20) above for loop
                int overlapStart = max(start, event.first);
                int overlapEnd = min(end, event.second);
                doubleBookings.push_back(make_pair(overlapStart, overlapEnd));
            }
        }

        // If there's no triple booking, add event to events vector and return true
        events.push_back(make_pair(start, end));
        return true;
    }
};
/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo* obj = new MyCalendarTwo();
 * bool param_1 = obj->book(start,end);
 */