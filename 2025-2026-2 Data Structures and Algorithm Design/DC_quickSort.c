#include<stdio.h>
#include<stdlib.h>

void quickSort(double * start,double * end)
{
    double temp;
    if (start<end)
    {
        if (end==start+1)
        {
            if (*start>*end)
            {
                temp=*start;
                *start=*end;
                *end=temp;
            }
        }
        else
        {
            double * low=start;
            double * high=end;
            double pivot=*start;
            while (1)
            {
                for (;(*high>=pivot)&&(high!=low);high--);
                if (high==low)
                {
                    *low=pivot;
                    break;
                }
                else
                {
                    *low=*high;
                }
                for(;(*low<=pivot)&&(low!=high);low++);
                if (low==high)
                {
                    *high=pivot;
                    break;
                }
                else
                {
                    *high=*low;
                }
            }
            quickSort(start,low-1);
            quickSort(high+1,end);
        }
    }
}

#define N 10

int main()
{
    
    double A[N]={20.108030589542736, 6.4118506526379075, 7.045802592059925, 24.04279885107584, 63.49046817993628, 34.36118188493699, 79.26441826471836, 25.545152039701346, 99.15613809468131, 37.74037075492818};
    quickSort(&A[0],&A[N-1]);
    for (int i=0;i<=N-1;i++)
    {
        printf("%f\n",A[i]);
    }
}
