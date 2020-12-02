#include <iostream>
#include <queue>
#include <vector>
using namespace std;

class AnimalShelf {
public:
    queue<int> dog;
    queue<int> cat;
    AnimalShelf() {

    }
    
    void enqueue(vector<int> animal) {
        if (animal[1] == 1) {
            dog.push(animal[0]);
        } else {
            cat.push(animal[0]);
        }
    }
    
    vector<int> dequeueAny() {
        if (dog.empty()) return dequeueCat();
        if (cat.empty()) return dequeueDog();

        if (dog.front() < cat.front()) return dequeueDog();
        else return dequeueCat();
    }
    
    vector<int> dequeueDog() {
        if (dog.empty()) return {-1, -1};
        int id = dog.front();
        dog.pop();
        return {id, 1};
    }
    
    vector<int> dequeueCat() {
        if (cat.empty()) return {-1, -1};
        int id = cat.front();
        cat.pop();
        return {id, 0};
    }
};

/**
 * Your AnimalShelf object will be instantiated and called as such:
 * AnimalShelf* obj = new AnimalShelf();
 * obj->enqueue(animal);
 * vector<int> param_2 = obj->dequeueAny();
 * vector<int> param_3 = obj->dequeueDog();
 * vector<int> param_4 = obj->dequeueCat();
 */