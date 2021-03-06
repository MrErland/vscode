/*
*问题描述：在Mars星球上，每个Mars人都随身佩带着一串能量项链。在项链上有N颗能量珠。
*能量珠是一颗有头标记与尾标记的珠子，这些标记对应着某个正整数。
*并且，对于相邻的两颗珠子，前一颗珠子的尾标记一定等于后一颗珠子的头标记。
*因为只有这样，这两颗珠子才能聚合成一颗珠子，同时释放出可以被吸盘吸收的能量。
*如果前一颗能量珠的头标记为m，尾标记为r，后一颗能量珠的头标记为r，尾标记为n，则聚合后释放的能量为m*r*n（Mars单位）
*新产生的珠子的头标记为m，尾标记为n。
*显然，不同的聚合顺序得到的总能量是不同的，请你设计一个聚合顺序，使一串项链释放出的总能量最大。
*例如：设N=4，4颗珠子的头标记与尾标记依次为(2，3) (3，5) (5，10) (10，2)。
*我们用记号⊕表示两颗珠子的聚合操作，(j⊕k)表示第j，k两颗珠子聚合后所释放的能量。
*则第4、1两颗珠子聚合后释放的能量为：(4⊕1)=10*2*3=60。
*这一串项链可以得到最优值的一个聚合顺序所释放的总能量为((4⊕1)⊕2)⊕3）=10*2*3+10*3*5+10*5*10=710。
*输入说明：第一行是一个正整数N（4≤N≤100），表示项链上珠子的个数。第二行是N个用空格隔开的正整数，所有的数均不超过1000。
*第i个数为第i颗珠子的头标记（1≤i≤N），当i<N< span>时，第i颗珠子的尾标记应该等于第i+1颗珠子的头标记。第N颗珠子的尾标记应该等于第1颗珠子的头标记。
*输出：一个正整数E（E≤2.1*109），为一个最优聚合顺序所释放的总能量。
*/


#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
const int N = 200;
static int dp[N][N];

int main()
{
	int n;
	cin >> n;
	vector<int> a(2 * n + 1);
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
		a[n + i] = a[i];			//数组表示环
	}
	int len, temp, i, j;
	for (len = 1; len < n; len++)			//聚合的数量
	{
		for (i = 1; i + len < 2 * n; i++)
		{
			temp = 0;
			for (j = i; j < i + len; j++)
				temp = max(temp, dp[i][j] + dp[j + 1][i + len] + a[i] * a[j + 1] * a[i + len + 1]);
			dp[i][i + len] = temp;
		}
	}
	int res = 0;
	for (i = 1; i <= n; i++)
	{
		if (dp[i][i + n - 1] > res)
			res = dp[i][i + n - 1];
	}
	cout << res;
	return 0;
}
