#include <stdio.h>

struct point {
        int goals;
        int assists;
        int year;
} messi[] = {
        51, 86, 2007,
        55, 109, 2008,
        92, 113, 2009,
        71, 135, 2010,
        87, 118, 2011,
        73, 135, 2012,
        52, 163, 2013,
        62, 131, 2014,
        40, 109, 2015,
        54, 114, 2016,
        40, 102, 2017,
        41, 132, 2018,
        31, 90, 2019,
};

void averageassistsandgoals(struct point messi[]);
void minandmaxpoints(struct point messi[]);

int main()
{
        averageassistsandgoals(messi);
        minandmaxpoints(messi);
}

void averageassistsandgoals(struct point messi[])
{
        float suma, sumg, total;
        float averagea, averageg;
        total = 13;
        suma = messi[0].assists + messi[1].assists + messi[2].assists + messi[3].assists + messi[4].assists + messi[5].assists + messi[6].assists + messi[7].assists + messi[8].assists + messi[9].assists + messi[10].assists + messi[11].assists + messi[13].assists;
         averagea = suma / total;
        sumg = messi[0].goals + messi[1].goals + messi[2].goals + messi[3].goals + messi[4].goals + messi[5].goals + messi[6].goals + messi[7].goals + messi[8].goals + messi[9].goals + messi[10].goals + messi[11].goals + messi[13].goals;         
averageg = sumg / total;
        printf("messi had an average of %f assists and %f goals per year over his career.\n", averagea, averageg);
        return;
}

void minandmaxpoints(struct point messi[])
{
        int points[13];
        int min_points, max_points;
        for(int i = 0; i < 13; i++)
        {
                points[i] = messi[i].assists + messi[i].goals;
        }
        for(int j = 0; j < 13; j++)
        {
                min_points = 0;
                for(int k = 0; k < 13; k++)
                {
                        if(points[j] <= points[k])
                        {
                                min_points += 1;
                        }
                }
                if(min_points == 13)
                {
                        printf("messi's worst season was in %d when he got %d points. (%d goals and %d assists)\n", messi[j].year, points[j], messi[j].goals, messi[j].assists);
                }
        }
        for(int m = 0; m < 13; m++)
        {
                max_points = 0;
                for(int n = 0; n < 13; n++)
                {
                        if(points[m] >= points[n])
                        {
                                max_points += 1;
                        }
                }
                if(max_points == 13)
                {
                        printf("messi's best season was in %d when he got %d points. (%d goals and %d assists)\n", messi[m].year, points[m], messi[m].goals, messi[m].assists);
                }
        }
        return;
}

