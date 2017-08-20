#include <stdio.h>
    #include <stdlib.h>
    
    void HeapAdjust(int num[], int parent, int last)
    {
        int child, temp;
        for(; parent*2+1<last; parent = child)
        {
            child = 2*parent + 1;
            if(child<last-1 && num[child]<num[child+1])
                child++;
            if(num[parent]<num[child])
            {
                temp = num[parent];
                num[parent] = num[child];
                num[child] = temp;
            }
                
        }
    }
    
    void HeapSort(int num[], int last)
    {
        int i, j, temp;
        for(i=last/2-1; i>=0; i--)
            HeapAdjust(num, i, last);
        for(j=last-1; j>0; j--)
        {
            temp=num[j];
            num[j]=num[0];
            num[0]=temp;
    
            HeapAdjust(num, 0, j);
        }
    }
    
    int main()
    {
        int length, i;
        int num[] = {13,22,65,43,278,47,85,67,99};
    
        length = sizeof(num)/sizeof(int);
    
        HeapSort(num, length);
        for(i=0; i<length; i++)
            printf("%d ",num[i]);
        return 0;
    }