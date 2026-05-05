#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();

        int majo = nums[0];
        int count = 1;

        for(int i=1; i<n; i++){
            if(count == 0){
                majo = nums[i];
                count = 1;
            }
            else if(nums[i] == majo){
                count ++;
            }
            else{
                count --;
            }
        }

        return majo;
    }
};