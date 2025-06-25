class Solution {
public:
    //The strategy is to use Floyd's cycle detection algorithm (Tortiose and Hare)
    //If both numbers meet at 1, then it is a happy number
    //If they meet at any other number, then it is not a happy number
    int makeHappy(int n) {
        int sum = 0;
        while(n) {
            sum += pow(n%10,2);
            n /= 10;
        }
        return sum;
    } 
    bool isHappy(int n) {
        int slow = n;
        int fast = n;
        do {
            slow = makeHappy(slow);
            fast = makeHappy(makeHappy(fast));            
        }while(slow != fast);
        return (slow == 1);
    }
};