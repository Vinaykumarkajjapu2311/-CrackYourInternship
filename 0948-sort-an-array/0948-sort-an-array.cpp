class Solution {
public:
    void merge(int low,int mid,int high,vector<int>&nums)
    {
        vector<int>temp;
        int left=low;
        int right=mid+1;
        while(left<=mid && right<=high)
        {
            if(nums[left]<=nums[right])
            {
                temp.push_back(nums[left]);
                left++;
            }
            else
            {
                temp.push_back(nums[right]);
                right++;
            }
        }
        while(left<=mid)
        {
            temp.push_back(nums[left]);
                left++;
        }
         while(right<=high)
        {
            temp.push_back(nums[right]);
                right++;
        }

        for(int i=low;i<=high;i++)
        {
            nums[i]=temp[i-low];
        }
    }
    void ms(int low,int high,vector<int>&nums)
    {
        if(low>=high)return;
        int mid=(low+high)/2;
        ms(low,mid,nums);
        ms(mid+1,high,nums);
        merge(low,mid,high,nums);
    }
    vector<int> sortArray(vector<int>& nums) {
        ms(0,nums.size()-1,nums);
        return nums;
    }
};