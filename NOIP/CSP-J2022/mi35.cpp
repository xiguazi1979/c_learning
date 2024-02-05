#include<stdio.h>
#include<math.h>
int main(){
    double x,x1,x2;
    scanf("%lf",&x);
    x1=x/2;
        while(1)
        {
             x2=(x1+x/x1)/2;
            if(fabs(x1-x2)<0.00001)break;
            x1=x2;
        }
        printf("%.3lf\n",x2);
    return 0;}