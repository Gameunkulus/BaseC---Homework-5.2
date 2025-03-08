// Homework-5.2.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class Figure {
protected:

    int numSides;

public:

    Figure() {
        this->numSides = 0;
    };

    int getSides() {
        return numSides;
    };

    void setSides(int num) {
        this->numSides = num;
    };

    virtual void getSidesCount() {
        cout << "Фигура: " << getSides() << endl;
    };

};

class Triangle : public Figure {

protected:
    int a, b, c;
    int A, B, C;

public:

    Triangle(int a, int b, int c, int A, int B, int C) : Figure() {
        numSides = 3;
        if (a == 0 || b == 0 || c == 0) {
            cout << "Ошибка, стороны треугольника не могут быть равны нулю." << endl;
        }
        else if (A == 0 || B == 0 || C == 0) {
            cout << "Ошибка, углы треугольника не могут быть равны нулю." << endl;
        }
        else if ((a + b) < c || (b + c) < a || (c + a) < b)
        {
            cout << "Ошибка, недопустимые значения сторон треугольника." << endl;
        }
        else if ((A + B + C) > 180) {
            cout << "Ошибка, сумма значений углов не могут быть больше 180." << endl;
        }
        else {
            this->a = a;
            this->b = b;
            this->c = c;
            this->A = A;
            this->B = B;
            this->C = C;
        };
    };

    string getSides() {
        string text = "Стороны: a = " + to_string(a) + " b = " + to_string(b) + " c = " + to_string(c) + "\n" +
            "Углы : A = " + to_string(A) + " B = " + to_string(B) + " C = " + to_string(C) + "\n";
        return text;
    };

    void getSidesCount() override {
            cout << "Треугольник: " << endl << getSides() << endl;
    };

};

class Fourangle : public Figure {
protected:
    int a, b, c, d;
    int A, B, C, D;

public:

    Fourangle(int a, int b, int c, int d, int A, int B, int C, int D) : Figure() {
        numSides = 4;
        if (a == 0 || b == 0 || c == 0 || d == 0) {
            cout << "Ошибка, стороны четырехугольника не могут быть равны нулю." << endl;
            return;
        }
        else if (A == 0 || B == 0 || C == 0 || D == 0) {
            cout << "Ошибка, углы четырехугольника не могут быть равны нулю." << endl;
            return;
        }
        else if ((A + B + C + D) > 360) {
            cout << "Ошибка, сумма значений углов не могут быть больше 360." << endl;
            return;
        }
        else {
            this->a = a;
            this->b = b;
            this->c = c;
            this->d = d;
            this->A = A;
            this->B = B;
            this->C = C;
            this->D = D;
        };


    };

    string getSides() {
        string text = "Стороны: a = " + to_string(a) + " b = " + to_string(b) + " c = " + to_string(c) + " d = " + to_string(d) + "\n" +
            "Углы : A = " + to_string(A) + " B = " + to_string(B) + " C = " + to_string(C) + " D = " + to_string(D) + "\n";
        return text;
    };

    void getSidesCount() override {
            cout << "Квадрат: " << endl << getSides() << endl;
    };


};


int main(int argc, char** argv)
{
    setlocale(LC_ALL, "Russian");
    cout << "Количество сторон: " << endl;
    Figure figure;
    figure.getSidesCount();

    Triangle triangle(10, 10, 10, 60, 60, 60);
    triangle.getSidesCount();


    Triangle triangleTwo(20, 10, 20, 60, 50, 60);
    triangleTwo.getSidesCount();

    Triangle triangleThree(10, 25, 15, 25, 65, 90);
    triangleThree.getSidesCount();

    Triangle triangleFour(10, 25, 15, 35, 65, 80);
    triangleFour.getSidesCount();

    Fourangle fourangle(10, 20, 30, 40, 50, 60, 70, 80);
    fourangle.getSidesCount();

    Fourangle fourangleTwo(10, 20, 10, 20, 90, 90, 90, 90);
    fourangleTwo.getSidesCount();

    Fourangle fourangleThree(20, 20, 20, 20, 90, 90, 90, 90);
    fourangleThree.getSidesCount();

    Fourangle fourangleFour(20, 30, 20, 30, 30, 40, 30, 40);
    fourangleFour.getSidesCount();

    Fourangle fourangleFive(30, 30, 30, 30, 30, 40, 30, 40);
    fourangleFive.getSidesCount();
}