class MyCalendarThree {
   map<int,pair<int,int>> hash;
   int maxi = 1;
public:
    MyCalendarThree() {
         //hash[-1]=-1;
    }
    
    int book(int start, int end) {
        auto lower = hash.upper_bound(start);
        int count = 1;
        while (lower != hash.end() && lower->second.first < end)
        {   //* overlap mearge && update count/max
            // cout << lower->second.second << endl;
            if (start < lower->second.first)
            {
                hash[lower->second.first] = {start,count};
                start = lower->second.first;
            }
            else if (start > lower->second.first)
            {
                hash[start] = {lower->second.first,lower->second.second};
                lower->second.first = start;
            }
            if (lower->first <= end)
            {
                start = lower->first;
                lower->second.second += count;
                maxi = max(maxi,lower->second.second);
                if (start==end) return maxi;
            }
            else if (lower->first > end)
            {
                lower->second.first = end;
                count += lower->second.second;
                maxi = max(maxi,count);
                hash[end] = {start,count};
                return maxi;
            }
            lower = hash.upper_bound(start);
            //break;
        }
        hash[end]={start,count};
        return maxi;
    }
};

/**
 * Your MyCalendarThree object will be instantiated and called as such:
 * MyCalendarThree* obj = new MyCalendarThree();
 * int param_1 = obj->book(start,end);
 */