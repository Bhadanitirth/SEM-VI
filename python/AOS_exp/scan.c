#include<stdio.h>

int main()
{
   printf("enter the max-range\n");
   int mrange=0;
   scanf("%d",&mrange);
   printf("enter the no. of request\n");
   int asize=0;
    scanf("%d",&asize);
    int a[asize];
    for(int i=0;i<asize;i++){
        printf("enter the request\n");
        scanf("%d",&a[i]);
    }
    printf("the head position\n");
    int i=0;
    scanf("%d",&i);
    int start=i;
    int min=mrange;
    for(int j=0;j<asize;j++){
        if(a[j]<min){
            min=a[j];
        }
    }
    int counter=asize;
    while (counter>0){
        while(start<mrange+1){
            for(int j=0;j<5;j++){
                if(a[j]==start){
                    printf("%d\n",start);
                    a[j]=-1;
                    start++;
                    counter--;
                }
            }
            start++;
        }
        start--;
        while (start>0)
        {
            for(int j=0;j<5;j++){
                if(a[j]==start){
                    printf("%d\n",start);
                    a[j]=-1;
                    start--;
                    counter--;
                }
            }
            start--;
        }
        
    }
    printf("seek time %d\n",(100-i)+(100-min));
    return 0;
}