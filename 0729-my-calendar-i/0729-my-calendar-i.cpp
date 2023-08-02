class MyCalendar {
public:
    vector<pair<int,int>> events;
    MyCalendar() {
        
    }
    
    bool book(int start, int end) {
        for(auto event:events)  //for very first event for loop is not executed
        {
            if(start<event.second && end>event.first)  //overlapping condition
                return false;
        }
        // cout<<start<<" "<<end<<endl;
        
        // no overlap, add event to vector and return true
        events.push_back(make_pair(start,end));
        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */