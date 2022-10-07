class MyCalendarTwo {
public:
    map<int,int>mp;
    MyCalendarTwo() {
        
    }
    
    bool book(int start, int end) {
        int count = 0;
        mp[start]++;
        mp[end]--;
        for(auto &it: mp)
        {
            count += it.second ;
            if(count > 2)  
            {
                mp[start]-- ; 
                mp[end]++ ;
                return false ;
            }
        }
        return true;
    }
};

/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo* obj = new MyCalendarTwo();
 * bool param_1 = obj->book(start,end);
 */