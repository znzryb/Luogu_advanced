#include <iostream>
using namespace std;
int a,b,c,d;
bool isMerge() {
    // if(a>=d || b<=c)    return false;
    if(a<d && b>c)  return true;
    else return false;
}
int main()
{
    cin>>a>>b>>c>>d;
    std::cout << isMerge() << std::endl;
    return 0;
}
