#include <iostream>
#include <cmath>

class Figure {
public:
    virtual int getArea() = 0;
    virtual void calculateDimensions(int area) = 0;
    virtual ~Figure() {}
};

class Square : public Figure {
public:

    void setSize(int size1, int size2) {
        param1 = size1;
        param2 = size2;
    }

    int getArea() override {
        return param1 * param2;
    }

    void calculateDimensions(int area) override {

        int side = static_cast<int>(std::sqrt(area));

        setSize(side, side);
    }

private:
    int param1 = 0;
    int param2 = 0;
};

class Circle : public Figure {
public:

    void setRadius(int radius) {
        rad = radius;
    }

    int getArea() override {
        return 3.14 * rad * rad;
    }

    void calculateDimensions(int area) override {

        int radius = static_cast<int>(std::sqrt(area / 3.14));
        setRadius(radius);
    }

private:
    int rad = 0;
};

int main() {
    Figure* f1 = new Circle();
    Figure* f2 = new Square();

    Circle* c = dynamic_cast<Circle*>(f1);
    Square* s = dynamic_cast<Square*>(f2);

    if (c != nullptr) {
        c->setRadius(5);
        std::cout << "Area of the circle: " << c->getArea() << '\n';

        f1->calculateDimensions(50);
        std::cout << "New area of the circle: " << c->getArea() << '\n';
    }

    if (s != nullptr) {
        s->setSize(10, 10);
        std::cout << "Area of the square: " << s->getArea() << '\n';

        f2->calculateDimensions(200);
        std::cout << "New area of the circle: " << s->getArea() << '\n';
    }

    if (c == nullptr && s == nullptr) {
        std::cout << "The object is neither a Circle nor a Square." << '\n';
    }

    delete f1;
    delete f2;

    return 0;
}