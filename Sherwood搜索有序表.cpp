//
//  搜索有序表
//
//  Created by wyt on 2018/11/16.
//  Copyright © 2018年 wyt. All rights reserved.
//

#include<iostream>
#include<ctime>
#include<set>
#include<cmath>
#include<time.h>
using namespace std;

const int N = 7;
int val[N] = { 2, 3, 13, 1, 5, 21, 8};
int ptr[N] = { 2, 5, 6, 1, 7, 0, 3};

//设x≥val[i]且x在表中，则从位置i开始查找x的算法
int Search(int x, int i){
    while (x > val[i]){
        i = ptr[i];
    }
    return i;
}
//顺序查找
int A(int x){
    return Search(x, ptr[4]);
}



//在val数组的前sqrt(n)个元素中找y<=x的最大整数y，从y开始查找。
int B(int x){
    int i = ptr[0];
    int max = val[i];
    for (int j = 1; j <= (int)sqrt((double)N); ++j){
        int y = val[j];
        if (max < y && y <= x){
            i = j;
            max = y;
        }
    }
    return Search(x, i);
}

//从sqrt(n)个指针对应的val[ptr[i]]中找不超过x的最大整数y
int C(int x){
    int k,y;
    int i=4;
    int max = val[ptr[4]];
    for (int j = 1; j <= (int)sqrt((double)N); ++j){
        k = rand() % N;
        y = val[ptr[k]];
        if (y>max && x>=y){
            i = ptr[k];
            max = y;
        }
    }
    return Search(x, i);
}

//随机选一个指针位置(0~n-1)开始查找
int D(int x){
    int i = rand() % N;
    int y = val[i];
    if (x < y){
        return Search(x, ptr[0]);
    }
    else if (x > y){
        return Search(x, ptr[i]);
    }
    else{
        return i;
    }
    
}
int main(){
    int x=21;
    cout<<"请输入要查询的数";
    cin>>x;
    
    clock_t start,finish;
    double totaltime;
    
    start=clock();
    A(x);
    finish=clock();
    
    totaltime=(double)(finish-start)/CLOCKS_PER_SEC;
    cout<<"\n算法A的运行时间为"<<totaltime<<"s！"<<endl;
    
    start=clock();
    B(x);
    finish=clock();
    
    totaltime=(double)(finish-start)/CLOCKS_PER_SEC;
    cout<<"\n算法B的运行时间为"<<totaltime<<"s！"<<endl;
    
    start=clock();
    C(x);
    finish=clock();
    
    totaltime=(double)(finish-start)/CLOCKS_PER_SEC;
    cout<<"\n算法C的运行时间为"<<totaltime<<"s！"<<endl;
    
    start=clock();
    D(x);
    finish=clock();
    
    totaltime=(double)(finish-start)/CLOCKS_PER_SEC;
    cout<<"\n算法D的运行时间为"<<totaltime<<"s！"<<endl;

    system("pause");
    return 0;
    
}
