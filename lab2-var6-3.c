#include <stdio.h>

int main() {
    double x, y;

    printf("Enter x and y: ");
    scanf("%lf %lf", &x, &y);

    if (x > 0 && y > 0)
        printf("1Q\n");
    else if (x < 0 && y > 0)
        printf("2Q\n");
    else if (x < 0 && y < 0)
        printf("3Q\n");
    else if (x > 0 && y < 0)
        printf("4Q\n");
    else if (x == 0 && y != 0)
        printf("Y axis\n");
    else if (y == 0 && x != 0)
        printf("X axis\n");
    else
        printf("Center (0,0)\n");

    return 0;
}