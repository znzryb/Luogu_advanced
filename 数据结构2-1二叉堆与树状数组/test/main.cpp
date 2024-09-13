#include <iostream>
using namespace std;
int heap[100];
int main()
{
    heap[1]=1;
    heap[2]=2;
    swap(heap[1],heap[2]);
    std::cout << heap[1] << std::endl;
    return 0;
}
