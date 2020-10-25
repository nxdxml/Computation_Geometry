//从y轴正无穷能看见多少条线 输出序号
/*
输入
3
-1 0
1 0
0 0
输出
1 2
*/
#include <bits/stdc++.h>
#define Max_Data 100005
using namespace std;
inline int read()
{
    int x = 0, f = 1;
    char ch = getchar();
    while (ch < '0' || ch > '9')
    {
        if (ch == '-')
            f = -1;
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9')
    {
        x = (x << 1) + (x << 3) + (ch ^ 48);
        ch = getchar();
    }
    return x * f;
}
int n;
struct node
{
    int k, b, id;
} a[Max_Data], s[Max_Data];
bool cmp2(node A, node B)
{
    return A.id < B.id;
}
double calc_x_intersection(node A, node B)
{
    return 1.0 * (B.b - A.b) / (1.0 * (A.k - B.k));
}
bool cmp(node A, node B)
{
    if (A.k != B.k)
        return A.k < B.k;
    return A.b > B.b;
}
int main()
{
    n=read();
    int i;
    for (i = 1; i <= n; i++)
    {
        a[i].k=read();
        a[i].b=read();
        a[i].id = i;
    }
    sort(a + 1, a + 1 + n, cmp);
    s[1] = a[1];
    int cnt = 1;
    for (i = 2; i <= n; i++)
        cout << calc_x_intersection(a[i - 1], a[i]) << "   ";
    {
        while (a[i].k == a[i - 1].k)
            continue;
        while (calc_x_intersection(s[cnt], a[i]) <= calc_x_intersection(s[cnt], s[cnt - 1]) && cnt > 1)
        {
            cnt--;
        }
        s[++cnt] = a[i];
    }
    sort(s + 1, s + cnt + 1, cmp2);
    for (int i = 1; i <= cnt; i++)
        printf("%d ", s[i].id);
    system("PAUSE");
    return 0;
}