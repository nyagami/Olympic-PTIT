#include<iostream>
using namespace std;
int main()
{
    int n;
    cin>>n;
    long long num;
    long long sum(0);
    for(int i(0);i<n;i++)
    {
        cin>>num;
        sum+=num;
    }
    cout<<-sum;
}
