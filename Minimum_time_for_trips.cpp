typedef long long ll;
class Solution {
public:
    bool helper(vector<int>& time, int totalTrips, ll mid){
        ll cnt = 0;
        for(int i=0; i<time.size(); ++i){
            cnt += mid/time[i];
            if(cnt >= totalTrips) return true;
        }
        return cnt >= totalTrips;
    }
        
    long long minimumTime(vector<int>& time, int totalTrips) {
        ll l = 1, r = LLONG_MAX, ans = 0;
        while(l<=r){
            ll mid = l + (r-l)/2;
            if(helper(time, totalTrips, mid)){
                r = mid-1;
                ans = mid;
            }else{
                l = mid+1;
            }
        }
        
        return ans;
    }
};
