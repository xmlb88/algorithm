#include <iostream>
#include <vector>
using namespace std;

// ±©Á¦³¬Ê±
int breakfastNumber(vector<int>& staple, vector<int>& drinks, int x) {
    int num = 0;
    for (int i = 0; i < staple.size(); i++) {
        for (int j = 0; j < drinks.size(); j++) {
            if (staple[i] + drinks[j] <= x) num++;
        }
    }
    return num;
}

int breakfastNumber(vector<int>& staple, vector<int>& drinks, int x) {
    
}