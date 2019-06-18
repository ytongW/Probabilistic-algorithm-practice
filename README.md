# Probabilistic-algorithm-practice
分享一下学习概率算法时做的一些实验～
共有数字概率算法、Monte Carlo算法、Las Vegas算法以及Sherwood算法四部分：  
## 1. 数字概率算法  
这类算法主要用于找到一个数字问题的近似解，这里我上传了经典的求解积分的代码以及估计整数子集的大小的代码。  
## 2. Monte Carlo算法  
该算法无论对任何实例均能以高概率找到正确解，适用于那些无论是确定的还是概率的，均找不到有效算法来获得正确答案的问题，但当算法出错时，没有任何警告信息，这里我实现的是素数测定问题，打印了100~10000以内的所有素数，并且计算了其中判断错误的比例。
## 3. Las Vegas算法  
该算法要么返回正确解，要么随机决策导致一个僵局。其成功的概率随着执行时间的增加而增加。我用这一算法来实践了八皇后问题，由于单纯的Las Vegas算法求解八皇后问题比较消极，一旦失败就要从头再来，因此我选择结合Las vegas算法与传统的回溯法，先用Las vegas算法随机放置一些皇后，再用回溯法放置剩下的皇后，并且计算了先用Las vegas算法放多少皇后可以实现最高的效率。

## 4. Sherwood算法
该算法用于平滑不同输入实例的执行时间。这里我实现的是搜索有序表。
