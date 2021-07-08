/* 
 * ʵ��ͬһ���ӿ�
 */

#include <iostream>
using namespace std;

// ��������࣬�ṩһ���ӿ�
class Hurt {
public:
    virtual void blood() = 0;
};

// ����Ĳ���ʵ���࣬����ʵ�ֽӿڣ�Adc������ͨ����
class AdcHurt : public Hurt {
public:
    void blood() override {
        cout << "Adc hurt, Blood loss" << endl;
    }
};

// ����Ĳ���ʵ���࣬����ʵ�ֽӿڣ�Apc���ܹ���
class ApcHurt : public Hurt {
public:
    void blood() override {
        cout << "Apc Hurt, Blood loss" << endl;
    }
};

// ������ɫ�࣬��Ϸ��ɫսʿ������һ��������ָ�����
class Soldier {
public:
    Soldier(Hurt* hurt) : m_pHurt(hurt) {}

    // �ڲ�ͬ�Ĳ����£�����Ϸ��ɫ���ֳ���ͬ�Ĺ���
    void attack() {
        m_pHurt->blood();
    }
private:
    Hurt* m_pHurt;
};

// ������Ա�ǩ
typedef enum {
    Hurt_Type_Adc,
    Hurt_Type_Apc,
    Hurt_Type_Num
}HurtType;

// ������ɫ�࣬��Ϸ��ɫ��ʦ������һ�����Ա�ǩ����
class Mage {
public:
    Mage(HurtType type) {
        switch(type) {
            case Hurt_Type_Adc:
                m_pHurt = new AdcHurt();
                break;
            case Hurt_Type_Apc:
                m_pHurt = new ApcHurt();
                break;
            default:
                break;
        }
    }

    ~Mage() {
        delete m_pHurt;
        m_pHurt = nullptr;
        cout << "~Mage()" << endl;
    }

    void attack() {
        m_pHurt->blood();
    }
private:
    Hurt* m_pHurt;
};

// ������ɫ�࣬��Ϸ��ɫ�����֣�ʵ��ģ�崫�ݲ���
template<typename T>
class Archer {
public:
    void attack() {
        m_hurt.blood();
    }
private:
    T m_hurt;
};

int main() {
    Archer<ApcHurt>* arc = new Archer<ApcHurt>;
    arc->attack();

    Archer<AdcHurt>* adc = new Archer<AdcHurt>;
    adc->attack();

    delete arc;
    arc = nullptr;
    delete adc;
    adc = nullptr;

    return 0;
}