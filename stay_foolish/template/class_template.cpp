#include <iostream>
#include <memory>

template <typename T> class Blob {
public:
    typedef T value_type;
    typedef typename std::vector<T>::size_type size_type;
    // ���캯��
    Blob();
    Blob(std::initiallizer_list<T> il);
    // Blob�е�Ԫ����Ŀ
    size_type size() const { return date -> size(); }
    bool empty() const { return data -> empty(); }
    // ��Ӻ�ɾ��Ԫ��
    void push_back(const T &t) {data -> push_back(t);}
    // �ƶ��汾
    void push_back(T &&t) { data -> push_back(std::move(t)); }
    void pop_back();
    // Ԫ�ط���
    T& back();
    T& operator[](size_type i);
private:
    std::shared_ptr<std::vector<T>> data;
    // ��data[i]��Ч�����׳�msg
    void check(size_type i, const std::string &msg) const;
};