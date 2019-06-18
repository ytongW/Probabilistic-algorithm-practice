//
//  eightqueen
//
//  Created by wyt on 2018/11/19.
//  Copyright © 2018年 wyt. All rights reserved.
//

#include<iostream>
#include<iomanip>
#include<ctime>
#include<set>
#include<cmath>

#define QUEEN_H
using namespace std;


class Queen{
    friend bool nQueen(int, int);
    friend bool nQueen(int n, int stopVegas,int &VistedNodes);
    
    
    int getVistedNodes(){
        return vistedNodes;
    }
    
private:
    bool CanPlace(int k);  //测试皇后k置于第x[k]列的合法性
    bool Backtrack(int t); //回溯法
    bool QueensLV(int stopVegas); //Las Vegas算法
    int n;          //皇后个数
    int vistedNodes; //一次搜索成功或失败访问的节点数。
    int *x;         //解向量
    int *y;
};


bool Queen::CanPlace(int k){
    for( int j=1; j<k; ++j){
        if ((abs(k-j) == abs(x[j]-x[k])) || (x[j]==x[k]))
            return false;
    }
    ++vistedNodes;
    return true;
}


bool Queen::Backtrack(int t){//解n后问题的回溯法，开始放第t个皇后。
    if(t > n){
        for(int i=1; i<=n; ++i){
            y[i] = x[i];
        }
        return true;
    }else{
        for(int i=1; i<=n; ++i){
            x[t] = i;
            if( CanPlace(t) && Backtrack(t+1) ){
                return true;
            }
        }
    }
    return false;
}
bool Queen::QueensLV(int stopVegas){//Las Vegas算法
    int k = 1;
    int count = 1;
    while( (k <= stopVegas) && (count > 0) ){
        count = 0;
        for( int i = 1; i <= n; ++i){
            x[k] = i;
            if( CanPlace(k)){
                y[count++] = i;
            }
        }
        if( count > 0 ){
            x[k++] = y[rand()%count]; //选择一个可以的随机位置，放到k列上
        }
    }
    return (count>0);  //count>0 表示放置成功
}

bool nQueen(int n, int stopVegas,int &vistedNodes){//与回溯法相结合的解n后问题的LasVegas算法
    Queen X;
    X.n = n;
    X.vistedNodes = 0;
    int *p = new int[n+1];
    int *q = new int[n+1];
    for( int i=0; i <= n; ++i){
        p[i] = 0;
        q[i] = 0;
    }
    X.y = p;
    X.x = q;
    bool found = false;
    
    while(!X.QueensLV(stopVegas));
    
    //算法的回溯搜索部分
    if(X.Backtrack(stopVegas+1)){
        found = true;
        
    }
    delete[] p;
    delete[] q;
    vistedNodes = X.vistedNodes;
    return found;
}
void test(){
    for (int n=12; n<=20; ++n){
        cout<<"皇后个数 n="<<n<<endl;
        cout<<setw(10)<<"stopVegas"<<setw(20)<<"p"<<setw(20)<<"t"<<endl;
        for (int stopVegas=0; stopVegas<=n; ++stopVegas) {
            long failCount = 0;
            long sucessVistedNodes = 0;
            long failVistedNodes = 0;
            int vistedNodes =0;
            for (int j=0; j<10; ++j) {
                while (1) {
                    if (nQueen(n, stopVegas, vistedNodes)){
                        sucessVistedNodes += vistedNodes;
                        break;
                    }else{
                        failVistedNodes += vistedNodes;
                        ++failCount;
                    }
                }
            }
            double p = 10.0/(10.0+failCount);
            cout<<setw(10)<<stopVegas<<setw(20)<<p<<setw(20)<<(sucessVistedNodes*p+(1-p)*failVistedNodes)/10<<" "<<failCount/10<<endl;
        }
        for (int i=0; i<55; ++i)
            cout<<"-";
        cout<<endl;
    }
}

int main(){
    srand((unsigned int)time(0));
    
    test();
    
    return 0;
}

