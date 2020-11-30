#include <iostream>
#include <vector>
using namespace std;

vector<int> swapNumbers(vector<int>& numbers) {
    numbers[0] = numbers[0] - numbers[1];
    numbers[1] = numbers[0] + numbers[1];
    numbers[0] = numbers[1] - numbers[0];
    return numbers;
}

// vector<int>swapNumbers(vector<int>& numbers) {
//     numbers[0] = numbers[0] + numbers[1];
//     numbers[1] = numbers[0] - numbers[1];
//     numbers[0] = numbers[0] - numbers[1];
//     return numbers;
// }

vector<int> swapNumbers(vector<int>& numbers) {
    numbers[0] ^= numbers[1];
    numbers[1] ^= numbers[0];
    numbers[0] ^= numbers[1];
    return numbers;
}

vector<int> swapNumbers(vector<int>& numbers) {
    numbers[0] = numbers[0] ^ numbers[1];
    numbers[1] = numbers[0] ^ numbers[1];
    numbers[0] = numbers[0] ^ numbers[1];
    return numbers;
}