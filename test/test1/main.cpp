#include"Date.h"
int main()
{
    Date d1(2019,3,17);
    Date d2(2019,3,18);
    Date d3(2019,3,19);
    d1.Print(d1);
    int m=d3-d2;
    cout<<"day:"<<m<<endl;
    
    return 0;
}
