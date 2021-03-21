/*
给定K个整数组成的序列{ N​1​​ , N​2​​ , ..., N​K​​  }，“连续子列”被定义为{ N​i​​ , N​i+1​​ , ..., N​j​​  }，
其中 1≤i≤j≤K。“最大子列和”则被定义为所有连续子列元素的和中最大者。例如给定序列{ -2, 11, -4, 13, -5, -2 }，其连续子列{ 11, -4, 13 }有最大的和20。
现要求你编写程序，计算给定整数序列的最大子列和。

本题旨在测试各种不同的算法在各种数据情况下的表现。各组测试数据特点如下：

数据1：与样例等价，测试基本正确性；
数据2：102个随机整数；
数据3：103个随机整数；
数据4：104个随机整数；
数据5：105个随机整数；
输入格式:
输入第1行给出正整数K (≤100000)；第2行给出K个整数，其间以空格分隔。

输出格式:
在一行中输出最大子列和。如果序列中所有整数皆为负数，则输出0。

输入样例:
6
-2 11 -4 13 -5 -2
输出样例:
20
*/
#include <stdio.h>
#include <stdlib.h>

void Read(int *L, int k)
{
    for (int i = 0; i < k; i++)
    {
        scanf("%d", L + i);
    }
}

void maxSeqSum(int L[], int k, int ret[])
{ // k: 数组长度
    int maxSum = 0, currentSum = 0;
    int start = 0, end = 0, zeroIndex = -1;

    for (int i = 0, j = 0; i < k; i++)
    {
        currentSum += L[i];
        if (L[i] == 0 && zeroIndex < 0)
            zeroIndex = i;
        if (currentSum > maxSum)
        {
            maxSum = currentSum;
            start = j;
            end = i;
        }
        if (currentSum < 0)
        {
            currentSum = 0;
            if (i < k - 1)
                j = i + 1;
        }
    }
    if (maxSum == 0 && end == 0)
    {
        if (zeroIndex > 0)
        {
            start = zeroIndex;
            end = zeroIndex;
        }
        else
        {
            end = k - 1;
        }
    }
    ret[0] = maxSum;
    ret[1] = L[start];
    ret[2] = L[end];
}

int main()
{
    int K;
    scanf("%d", &K);
    int L[K], ret[3];
    Read(L, K);
    maxSeqSum(L, K, ret);
    printf("%d %d %d\n", ret[0], ret[1], ret[2]);
    return 0;
}