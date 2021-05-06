#include <iostream>
#include <queue>
#include <vector>
#include <unordered_map>
#include <stack>
using namespace std;

class Employee {
public:
    int id;
    int importance;
    vector<int> subordinates;
};

int getImportance(vector<Employee*> employees, int id) {
    int res = 0;
    queue<Employee*> q;
    unordered_map<int, Employee*> emp_id;
    for (auto employ : employees) {
        emp_id[employ -> id] = employ;
    }
    q.push(emp_id[id]);

    while (!q.empty()) {
        int size = q.size();
        for (int i = 0; i < size; i++) {
            auto employ = q.front();
            q.pop();
            res += employ -> importance;
            for (int number : employ -> subordinates) {
                q.push(emp_id[number]);
            }
        }
    }

    return res;
}

int getImportance(vector<Employee*> employees, int id) {
    int pos;
    for (int i = 0; i < employees.size(); i++) {
        if (employees[i] -> id == id) {
            pos = i;
            break;
        }
    }
    int res = employees[pos] -> importance;
    for (int i = 0; i < employees[pos] -> subordinates.size(); i++) {
        res += getImportance(employees, employees[pos] -> subordinates[i]);
    }
    return res;
}

// review 2021Äê5ÔÂ6ÈÕ17:27:57
int getImportance(vector<Employee*> employees, int id) {
    int res = 0;
    vector<int> sub_emp;
    for (auto& emp : employees) {
        if (emp->id == id) {
            res += emp->importance;
            sub_emp = emp->subordinates;
        }
    }

    for (int sub_id : sub_emp) {
        res += getImportance(employees, sub_id);
    }
    return res;
}