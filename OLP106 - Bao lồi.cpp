#include <bits/stdc++.h>
using namespace std;
/*Start*/
/*
   ██          ██
   █▒█        █▒█
  █▒███    ███▒█
  █▒████████▒▒█
  █▒████▒▒█▒▒██
  ████▒▒▒▒▒████
   █▒▒▒▒▒▒▒████
  █▒▒▒▒▒▒▒▒████      █
 ██▒█▒▒▒▒▒█▒▒████  █▒█
 █▒█●█▒▒▒█●█▒▒███ █▒▒█
 █▒▒█▒▒▒▒▒█▒▒▒██ █▒▒█
  █▒▒▒=▲=▒▒▒▒███ ██▒█
  ██▒▒█♥█▒▒▒▒███  ██▒█
    ███▒▒▒▒████    █▒█
      ██████        ███
       █▒▒████      ██
       █▒▒▒▒▒████ _██
       █▒██▒██████▒█
       █▒███▒▒▒█████
     █▒████▒▒▒▒████
      █▒███▒██████
*/
// #define int long long
// #define ll long long
// #define db double
// #define fi first
// #define se second

// typedef pair <int,int> ii;
// typedef vector<int> v;

// const ll oo=1e13;
// const int mod=1e9+7;
// const int N=1e6+5;

int di[] = {-1, 0, 0, 1, -1, -1, 1, 1};
int dj[] = {0, -1, 1, 0, -1, 1, -1, 1};
/**/
#define EPS 1e-6
const double PI = acos(-1.0);

double DEG_to_RAD(double d) { return d * PI / 180.0; }
double RAD_to_DEG(double r) { return r * 180.0 / PI; }

inline int cmp(double a, double b)
{
    return (a < b - EPS) ? -1 : ((a > b + EPS) ? 1 : 0);
}

struct Point
{
    double x, y;
    Point() { x = y = 0.0; }
    Point(double _x, double _y) : x(_x), y(_y) {}

    Point operator+(const Point &a) const { return Point(x + a.x, y + a.y); }
    Point operator-(const Point &a) const { return Point(x - a.x, y - a.y); }
    Point operator*(double k) const { return Point(x * k, y * k); }
    Point operator/(double k) const { return Point(x / k, y / k); }

    double operator*(const Point &a) const { return x * a.x + y * a.y; } // dot product
    double operator%(const Point &a) const { return x * a.y - y * a.x; } // cross product

    int cmp(Point q) const
    {
        if (int t = ::cmp(x, q.x))
            return t;
        return ::cmp(y, q.y);
    }

#define Comp(x) \
    bool operator x(Point q) const { return cmp(q) x 0; }
    Comp(>) Comp(<) Comp(==) Comp(>=) Comp(<=) Comp(!=)
#undef Comp

        Point conj()
    {
        return Point(x, -y);
    }
    double norm() { return x * x + y * y; }

    // Note: There are 2 ways for implementing len():
    // 1. sqrt(norm()) --> fast, but inaccurate (produce some values that are of order X^2)
    // 2. hypot(x, y) --> slow, but much more accurate
    double len() { return sqrt(norm()); }

    Point rotate(double alpha)
    {
        double cosa = cos(alpha), sina = sin(alpha);
        return Point(x * cosa - y * sina, x * sina + y * cosa);
    }
};
double area2(Point a, Point b, Point c)
{
    return a % b + b % c + c % a;
}
#ifdef REMOVE_REDUNDANT
bool between(const Point &a, const Point &b, const Point &c)
{
    return (fabs(area2(a, b, c)) < EPS && (a.x - b.x) * (c.x - b.x) <= 0 && (a.y - b.y) * (c.y - b.y) <= 0);
}
#endif

void ConvexHull(vector<Point> &pts)
{
    sort(pts.begin(), pts.end());
    pts.erase(unique(pts.begin(), pts.end()), pts.end());
    vector<Point> up, dn;
    for (int i = 0; i < (int)pts.size(); i++)
    {
        // Note: If need maximum points on convex hull, need to change >= and <= to > and <.
        while (up.size() > 1 && area2(up[up.size() - 2], up.back(), pts[i]) >= 0)
            up.pop_back();
        while (dn.size() > 1 && area2(dn[dn.size() - 2], dn.back(), pts[i]) <= 0)
            dn.pop_back();
        up.push_back(pts[i]);
        dn.push_back(pts[i]);
    }
    pts = dn;
    for (int i = (int)up.size() - 2; i >= 1; i--)
        pts.push_back(up[i]);

#ifdef REMOVE_REDUNDANT
    if (pts.size() <= 2)
        return;
    dn.clear();
    dn.push_back(pts[0]);
    dn.push_back(pts[1]);
    for (int i = 2; i < (int)pts.size(); i++)
    {
        if (between(dn[dn.size() - 2], dn[dn.size() - 1], pts[i]))
            dn.pop_back();
        dn.push_back(pts[i]);
    }
    if (dn.size() >= 3 && between(dn.back(), dn[0], dn[1]))
    {
        dn[0] = dn.back();
        dn.pop_back();
    }
    pts = dn;
#endif
}
double s(double c1, double c2, double c3)
{
    double p = (c1 + c2 + c3) / 2;
    p = p * (p - c1) * (p - c2) * (p - c3);
    p = sqrt(p);
    return p;
}
double d(Point a, Point b)
{
    double d1 = a.x - b.x;
    d1 *= d1;
    double d2 = a.y - b.y;
    d2 *= d2;
    return sqrt(d1 + d2);
}
/*Main*/
void init() {}
void solution()
{
    int n;
    cin >> n;
    vector<Point> a(n);
    for (auto &x : a)
        cin >> x.x >> x.y;
    ConvexHull(a);
    double c1, c2, c3, S = 0;
    for (int i = 1; i < a.size() - 1; i++)
    {
        c1 = d(a[0], a[i]);
        c2 = d(a[0], a[i + 1]);
        c3 = d(a[i], a[i + 1]);
        S += s(c1, c2, c3);
    }
    printf("%.3lf\n", S);
}
/**/
main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    int t = 1;
    cin >> t;
    while (t--)
    {
        init();
        solution();
    }
    return 0;
}
/*THE END*/
