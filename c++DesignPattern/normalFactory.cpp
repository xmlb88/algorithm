/* 
��������ģʽ��
����һ����������Ľӿڣ�������ȥ����ʵ������ӿ�����ɾ���Ĵ��������������Ҫ�����µĲ�Ʒ�ֻ࣬��Ҫ��չһ����Ӧ�Ĺ����༴��

ȱ�㣺��Ʒ�����ݽ϶�ʱ����Ҫʵ�ִ����Ĺ�����

 */


// ����������������ִ��

#include <iostream>
using namespace std;

// ��Ʒ������
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

// 
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

// ���󹤳��࣬�ṩһ�������ӿ�
class TankFactory {
public:
    // �ṩ������Ʒʵ���Ľӿڣ����س����Ʒ��
    virtual Tank* createTank() = 0;
};

// ����Ĵ��������࣬ʹ�ó��󹤳��ṩ�Ľӿڣ�ȥ��������Ĳ�Ʒʵ��
class Tank56Factory : public TankFactory {
public:
    Tank* createTank() override {
        return new Tank56();
    }
};

//
class Tank96Factory : public TankFactory {
public:
    Tank* createTank() override {
        return new Tank96();
    }
};


int main() {
    TankFactory* factory56 = new Tank56Factory();
    Tank* tank56 = factory56->createTank();
    tank56->type();

    TankFactory* factory96 = new Tank96Factory();
    Tank* tank96 = factory96->createTank();
    tank96->type();

    delete tank96;
    tank96 = nullptr;
    delete factory96;
    factory96 = nullptr;
    delete tank56;
    tank56 = nullptr;
    delete factory56;
    factory56 = nullptr;

    return 0;
}