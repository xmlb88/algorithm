// 423
#include <iostream>
#include <vector>
#include <string>
#include <memory>
using namespace std;

void t_allocator() {
    allocator<string> alloc;
    auto const p = alloc.allocate(n);
    alloc.deallocate();
    alloc.construct();
    alloc.destroy();
    auto q = p;
    alloc.construct(q++);
    alloc.construct(q++, 10, 'c');
    alloc.construct(q++, "Hi");
}

// 432

