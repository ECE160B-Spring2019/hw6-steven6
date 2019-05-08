#include <stdio.h>

struct point {
        int x;
        int y;
};

struct curve {
        struct point pt1;
        struct point pt2;
        struct point pt3;
        struct point pt4;
        struct point pt5;
        struct point pt6;
        struct point pt7;
        struct point pt8;
        struct point pt9;
        struct point pt10;
        struct point pt11;
};

struct point makepoint(int x, int a, int b, int c)
{
        struct point temp;
        temp.x = x;
        temp.y = (a*x*x) + (b*x) + c;
        return temp;
}

int main()
{
        int a, b, c;
        struct curve quadratic;
        struct point makepoint(int, int, int, int);
        
        printf("Enter a value for a: ");
        scanf("%d", &a);
        printf("Enter a value for b: ");
        scanf("%d", &b);
        printf("Enter a value for c: ");
        scanf("%d", &c);

        quadratic.pt1 = makepoint(-5, a, b, c);
        quadratic.pt2 = makepoint(-4, a, b, c);
        quadratic.pt3 = makepoint(-3, a, b, c);
        quadratic.pt4 = makepoint(-2, a, b, c);
        quadratic.pt5 = makepoint(-1, a, b, c);
        quadratic.pt6 = makepoint(0, a, b, c);
        quadratic.pt7 = makepoint(1, a, b, c);
        quadratic.pt8 = makepoint(2, a, b, c);
        quadratic.pt9 = makepoint(3, a, b, c);
        quadratic.pt10 = makepoint(4, a, b, c);
        quadratic.pt11 = makepoint(5, a, b, c);
        printf("The following are 11 points on your curve:\n(-5, %d)\n(-4,%d)\n(-3, %d)\n(-2, %d)\n(-1, %d)\n(0, %d)\n(1,%d)\n(2,%d)\n(3,%d)\n(4, %d)\n(5, %d)\n", quadratic.pt1.y, quadratic.pt2.y, quadratic.pt3.y, quadratic.pt4.y, quadratic.pt5.y, quadratic.pt6.y, quadratic.pt7.y, quadratic.pt8.y, quadratic.pt9.y, quadratic.pt10.y, quadratic.pt11.y);
        return 0;
}

