#include <iostream>
#include <string>
#include <vector>
#include "Screen.h"
using namespace std;

class Window_mgr {
public:

private:
    vector<Screen> screens{Screen(24, 80, ' ')};
}