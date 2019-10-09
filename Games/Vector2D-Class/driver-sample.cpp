#include <iostream>   // cin, cout, endl
#include "Vector2D.h" // Vector2D class

void ConstructorTest(void)
{
	std::cout << "\n********** Constructor test ********** " << std::endl;

	CS170::Vector2D v1(3.0f, 4.0f);
	CS170::Vector2D v2;
	CS170::Vector2D v3(v1);
	CS170::Vector2D v4 = v1;
	CS170::Vector2D v5;

	v5 = v4;

	// DO NOT ALLOW THIS SYNTAX:
	//CS170::Vector2D p6 = 4; // this should not compile
	//CS170::Vector2D p7(4);  // this should not compile

	std::cout << "Vector2D v1(3, 4): " << v1 << std::endl;
	std::cout << "Vector2D v2: " << v2 << std::endl;
	std::cout << "Vector2D v3(v1): " << v3 << std::endl;
	std::cout << "Vector2D v4 = v1: " << v3 << std::endl;
	std::cout << "v5 = v4: " << v5 << std::endl;

	std::cout << std::endl;
}

void GetSetTest(void)
{
	std::cout << "\n********** Get and Set test ********** " << std::endl;

	CS170::Vector2D v1(9.0f, -5.0f);
	std::cout << "v1.x = " << v1.X() << std::endl;
	std::cout << "v1.y = " << v1.Y() << std::endl;

	v1.X(4.0f);
	std::cout << "v1.x = 4.0f" << std::endl;
	std::cout << "v1.x = " << v1.X() << std::endl;

	v1.Y(9.0f);
	std::cout << "v1.y = 9.0f" << std::endl;
	std::cout << "v1.y = " << v1.Y() << std::endl;

	std::cout << std::endl;
}

void MagnitudeTest(void)
{
	std::cout << "\n********** Magnitude test ********** " << std::endl;

	CS170::Vector2D v1(3.0f, 4.0f);
	std::cout << "v1 = " << v1 << std::endl;
	std::cout << "magnitude of v1 = " << v1.Magnitude() << std::endl;
	std::cout << "magnitude of v1 squared = " << v1.MagnitudeSquared() << std::endl;

	CS170::Vector2D v2(7.0f, 12.0f);
	std::cout << "v2 = " << v2 << std::endl;
	std::cout << "magnitude of v2 = " << v2.Magnitude() << std::endl;
	std::cout << "magnitude of v2 squared = " << v2.MagnitudeSquared() << std::endl;
	std::cout << std::endl;

	std::cout << "v1 normalized = " << v1.Normalized() << std::endl;
	std::cout << "v2 normalized = " << v2.Normalized() << std::endl;
	std::cout << std::endl;
}

void DistanceTest(void)
{
	std::cout << "\n********** Distance test ********** " << std::endl;

	CS170::Vector2D v1(3.0f, 4.0f);
	CS170::Vector2D v2(7.0f, 12.0f);
	float distance = 0.0f;;

	distance = v2.Distance(v1);
	std::cout.setf(std::ios_base::fixed, std::ios::floatfield);
	std::cout.precision(3);
	std::cout << "Distance between " << v2 << " and " << v1 << " is " << distance << std::endl;

	distance = v1.Distance(v2);
	std::cout << "Distance between " << v1 << " and " << v2 << " is " << distance << std::endl;

	v1 = CS170::Vector2D(-5.0f, 3.0f);
	v2 = CS170::Vector2D(-1.0f, -7.0f);

	distance = v2.Distance(v1);
	std::cout << "Distance between " << v2 << " and " << v1 << " is " << distance << std::endl;

	distance = v2.DistanceSquared(v1);
	std::cout << "Squared distance between " << v2 << " and " << v1 << " is " << distance << std::endl;

	std::cout << std::endl;
	std::cout.unsetf(std::ios_base::fixed);
	std::cout.precision(6);
}

void MidpointTest(void)
{
	std::cout << "\n********** Midpoint test ********** " << std::endl;

	CS170::Vector2D v1(3.0f, 4.0f);
	CS170::Vector2D v2(7.0f, 12.0f);

	CS170::Vector2D v3 = v1.Midpoint(v2);
	std::cout.setf(std::ios_base::fixed, std::ios::floatfield);
	std::cout.precision(3);
	std::cout << "Midpoint of " << v1 << " and " << v2 << " is " << v3 << std::endl;

	v1 = CS170::Vector2D(-5.0f, 3.0f);
	v2 = CS170::Vector2D(-1.0f, -7.0f);
	v3 = v1.Midpoint(v2);
	std::cout << "Midpoint of " << v1 << " and " << v2 << " is " << v3 << std::endl;

	std::cout << std::endl;
	std::cout.unsetf(std::ios_base::fixed);
	std::cout.precision(6);
}

void DotTest(void)
{
	std::cout << "\n********** Dot test ********** " << std::endl;

	CS170::Vector2D v1(3.0f, 4.0f);
	CS170::Vector2D v2(7.0f, 12.0f);

	std::cout << "v1 = " << v1 << std::endl;
	std::cout << "v2 = " << v2 << std::endl;
	std::cout << "v1 dot v2 = " << v1.DotProduct(v2) << std::endl;
	std::cout << "v2 dot v1 = " << v2.DotProduct(v1) << std::endl;
	std::cout << std::endl;

	CS170::Vector2D v3(2.0f, 4.0f);
	CS170::Vector2D v4(-8.0f, 4.0f);

	std::cout << "v3 = " << v3 << std::endl;
	std::cout << "v4 = " << v4 << std::endl;
	std::cout << "v3 dot v4 = " << v3.DotProduct(v4) << std::endl;
	std::cout << "v4 dot v3 = " << v4.DotProduct(v3) << std::endl;
	std::cout << std::endl;
}

void AddSubtractTest(void)
{
	std::cout << "\n********** Add and Subtract test ********** " << std::endl;

	CS170::Vector2D v1(3.0f, 4.0f);
	CS170::Vector2D v2(7.0f, 12.0f);
	CS170::Vector2D v3;

	v3 = v1 + v2;
	std::cout << v1 << " + " << v2 << " = " << v3 << std::endl;

	CS170::Vector2D v4;
	v4 = v2 - v1;
	std::cout << v2 << " - " << v1 << " = " << v4 << std::endl;

	std::cout << std::endl;
}

// void ScaleTest(void)
// {
// 	std::cout << "\n********** Scale test ********** " << std::endl;

// 	CS170::Vector2D v1(3.0f, 4.0f);
// 	CS170::Vector2D v2 = v1 * 3.0f;
// 	std::cout << v1 << " * 3 = " << v2 << std::endl;
// 	std::cout << std::endl;

// 	CS170::Vector2D v3(5.0f, 8.0f);
// 	CS170::Vector2D v4 = 5.0f * v3;
// 	std::cout << "5 * " << v3 << " = " << v4 << std::endl;
// 	std::cout << std::endl;

// 	std::cout << v4 << " / 3 = " << v4 / 3.0f << std::endl;
// 	std::cout << std::endl;
// }

// void AssignmentTest1(void)
// {
// 	std::cout << "\n********** Assignment test 1 ********** " << std::endl;

// 	CS170::Vector2D v1(3.0f, 4.0f);
// 	CS170::Vector2D v2(-5.0f, 1.0f);

// 	std::cout << "v1 = " << v1 << std::endl;
// 	std::cout << "v2 = " << v2 << std::endl;
// 	v1 += v2;
// 	std::cout << "v1 += v2" << std::endl;
// 	std::cout << "v1 = " << v1 << std::endl;
// 	std::cout << "v2 = " << v2 << std::endl;

// 	std::cout << std::endl;

// 	CS170::Vector2D v3(3.0f, 4.0f);
// 	std::cout << "v3 = " << v3 << std::endl;

// 	std::cout << std::endl;

// 	v1 += v2 += v3;
// 	std::cout << "v1 += v2 += v3" << std::endl;
// 	std::cout << "v1 = " << v1 << std::endl;
// 	std::cout << "v2 = " << v2 << std::endl;
// 	std::cout << "v3 = " << v3 << std::endl;
// }

// void AssignmentTest2(void)
// {
// 	std::cout << "\n********** Assignment test 2 ********** " << std::endl;

// 	CS170::Vector2D v1(1.0f, 2.0f);
// 	std::cout << "v1 = " << v1 << std::endl;
// 	CS170::Vector2D v2(-9.0f, 12.0f);
// 	std::cout << "v2 = " << v2 << std::endl;
// 	v1 -= v2;
// 	std::cout << "v1 -= v2 " << std::endl;
// 	std::cout << "v1 = " << v1 << std::endl;

// 	std::cout << std::endl;

// 	CS170::Vector2D v3(7.0f, 3.0f);
// 	std::cout << "v3 = " << v3 << std::endl;
// 	v3 *= -2.5f;
// 	std::cout << "v3 *= -2.5" << std::endl;
// 	std::cout << "v3 = " << v3 << std::endl;
// 	std::cout << std::endl;

// 	std::cout << "v3 /= 4" << std::endl;
// 	v3 /= 4.0f;
// 	std::cout << "v3 = " << v3 << std::endl;
// 	std::cout << std::endl;
// }

// void UnaryTest(void)
// {
// 	std::cout << "\n********** Unary test ********** " << std::endl;

// 	CS170::Vector2D v1(3.0f, 4.0f);
// 	std::cout << "v1 = " << v1 << std::endl;
// 	CS170::Vector2D v2 = -v1;
// 	std::cout << "v2 = -v1" << std::endl;

// 	std::cout << "v1 = " << v1 << std::endl;
// 	std::cout << "v2 = " << v2 << std::endl;

// 	std::cout << std::endl;

// 	CS170::Vector2D v3(-3.0f, 4.0f);
// 	std::cout << "v3 = " << v3 << std::endl;
// 	CS170::Vector2D v4 = - - -v3;
// 	std::cout << "v4 = - - -v3" << std::endl;

// 	std::cout << "v3 = " << v3 << std::endl;
// 	std::cout << "v4 = " << v4 << std::endl;
// }

int main(void)
{
	ConstructorTest();
	GetSetTest();
	MagnitudeTest();
	DistanceTest();
	MidpointTest();
	DotTest();
	AddSubtractTest();
	// ScaleTest();
	// AssignmentTest1();
	// AssignmentTest2();
	// UnaryTest();

	return 0;
}
