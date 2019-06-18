//
//  估计整数子集大小.cpp
//
//  Created by wyt on 2018/11/15.
//  Copyright © 2018年 wyt. All rights reserved.
//

#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<time.h>
#define N 1000000

int main()
{
    unsigned int k,i;
    unsigned int record[N]={0};
    unsigned int uniform;
    unsigned int n,m;
    unsigned int size;
    
    printf(" 输入集合大小：");
    scanf("%d",&n);
    srand( (unsigned)time(NULL));
    for(i=0;i<n;i++)
    {
        uniform=rand()*rand()%n;
        for(k=0;k<n;k++)
        {
            if(record[k]==uniform)
            {
                size = 2*i*i/3.14;
                printf(" 集合估计大小：%d\n",size);
                return 0;
            }
        }
        record[i]=uniform;
    }
    return 0;
}
