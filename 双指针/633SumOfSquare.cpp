

/*
给定一个非负整数 c ，你要判断是否存在两个整数 a 和 b，使得 a2 + b2 = c 。
*/

class Solution {
public:
    bool judgeSquareSum(int c) {
        int fir=0,end=sqrt(c);
        while(fir<=end){
            if(pow(fir,2)+pow(end,2)==c) return true;
            else if (pow(fir,2)+pow(end,2)<c) fir++;
            else end--;
        }
        return false;
    }
};