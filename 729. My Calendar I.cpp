class MyCalendar {
public:
    vector<pair<int,int>> calendar;
    MyCalendar() {
    }
    bool book(int st, int ed) {
        
        for(pair<int, int> curr : calendar){
            if(!(st>=curr.second || ed<=curr.first))
                return false;
        }   
        calendar.push_back({st, ed}); 
        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */