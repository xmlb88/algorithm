#include <iostream>
#include <vector>
using namespace std;

class ParkingSystem{
private:
    int big, medium, small;
public:
    ParkingSystem(int big, int medium, int small) {
        big = big;
        medium = medium;
        small = small;
    }

    bool addCar(int carType) {
        if (carType == 1) {
            if (big > 0) {
                big--;
                return true;
            } else return false;
        } else if (carType == 2) {
            if (medium > 0) {
                medium--;
                return true;
            } else return false;
        } else if (carType == 3) {
            if (small > 0) {
                small--;
                return true;
            } else return false;
        }
    }
};