#include <stdio.h>

void ranges(int x[], int npts, int *max_ptr, int *min_ptr)
{
        int max_pts, min_pts, d;
        for(int i = 0; i < npts; i++)
        {
                min_pts = 0;
                for(int y = 0; y < npts; y++)
                {
                        if(x[i] <= x[y])
                        {
                                min_pts = min_pts + 1;
                        }
                }
                if(min_pts == npts)
                {
                        min_ptr = &x[i];
                        printf("The minimum value in this array is stored in the address %x and is %d.\n", min_ptr, *min_ptr);
                }
        }
        for(int i = 0; i < npts; i++)
        {
                max_pts = 0;
                for(int y = 0; y < npts; y++)
                {
                        if(x[i] >= x[y])
                        {
                                max_pts = max_pts + 1;
                        }
                }
                if(max_pts == npts)
                {
                        max_ptr = &x[i];
                        printf("The maximum value in this array is stored in the address %x and is %d.\n", max_ptr, *max_ptr);
                }
        }
        return;
}

int main()
{
        int max_ptr, min_ptr;
        printf("Case 1: \n");
        int a[] = {1, 5, 12, 15, 2, 13};
        ranges(a, 8, &max_ptr, &min_ptr);
        
        printf("Case 2: \n");
        int b[] = {9, 1, 3, 5, 22};
        ranges(b, 5, &max_ptr, &min_ptr);
        
        printf("Case 3: \n");
        int c[] = {9, 7, 5, 8, 6, 4, 10, 12};
        ranges(c, 8, &max_ptr, &min_ptr);
}

