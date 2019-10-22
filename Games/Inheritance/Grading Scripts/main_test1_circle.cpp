#include <iostream>
#include "Circle.h"
#include "Rectangle.h"
#include "Polygon.h"

void TestingTheCircleClass(void)
{
	std::cout << "Testing The Circle Class:" << std::endl;
	std::cout << "-------------------------" << std::endl;
	std::cout << "Circle 1:" << std::endl;
	std::cout << "---------" << std::endl;
	Circle c1(Point(10, 10), 5);
	c1.Draw();

	std::cout << "Circle 2:" << std::endl;
	std::cout << "---------" << std::endl;
	Circle c2(c1);
	c2.Draw();

	std::cout << "Circle 3:" << std::endl;
	std::cout << "---------" << std::endl;
	Circle *c3 = new Circle(Point(), 10);
	c3->Draw();
	c3->SetCenter(15, 15);
	c3->Draw();
	delete c3;

	std::cout << "Circle 4:" << std::endl;
	std::cout << "---------" << std::endl;
	const Circle c4(Point(20,20), 3);
	c4.Draw();
	//Should get a compiler error
	//c4.SetCenter(30, 30);

	std::cout << std::endl;
}

void TestingTheRectangleClass(void)
{
	std::cout << "Testing The Rectangle Class:" << std::endl;
	std::cout << "-------------------------" << std::endl;
	std::cout << "Rectangle 1:" << std::endl;
	std::cout << "---------" << std::endl;
	Rectangle s1(Point(0, 0), 10, 5);
	s1.Draw();

	std::cout << "Rectangle 2:" << std::endl;
	std::cout << "---------" << std::endl;
	Rectangle s2(s1);
	s2.Draw();

	std::cout << "Rectangle 3:" << std::endl;
	std::cout << "---------" << std::endl;
	Rectangle *s3 = new Rectangle(Point(10, 10), 10, 10);
	s3->Draw();
	s3->SetCenter(15, 15);
	s3->Draw();
	delete s3;

	std::cout << "Rectangle 4:" << std::endl;
	std::cout << "---------" << std::endl;
	const Rectangle s4(Point(20, 20), 12, 4);
	s4.Draw();
	//Should get a compiler error
	//s4.SetCenter(30, 30);

	std::cout << std::endl;
}

void TestingThePolygonClass(void)
{
	std::cout << "Testing The Polygon Class:" << std::endl;
	std::cout << "---------------------------" << std::endl;
	std::cout << "Polygon 1:" << std::endl;
	std::cout << "-----------" << std::endl;
	Polygon p1(Point(0, 0), 3);
	p1.Draw();
	p1.SetVertex(0, 5, 0);
	p1.SetVertex(1, 0, 15);
	p1.SetVertex(2, -5, 0);
	p1.Draw();

	std::cout << "Polygon 2:" << std::endl;
	std::cout << "-----------" << std::endl;
	Polygon p2(p1);
	p2.Draw();

	std::cout << "Polygon 3:" << std::endl;
	std::cout << "-----------" << std::endl;
	Polygon *p3 = new Polygon(Point(10, 10), 4);
	p3->SetVertex(0, 5, 0);
	p3->SetVertex(1, 0, 15);
	p3->SetVertex(2, -5, 0);
	p3->SetVertex(3, 0, -15);
	p3->Draw();
	p3->SetCenter(15, 15);
	p3->Draw();
	p3->SetVertex(4, 5, 5);
	std::cout << std::endl;
	delete p3;

	std::cout << "Polygon 4:" << std::endl;
	std::cout << "-----------" << std::endl;
	Point points[4] = {Point(5, 0), Point(0,15), Point(-5, 0), Point(0, -15) };
	const Polygon p4(Point(20, 20), points, 4);
	p4.Draw();
	//Should get a compiler error
	//p4.SetCenter(30, 30);
	//p4.SetVertex(0, 10, 10);
	
	std::cout << std::endl;
}

void TestingPolymorphism(void)
{
	std::cout << "Testing Polymorphism:" << std::endl;
	std::cout << "----------------------" << std::endl;

#define SIZE 3

	Shape *shapes[SIZE];
	shapes[0] = new Circle(Point(10, 10), 5);
	shapes[1] = new Rectangle(Point(30,30), 10, 5);
	shapes[2] = new Polygon(Point(50,50), 3);
	((Polygon *)(shapes[2]))->SetVertex(0, 5, 0);
	((Polygon *)(shapes[2]))->SetVertex(1, 0, 15);
	((Polygon *)(shapes[2]))->SetVertex(2, -5, 0);

	for (int i = 0; i < SIZE; ++i)
	{
		shapes[i]->Draw();
	}

	for (int i = 0; i < SIZE; ++i)
	{
		delete shapes[i];
	}
}


/*
// Comment out the below code in order to test the abstract classes
void TestingTheAbstractClasses(void)
{
	//Should get a compiler error
	Shape s;
	//Should get a compiler error
	Shape_With_Vertices sv;

}
*/

int main(void)
{
	TestingTheCircleClass();
	//TestingTheRectangleClass();
	//TestingThePolygonClass();
	//TestingPolymorphism();
}