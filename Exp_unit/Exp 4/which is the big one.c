#include <stdio.h>
main()
{
    int x=4, y=6, z=7;
    int  u, v;
    
    if(x > y) u = x;
    else      u = y;
    if(u > z) v = u;
    else      v = z;

    printf("v=%d", v);
}


