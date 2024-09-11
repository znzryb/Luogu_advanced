#include <iostream>
#include <chrono> // 用于测量时间

unsigned long long int result;
const unsigned long long int number=1e10;

int main() {

    // std::cout << "请输入一个正整数: ";
    // std::cin >> number;

    auto start = std::chrono::high_resolution_clock::now(); // 开始时间点

    for(unsigned long long int i=1;i<=number;i++) {
        result+=i;
    }

    auto end = std::chrono::high_resolution_clock::now(); // 结束时间点
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start).count();

    std::cout << "从1到" << number << "的和是: " << result << std::endl;
    std::cout << "程序运行时间: " << duration << " 微秒" << std::endl;

    return 0;
}

// 从1到10000000000的和是: 13106511857580896768
// 程序运行时间: 19060547 微秒