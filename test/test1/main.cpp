#include"Date.h"
int main()
{
    Date d1(2019,3,20);
    Date d2(2019,3,20);
    Date d3(2019,3,20);
    Date d4(2019,3,20);
    d1.Print(d1);
    d2.Print(d2);
    d3=d1++;
    d4=++d2;
    d3.Print(d3);
    d4.Print(d4);
    return 0;
}
