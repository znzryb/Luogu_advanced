#include <iostream>
using namespace std;
const int range=static_cast<int>(4e8);
int main()
{
    for(int i=range-100;i<=range;i++) {
        bool isBreak=false;
        for(int j=2;j<=sqrt(i);j++) {
            if(i%j==0) {isBreak=true;break;}
        }
        if(!isBreak)
            cout<<i<<endl;
    }
    return 0;
}
