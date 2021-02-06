#ifndef PERSON_H
#define PERSON_H

#include <string>

// class Person;
// std::istream& read(std::istream &, Person &);

class Person {
// ��Ԫ����
friend std::istream& read(std::istream&, Person&);
friend std::ostream& print(std::ostream&, const Person&);

private:
    std::string name;
    std::string address;
public:
    // ���캯��
    Person() = default;
    Person(const std::string& sname, const std::string& saddr) : name(sname), address(saddr) {}
    Person(std::istream &is) { read(is, *this); }


    const std::string& get_name() const {
        return name;
    }
    const std::string& get_addr() const {
        return address;
    }
};

std::istream& read(std::istream &is, Person &p) {
    return is >> p.name >> p.address;
}

std::ostream& print(std::ostream &os, const Person &p) {
    return os << p.name << " " << p.address;
}


#endif