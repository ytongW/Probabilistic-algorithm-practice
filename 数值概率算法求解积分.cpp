//
//  Created by wyt on 2018/11/14.
//  Copyright © 2018年 wyt. All rights reserved.
//

#include <iostream>
#include<iostream>
#include<ctime>
#include<cmath>
using namespace std;


double func(double x){
    return x*x+10;
}

double count(double x1, double x2, double y1, double y2,unsigned long n){
    unsigned long k = 0;
    srand((unsigned long)time(0));
    double area = (x2-x1) * y2;
    double x = 0.0;
    double y = 0.0;
    for (unsigned long i=0; i<n; ++i){
        x = rand()/(double)RAND_MAX;
        y = rand()/(double)RAND_MAX;
        x = (x2-x1)*x + x1;
        y = y2*y;
        if ( y <= func(x) )
            ++k;
        }
    return ((double)k/double(n))*area;
}

int main(){
    unsigned long num=100000;
    cout<<"func=x*x+10,[a,b]=[2,4];[c,d]=[14,26]. 精确值为38.66666667"<<endl;
    for (int i=0; i<5; ++i){
        cout<<"在随机总次数 n= "<<num<<" 时，函数的积分值为"<<count(2.0, 4.0, 14.0, 26.0, num)<<endl;
        num*=10;
    }
    system("pause");
    return 0;
}

