#include <iostream>
#include <vector>
#include <string>
#include <memory>
using namespace std;

class StrBlob {
public:
    typedef std::vector<std::string>::size_type size_type;
    StrBlob();
    StrBlob(std::initializer_list<std::string> il);
    size_type size() const { return data -> empty(); }
    // ��Ӻ�ɾ��Ԫ��
    void push_back(const std::string& t) {data -> push_back(t);}
    void pop_back();
    // Ԫ�ط���
    std::string& front();
    std::string& back();
private:
    std::shared_ptr<std::vector<std::string>> data;
    void check(size_type i, const std::string& msg) const;
};

StrBlob::StrBlob() : data(make_shared<vector<string>> ()) {}
StrBlob::StrBlob(initializer_list<string> il) : data(make_shared<vector<string>> (il)) {}

void StrBlob::check(size_type i, const string& msg) const {
    if (i >= data -> size())
        throw out_of_range(msg);
}

string& StrBlob::front() {
    // ���vectorΪ�գ�check���׳�һ���쳣
    check(0, "front on empty StrBlob");
    return data -> front();
}

// const ����
const string& StrBlob::front() {
    check(0, "front on empty StrBlob");
    return data -> front();
}

string& StrBlob::back() {
    check(0, "back on empty StrBlob");
    return data -> back();
}

void StrBlob::pop_back() {
    check(0, "pop_back on empty StrBlob");
    data -> pop_back();
}
// 406