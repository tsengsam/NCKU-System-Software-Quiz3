#include <stdint.h>
#include <stdio.h>

/*
 * This function provide a flexibility that making arithmetic right shift (ASR)
 * avalible on different compliers or platforms
 */
int asr_i(signed int m, unsigned int n)
{
    const int logical = (((int) -1) >> 1) > 0;
    unsigned int fixu = -(logical & (m < 0));
    int fix = *(int *) &fixu;
    return (m >> n) | (fix ^ (fix >> n));
}

int main()
{
    int m, n;
    printf("Input m and n (m >> n)...");
    scanf("%d%d", &m, &n);
    printf("%d\n", asr_i(m, n));
}
