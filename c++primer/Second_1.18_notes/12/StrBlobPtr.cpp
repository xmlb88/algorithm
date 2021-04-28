// 421
#include <iostream>
#include <vector>
#include <string>
#include <memory>
using namespace std;

class StrBlobPtr {
public:
    StrBlobPtr() : curr(0) {}
    StrBlobPtr(StrBlob &a, size_t sz = 0) : wptr(a.data), curr(sz) {}
    string& deref() const;
    StrBlobPtr& incr(); // 前缀递增
private:
    shared_ptr<vector<string>> check(size_t, string&) const;
    weak_ptr<vector<string>> wptr;
    size_t curr;
};

shared_ptr<vector<string>>
StrBlobPtr::check(size_t i, const string& msg) const
{
    auto ret = wptr.lock(); // vector还存在吗？
    if (!ret)
        throw runtime_error("unbound StrBlobPtr");
    if (i >= ret -> size())
        throw out_of_range(msg);
    return ret;
}

string& StrBlobPtr::deref() const
{
    auto p = check(curr, "dereference past end");
    return (*p)[curr];
}

StrBlobPtr& StrBlobPtr::incr()
{
    // 如果curr已经指向容器的尾后位置，就不能递增它
    check(curr, "increment past enf of StrBlobPtr");
    ++curr;
    return *this;
}

// TODO:423 practice