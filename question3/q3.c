#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

#define MAXLINE 5000
#define MAXLEN 1000
#define ALLOCSIZE 10000
char *lineptr[MAXLINE];

int readlines(char *lineptr[], int nlines);
void writelines(char *lineptr[], int nlines);

void my_qsort(void *lineptr[], int left, int right, int (*comp)(void *, void *), int order);
            
int numcmp(char *, char *);
int strcmp_f(char *, char *);


int main(int argc, char *argv[])
{
    int nlines;
    int numeric = 0;
    int reverse = 0;
    int foldcase = 0;

    while (--argc > 0)
    {
        if (strcmp(*++argv, "-n") == 0)
        {
            numeric = 1;
        }
        else if (strcmp(*argv, "-r") == 0)
        {
            reverse = 1;
        }
        else if (strcmp(*argv, "-f") == 0)
        {
            foldcase = 1;
        }
    }

    if ((nlines = readlines(lineptr, MAXLINE)) >= 0)
    {
        my_qsort((void **) lineptr, 0, nlines-1, (int (*)(void *, void *))(numeric ? numcmp : (foldcase ? strcmp_f : strcmp)), reverse ? -1 : 1);
        writelines(lineptr, nlines);
        return 0;
    }
    else
    {
        printf("input too big to sort\n");
        return 1;
    }
    
    return 0;
}

int my_getline(char *, int);
char *alloc(int);


int readlines(char *lineptr[], int maxlines)
{
    int len, nlines;
    char *p, line[MAXLEN];

    nlines = 0;
    while ((len = my_getline(line, MAXLEN)) > 0)
    {
        if (nlines >= maxlines || (p = alloc(len)) == NULL)
        {
            return -1;
        }
        else
        {
            line[len-1] = '\0';
            strcpy(p, line);
            lineptr[nlines++] = p;
        }
    }
    return nlines;
}


void writelines(char *lineptr[], int nlines)
{
    int i;

    for (i = 0; i < nlines; i++)
        printf("%s\n", lineptr[i]);
}


int my_getline(char s[], int lim)
{
    int c, i;

    for (i = 0; i < lim-1 && (c = getchar()) != EOF && c != '\n'; ++i)
    {
        s[i] = c;
    }
    if (c == '\n')
    {
        s[i++] = c;
    }
    s[i] = '\0';

    return i;
}

static char allocbuf[ALLOCSIZE];
static char *allocp = allocbuf;
   
char *alloc(int n)
{
    if (allocbuf + ALLOCSIZE - allocp >= n)
    {
        allocp += n;
        return allocp - n;
    }
    else
    {        
        return 0;
    }
}

int numcmp(char *s1, char *s2)
{
    double v1, v2;

    v1 = atof(s1);
    v2 = atof(s2);
    if (v1 < v2)
    {
        return -1;
    }
    else if (v1 > v2)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int strcmp_f(char *s, char *t)
{
    for ( ; toupper(*s) == toupper(*t); s++, t++)
    {
        if (*s == '\0')
        {
            return 0;
        }
    }

    return toupper(*s) - toupper(*t);
}

void my_qsort(void *v[], int left, int right,
            int (*comp)(void *, void *), int order)
{
    int i, last;

    void swap(void *v[], int, int);

    if (left >= right)
    {
        return;
    }
    swap(v, left, (left + right)/2);
    last = left;
    for (i = left+1; i <= right;  i++)
    {
        if (order * (*comp)(v[i], v[left]) < 0)
        {
            swap(v, ++last, i);
        }
    }
    swap(v, left, last);
    my_qsort(v, left, last-1, comp, order);
    my_qsort(v, last+1, right, comp, order);
}

void swap(void *v[], int i, int j)
{
    void *temp;

    temp = v[i];
    v[i] = v[j];
    v[j] = temp;
}

