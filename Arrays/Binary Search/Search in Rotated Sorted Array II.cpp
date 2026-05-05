class Solution {
public:
    int findPivote(vector<int>& nums, int l, int r){
       
        while(l < r){

            while(l < r && nums[l] == nums[l+1]){
                l++;
            }

            while(l < r && nums[r] == nums[r - 1]){
                r--;
            }

            int mid = l + (r - l)/2;

            if(nums[mid] > nums[r]){
                l = mid + 1;
            }
            else{
                r = mid;
            }
        }

        return r;
    }
    bool binarySearch(vector<int>& nums, int l, int r, int tar){

        while(l <= r){
            int mid = l + (r - l)/2;

            if(nums[mid] == tar){
                return true;
            }
            else if(nums[mid] < tar){
                l = mid + 1;
            }
            else{
                r = mid - 1;
            }
        }

        return false;
    }

    bool search(vector<int>& nums, int target) {
        int n = nums.size();

        int pivote = findPivote(nums, 0, n-1);

        if(pivote > 0 && binarySearch(nums, 0, pivote - 1, target)){
            return true;
        }

        return binarySearch(nums, pivote, n-1, target);
    }
};