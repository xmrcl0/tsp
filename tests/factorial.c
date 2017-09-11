#include <stdio.h>
#include "utils.h"

int
main()
{
    int i;

    for(i = 0; i <= 100; i++)
        //printf("%4d! - %.0Lf\n", i, factorial(i));
        printf("%4d! - %.0Le\n", i, factorial(i));
}
