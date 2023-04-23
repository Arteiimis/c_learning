#include <iostream>
#include <string>
using namespace std;

class Student {
public:
    Student(int id, string name, double score) {
        this->id = id;
        this->name = name;
        this->score = score;
        count++;
        total_score += score;
    }
    void display() {
        cout << "ID: " << id << ", Name: " << name << ", Score: " << score << endl;
    }
    static int get_count() {
        return count;
    }
    static double get_average_score() {
        return total_score / count;
    }
private:
    int id;
    string name;
    double score;
    static int count;
    static double total_score;
};

int Student::count = 0;
double Student::total_score = 0;

int main() {
    Student s1(1, "Alice", 90);
    Student s2(2, "Bob", 80);
    Student s3(3, "Charlie", 70);

    s1.display();
    s2.display();
    s3.display();

    cout << "Number of students: " << Student::get_count() << endl;
    cout << "Average score: " << Student::get_average_score() << endl;

    return 0;
}