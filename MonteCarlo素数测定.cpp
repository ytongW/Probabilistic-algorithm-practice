//
//  判素错误比例
//
//  Created by 魏俣童 on 2018/11/17.
//  Copyright © 2018年 魏俣童. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
using namespace std;
static int count1;
static int count2;

bool Btest(int a, int n){
    int s=0,t=n-1;
    unsigned long long x=1;
    while(t%2!=1 ){
        s=s+1;
        t=t/2;
    }
    while(t){
        x=(x*a)%n;
        t=t-1;
    }
    if(x==1 or x==(n-1)){
        return true;
    }
    for(int i=1;i<=(s-1);i++){
        x=(x*x)%n;
        if(x==(n-1)){
            return true;
        }
    }
    return false;
}

bool MillRab(int m){
    int a;
    a=rand()%(m-3);
    a=a+2;
    return Btest(a, m);
}

bool RepeatMillRob(int l,int k){
    int j;
    for(j=1;j<=k;j++){
        if (MillRab(l)==false) {
            return false;
        }
    }
    return true;
}

bool panduan(int n)
{
    for (int j=2; j<= (int) sqrt((double)n); ++j)
    {
        if ( n%j == 0)
        {
            return false;
        }
    }
    return true;
}

int Print(){
    int temp,h;
    for (h=5; h<=10000; ) {
        temp=(int)log(h);
        if (RepeatMillRob(h, temp) and (h>100)) {
            count1++ ;
            printf("%d,",h);
            if (panduan(h)==false) {
                count2++;
            }
        }
        h=h+2;
    }
    return 0;
}


int main(){
    count1=0;
    count2=0;
    Print();
    double percent=0;
    percent=(double )count2/(double)count1;
    printf("输出素数个数为%d\n",count1);
    printf("其中错误的个数为%d\n",count2);
    printf("错误比例为%f\n",percent);
    return 0;
}


