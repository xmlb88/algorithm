/* 
����ģʽ��
�ڹ���ģʽ�У������ڴ�������ʱ����Կͻ��˱�¶�����߼���������ͨ��ʹ��һ�������Ľӿ���ָ���´����Ķ��󣬹���ģʽ��Ϊһ�ִ���ģʽ
��һ���ڴ������Ӷ���ʱ������ʹ�ã��ڴ����򵥶���ʱ������ֱ��new���

�򵥹���ģʽ��
��Ҫ�ص�����Ҫ�ڹ����������жϣ��Ӷ�������Ӧ�Ĳ�Ʒ���������²�Ʒʱ����Ҫ�޸Ĺ����࣬ʹ�ü򵥹���ģʽ������ֻ��Ҫ֪��������ͺž�
���Դ���һ����Ʒ

ȱ�㣺�����༯�������в�Ʒ��Ĵ����߼��������Ʒ���ϴ󣬻�ʹ�ù������ķǳ�ӷ��

 */



// ���������ڹ����������

#include <iostream>
using namespace std;

// �����Ʒ������Ϣ
typedef enum {
    Tank_Type_56,
    Tank_Type_96,
    Tank_Type_Num
} Tank_Type;

// �����Ʒ��
class Tank {
public:
    virtual const string& type() = 0;
};

// ����Ĳ�Ʒ��
class Tank56 : public Tank {
public:
    Tank56() : Tank(), m_strType("Tank56") {}
    const string& type() override {
        cout << m_strType.data() << endl;
        return m_strType;
    }
private:
    string m_strType;
};

// ����Ĳ�Ʒ��
class Tank96 : public Tank {
public:
    Tank96() : Tank(), m_strType("Tank96") {}
    const string& type() override {
        cout << m_strType.data() << endl;
        return m_strType;
    }
private:
    string m_strType;
};

// ������
class TankFactory {
public:
    // ���ݲ�Ʒ��Ϣ��������Ĳ�Ʒ��ʵ��������һ�������Ʒ��
    Tank* createTank(Tank_Type type) {
        switch(type) {
            case Tank_Type_56:
                return new Tank56();
            case Tank_Type_96:
                return new Tank96();
            default:
                return nullptr;
        }
    }
};

int main() {
    TankFactory* factory = new TankFactory();
    Tank* tank56 = factory->createTank(Tank_Type_56);
    tank56->type();
    Tank* tank96 = factory->createTank(Tank_Type_96);
    tank96->type();

    delete tank96;
    tank96 = nullptr;
    delete tank56;
    tank56 = nullptr;
    delete factory;
    factory = nullptr;

    return 0;
}