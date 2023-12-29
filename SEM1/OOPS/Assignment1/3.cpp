#include <iostream>
using namespace std;

class Manager {
    private:
        string name;
        int age;

    public:
        Manager(){

        }
        Manager(string n, int a){
            this->name = n;
            this->age= a;
        } 
        void display() {
            cout << "Name: " << name << ", Age: " << age << endl;
        }
};

int main() {
    int x = 3; 
    Manager managerArr[x]; 

    managerArr[0] = Manager("Burce Wayne", 35);
    managerArr[1] = Manager("Lucifer", 40);
    managerArr[2] = Manager("Pink Man", 36);
    
    for (int i = 0; i < x; ++i) {
        managerArr[i].display();
    }

    return 0;
}
