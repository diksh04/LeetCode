class MyCalendarThree {
public:
    map<int,int>mp;
    MyCalendarThree() {
        
    }
    
    int book(int start, int end) {
        int ans=0 , count=0 ;
        mp[start]++ ;
        mp[end]-- ;
        for(auto &it : mp)
        {
            count += it.second ;
            ans = max(ans , count) ;
        }
        return ans ;
    }
};

/**
 * Your MyCalendarThree object will be instantiated and called as such:
 * MyCalendarThree* obj = new MyCalendarThree();
 * int param_1 = obj->book(start,end);
 */