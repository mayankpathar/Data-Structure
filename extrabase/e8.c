// WAP to calculate an angle between hour and minute hand. (Hours and minutes should be
// taken from user)
// Angle=|30𝐻−5.5𝑀|

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int h, m;
    float angle;
    printf("enter the hour: ");
    scanf("%d", &h);
    printf("enter the minute: ");
    scanf("%d", &m);
    angle =abs(30 * h - 5.5 * m);

    if (angle > 180)
    {
        angle = 360 - angle;
    }
    printf("%f", angle);

    return 0;
}