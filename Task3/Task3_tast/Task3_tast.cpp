#include "CppUnitTest.h"
#include "../Task3_decision/circle.h"
#include "../Task3_decision/point.h"
#include "../Task3_decision/shape.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace CircleTests
{
    TEST_CLASS(PointTests)
    {
    public:
        TEST_METHOD(DefaultConstructor_CreatesZeroPoint)
        {
            Point p;

            Assert::AreEqual(0.0, p.getX());
            Assert::AreEqual(0.0, p.getY());
        }

        TEST_METHOD(ValueConstructor_CreatesPointWithValues)
        {
            const double x = 10.0;
            const double y = 20.0;

            Point p(x, y);

            Assert::AreEqual(x, p.getX());
            Assert::AreEqual(y, p.getY());
        }

        TEST_METHOD(EqualityOperator_EqualPoints_ReturnsTrue)
        {
            Point p1(1, 2);
            Point p2(1, 2);

            Assert::IsTrue(p1 == p2);
        }

        TEST_METHOD(EqualityOperator_DifferentX_ReturnsFalse)
        {
            Point p1(1, 2);
            Point p2(3, 2);

            Assert::IsFalse(p1 == p2);
        }

        TEST_METHOD(EqualityOperator_DifferentY_ReturnsFalse)
        {
            Point p1(1, 2);
            Point p2(1, 3);

            Assert::IsFalse(p1 == p2);
        }

        TEST_METHOD(InequalityOperator_DifferentPoints_ReturnsTrue)
        {
            Point p1(1, 2);
            Point p2(1, 3);

            Assert::IsTrue(p1 != p2);
        }

        TEST_METHOD(InequalityOperator_EqualPoints_ReturnsFalse)
        {
            Point p1(1, 2);
            Point p2(1, 2);

            Assert::IsFalse(p1 != p2);
        }

        TEST_METHOD(AdditionOperator_AddsValueCorrectly)
        {
            Point p(1, 2);
            double value = 3;

            Point result = p + value;

            Assert::AreEqual(4.0, result.getX());
            Assert::AreEqual(5.0, result.getY());
        }

        TEST_METHOD(SubtractionOperator_SubtractsValueCorrectly)
        {
            Point p(5, 4);
            double value = 3;

            Point result = p - value;

            Assert::AreEqual(2.0, result.getX());
            Assert::AreEqual(1.0, result.getY());
        }

        TEST_METHOD(OutputOperator_FormatsCorrectly)
        {
            Point p(10, 20);
            std::stringstream ss;

            ss << p;

            Assert::AreEqual("(10, 20)", ss.str().c_str());
        }

        TEST_METHOD(SetX_ValidValue_SetsCorrectly)
        {
            Point p;
            p.setX(15);

            Assert::AreEqual(15.0, p.getX());
        }

        TEST_METHOD(SetY_ValidValue_SetsCorrectly)
        {
            Point p;
            p.setY(25);

            Assert::AreEqual(25.0, p.getY());
        }
    };

    TEST_CLASS(ShapeTests)
    {
    public:
        TEST_METHOD(Draw_CallsToString)
        {
            Circle circle((10, 10), 5, 100);
            std::stringstream buffer;
            std::streambuf* old = std::cout.rdbuf(buffer.rdbuf());

            std::cout.rdbuf(old);

            Assert::IsTrue(buffer.str().find("Circle with center") != std::string::npos);
        }
    };

    TEST_CLASS(CircleTests)
    {
    public:
        TEST_METHOD(CircleConstructor_ValidParams_CreatesCircle)
        {
            Circle circle((10,10), 5, 100);

            Assert::AreEqual(10.0, circle.getCenter().getX());
            Assert::AreEqual(10.0, circle.getCenter().getY());
            Assert::AreEqual(5.0, circle.getRadius());
        }

        TEST_METHOD(CircleConstructor_ZeroRadius_ThrowsException)
        {
            auto func = [] {
                Circle circle((10, 10), 0, 100);
                };

            Assert::ExpectException<std::invalid_argument>(func);
        }

        TEST_METHOD(CircleConstructor_ExceedsMaxCoord_ThrowsException)
        {
            auto func = [] {
                Circle circle((95, 95), 10, 100);
                };

            Assert::ExpectException<std::out_of_range>(func);
        }

        TEST_METHOD(GetArea_CalculatesCorrectly)
        {
            Circle circle((0, 0), 10, 100);
            double expected = 314;
            double actual = circle.getArea();

            Assert::AreEqual(expected, actual, 0.0001);
        }

        TEST_METHOD(GetPerimeter_CalculatesCorrectly)
        {
            Circle circle((0, 0), 10, 100);
            double expected = 62.83185307179586;
            double actual = circle.getPerimeter();

            Assert::AreEqual(expected, actual, 0.0001);
        }

        TEST_METHOD(Contains_PointInside_ReturnsTrue)
        {
            Circle circle((10, 10), 5, 100);
            Point p(12, 12);

            Assert::IsTrue(circle.contains(p));
        }

        TEST_METHOD(Contains_PointOutside_ReturnsFalse)
        {
            Circle circle((10, 10), 5, 100);
            Point p(20, 20);

            Assert::IsFalse(circle.contains(p));
        }

        TEST_METHOD(ToString_ReturnsCorrectFormat)
        {
            Circle circle((10, 10), 5, 100);
            std::string result = circle.toString();

            Assert::IsTrue(result.find("круг с центром (10, 10)") != std::string::npos);
            Assert::IsTrue(result.find("радиус 5") != std::string::npos);
        }

        TEST_METHOD(PolymorphicCall_ThroughShapePointer)
        {
            Shape* shape = new Circle((0, 0), 10, 100);
            double area = shape->getArea();
            delete shape;

            Assert::AreEqual(314, area, 0.0001);
        }
    };
}