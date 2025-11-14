class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> a;
        deque<int> q;
        if(nums.size()==0){
            return a;
        }
        int i=0;
        for(i;i<min((int)nums.size(),k);i++){
            while(!q.empty()&&q.back()<nums[i]){
                q.pop_back();
            }
            q.push_back(nums[i]);
            
            
        }
        a.push_back(q.front());
        for(i;i<nums.size();i++){
            if(!q.empty()&&q.front()==nums[i-k]){
                q.pop_front();
            }
            while(!q.empty()&&q.back()<nums[i]){
                q.pop_back();
            }
            q.push_back(nums[i]);
            
            a.push_back(q.front());
        }
        return a;
    }
};