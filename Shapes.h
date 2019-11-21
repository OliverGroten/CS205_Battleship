//
// Created by Hannah Meharg on 11/19/19.
//
#ifndef SHAPES_H
#define SHAPES_H


const double PI = 3.14159265358979;

/*
 * Colors are stored as (r, g, b) in OpenGL
 * Each part is stored on a [0,1] scale
 * Mac'n'cheese: 255, 189, 136
 * We would store it as (255/255.0, 189/255.0, 136/255.0)
 */
struct color {
    double red;
    double green;
    double blue;
};

struct point {
    // public fields
    // integers because pixels can't be divided
    int x;
    int y;

    point();
    point(int xIn, int yIn);
    point(double xIn, double yIn);
};

double distance(const point &p1, const point &p2);

class Shape {
public:
    // Constructors
    Shape();
    Shape(point c, color b, color f);
    Shape(int xIn, int yIn, double rb, double gb, double bb, double rf, double gf, double bf);

    // Getters
    point getCenter() const;
    color getBorderColor() const;
    color getFillColor() const;
    double getArea() const;
    double getPerimeter() const;

    // Setters
    void setCenter(point c);
    void setCenter(int xIn, int yIn);
    void move(int deltaX, int deltaY);
    void setBorderColor(color b);
    void setBorderColor(double r, double g, double b);
    void setFillColor(color f);
    void setFillColor(double r, double g, double b);
    // Note: no setters for area and perimeter
    // because those will be calculated in child classes
    // from fields (radius, length and width, etc.)

    // Note: make methods virtual that need to be
    // overridden in the child classes
    // This is pure virtual. It is explicitly undefined.
    // This makes the class abstract.
    virtual void draw() const = 0;

    virtual char getType() const = 0;

    virtual bool isOverlapping(const point &p) const = 0;

protected:
    point center;
    color border;
    color fill;
    double area;
    double perimeter;
    virtual void calculateArea() = 0;
    virtual void calculatePerimeter() = 0;
};


class Tangle : public Shape {
private:
    double length;
    double width;

    void calculateArea() override;
    void calculatePerimeter() override;

public:
    Tangle();
    Tangle(double l, double w);
    Tangle(color b, color f);
    Tangle(double rb, double gb, double bb, double rf, double gf, double bf);
    Tangle(double l, double w, color b, color f);
    Tangle(double l, double w, double rb, double gb, double bb, double rf, double gf, double bf);
    Tangle(double l, double w, point c);
    Tangle(double l, double w, int xIn, int yIn);
    Tangle(double l, double w, color b, color f, point c);
    Tangle(double l, double w, double rb, double gb, double bb, double rf, double gf, double bf, int xIn, int yIn);

    // Getters
    double getLength() const;
    double getWidth() const;

    // Setters
    void setDimensions(double l, double w);
    void setAreaAndLength(double a, double l);
    void setAreaAndWidth(double a, double w);
    void setPerimeterAndLength(double p, double l);
    void setPerimeterAndWidth(double p, double w);

    void draw() const override;

    char getType() const override;

    bool isOverlapping(const point &p) const override;
    bool isOverlappingTangle(const Tangle &rectangle) const;

    point mouse(int x, int y);

};





#endif //TEST_SHAPE_H
