class Solution {
public:
    bool canEat(vector<int>& piles, int mid, int h){
        int actualH = 0;

        for(int &x: piles){
            actualH = actualH + x/mid;

            if((x % mid) != 0){
                actualH ++;
            }
        }
        return actualH <= h;

    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int s = 1;
        int e = *max_element(begin(piles), end(piles));

        while(s < e){
            int mid = s + (e - s)/2;

            if(canEat(piles, mid, h)){
                e = mid;
            }
            else{
                s = mid+1;
            }
        }

        return s;
    }
};