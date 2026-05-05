class Solution {
public:
    int findpivote(vector<int>& nums, int n){

        int s = 0;
        int e = n-1;

        while(s < e){
            int mid = s + (e - s)/2;

            if(nums[mid] > nums[e]){
                s = mid + 1;
            }
            else{
                e = mid;
            }
        }

        return s;
    }

    int binarySearch(int s, int e, vector<int>& nums, int target){

        int idx = -1;

        while(s <= e){
            int mid = s + (e - s)/2;

            if(nums[mid] == target){
                return mid;
            }
            else if(nums[mid] < target){
                s = mid + 1;
            }
            else{
                e = mid -1;
            }
        }

        return idx;
    }
    int search(vector<int>& nums, int target) {
        int n = nums.size();

        int pivote = findpivote(nums, n);

        int idx = binarySearch(0, pivote - 1, nums, target);

        if(idx != -1){
            return idx;
        }

        idx = binarySearch(pivote, n-1, nums, target);

        return idx;
    }
};