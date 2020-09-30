#include <stdbool.h>
#include <stdio.h>

/* Given a signed number and to calculate whether the input number
 * is the power of four or not
 * I implement two versions of function, one is solving by loops
 * and one is without loops
 */

bool isPowerOfFour_loop(int num)
{
    if (num <= 0)
        return false;
    for (int r = 0; num > 1; num /= 4) {
        if (num % 4)
            return false;
    }
    return true;
}

bool isPowerOfFour(int num)
{
    return num > 0 && (num & (num - 1)) == 0 && !(__builtin_ctz(num) & 0x1);
}

int main()
{
    printf("Input here...");
    int num;
    scanf("%d", &num);
    if (isPowerOfFour(num)) {
        printf("Yes\n");
    } else {
        printf("No\n");
    }
    return 0;
}
