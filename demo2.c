#include <stdio.h>
 
int main()
{
    int a = 10;
    int b = 1002;
    printf("%d", a);
    printf("%d", b);
    for(int i = 0; i< 100; i++)
    {
        a = a + i;
        b = b + i;
        printf("%d", a);
        printf("%d", b);
    }
    /* 我的第一个 C 程序 */
    printf("Hello, World! \n");
 
    return 0;
}
