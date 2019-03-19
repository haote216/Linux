#include"Date.h"
int main()
{
    Date d1(2019,3,19);
    Date d3(2019,1,1);
    Date d2;
    d2=d1++;
    d2.Print(d2);
    d2=++d3;
    d2.Print(d2);
    int m=d3-d1;
    cout<<"day:"<<m<<endl;
    return 0;
}
