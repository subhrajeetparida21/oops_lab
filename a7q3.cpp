#include <iostream>
using namespace std;

class Tool {
protected:
    int strength;
    char t_type;
public:
    Tool() : strength(0), t_type(' ') {}
    void setStrength(int s) { strength = s; }
    virtual char getType() const = 0;
    int getStrength() const { return strength; }
    virtual bool cmp_strength(const Tool& t) const = 0;
    virtual void display() const {
        cout << "Tool Type: " << t_type << ", Strength: " << strength << endl;
    }
};

class Wrench : public Tool {
public:
    Wrench(int s) { strength = s; t_type = 'w'; }
    char getType() const override { return t_type; }
    bool cmp_strength(const Tool& t) const override { return strength > t.getStrength(); }
};

class Axe : public Tool {
public:
    Axe(int s) { strength = s; t_type = 'a'; }
    char getType() const override { return t_type; }
    bool cmp_strength(const Tool& t) const override { return strength > t.getStrength(); }
};

class Scissors : public Tool {
public:
    Scissors(int s) { strength = s; t_type = 's'; }
    char getType() const override { return t_type; }
    bool cmp_strength(const Tool& t) const override { return strength > t.getStrength(); }
};

int main() {
    int s1, s2, s3;
    cout << "Enter strength for Wrench: ";
    cin >> s1;
    cout << "Enter strength for Axe: ";
    cin >> s2;
    cout << "Enter strength for Scissors: ";
    cin >> s3;

    Wrench w(s1);
    Axe a(s2);
    Scissors s(s3);

    w.display();
    a.display();
    s.display();

    cout << "\nComparisons:\n";
    cout << "Wrench vs Axe: " << (w.cmp_strength(a) ? "Wrench is stronger" : "Wrench is weaker or equal") << endl;
    cout << "Wrench vs Scissors: " << (w.cmp_strength(s) ? "Wrench is stronger" : "Wrench is weaker or equal") << endl;
    cout << "Axe vs Scissors: " << (a.cmp_strength(s) ? "Axe is stronger" : "Axe is weaker or equal") << endl;

    return 0;
}
