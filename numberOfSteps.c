/* Given a non-negative integer num, return the number of steps to reduce it to
 * zero. If the current number is even, divide it by 2, otherwise, subtract 1
 * from it. Assume num is 32 bits width
 */
#include <stdio.h>

/* I implement 2 versions, one makes use of gcc extension
 * and the other one use while-loop
 */
int numOfSteps_loop(int num)
{
    int cnt = 0;
    while (num) {
        cnt++;
        if (num % 2) {
            num -= 1;
        } else {
            num = num >> 1;
        }
    }
    return cnt;
}

int numOfSteps(int num)
{
    return num ? __builtin_popcount(num) + 31 - __builtin_clz(num) : 0;
}

int main()
{
    printf("Input...");
    int num;
    scanf("%d", &num);
    printf("Ans = %d\n", numOfSteps_loop(num));
}
