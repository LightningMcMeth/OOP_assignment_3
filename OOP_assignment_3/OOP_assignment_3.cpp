class Figure {
public:
    virtual int getArea() = 0;
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

private:
    int rad = 0;
};

int main() {
    Figure* f = new Circle();

    Circle* c = dynamic_cast<Circle*>(f);
    Square* s = dynamic_cast<Square*>(f);

    c->setRadius(5);
    s->setSize(10, 10);

    std::cout << "Area of the circle" << c->getArea() << '\n';
    std::cout << "Are of the square" << s->getArea() << '\n';

    delete f;
    delete c;

    return 0;
}