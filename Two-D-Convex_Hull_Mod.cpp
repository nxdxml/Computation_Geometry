#include <bits/stdc++.h>
#define Max_Data 10005
using namespace std;

int n;
double ans;

struct Point
{
    double x, y;
} p[Max_Data], s[Max_Data];
typedef Point Vect;
// 叉乘右手定则从前转到后，指向外为正
double Multiplication_Cross(Point A1, Point A2, Point B1, Point B2)
{
    double x1 = A2.x - A1.x;
    double y1 = A2.y - A1.y;
    double x2 = B2.x - B1.x;
    double y2 = B2.y - B1.y;
    return x1 * y2 - y1 * x2;
}
double Distance(Point A, Point B)
{
    return sqrt((A.x - B.x) * (A.x - B.x) + (A.y - B.y) * (A.y - B.y));
}
bool cmp(Point v1, Point v2)
{
    double tmp = Multiplication_Cross(p[1], v1, p[1], v2);
    if (tmp > 0)
        return 1;
    if (tmp == 0)
    {
        // 一条线的时候短的排在前面
        return Distance(p[1], v1) < Distance(p[1], v2);
    }
    return 0;
}
void My_Swap(Point &A, Point &B)
{
    double tmp;
    tmp = A.x;
    A.x = B.x;
    B.x = tmp;
    tmp = A.y;
    A.y = B.y;
    B.y = tmp;
}
int main()
{
    cin >> n;
    cin >> p[1].x >> p[1].y;
    for (int i = 2; i <= n; i++)
    {
        cin >> p[i].x >> p[i].y;
        if (p[i].y < p[1].y)
            My_Swap(p[1], p[i]);
    }
    sort(p + 2, p + 1 + n, cmp);
    int cnt = 1;
    s[1] = p[1];
    for (int i = 2; i <= n; i++)
    {
        // 右拐弹出，可弹多个
        while (cnt > 1 && Multiplication_Cross(s[cnt - 1], s[cnt], s[cnt], p[i]) <= 0)
            cnt--;
        cnt++;
        s[cnt] = p[i];
    }
    s[++cnt] = p[1];
    for (int i = 2; i <= cnt; i++)
        ans += Distance(s[i - 1], s[i]);
    printf("%.2lf\n", ans);
    system("PAUSE");
    return 0;
}