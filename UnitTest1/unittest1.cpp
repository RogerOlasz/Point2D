#include "stdafx.h"
#include "CppUnitTest.h"
#include "../Project1/Point2D.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{		
	TEST_CLASS(UnitTest1)
	{
	public:

		TEST_METHOD(OperatorPlus)
		{
			Point2D p1, p2;

			p1.x = 5.0f;
			p1.y = 2.0f;

			p2.x = 1.0f;
			p2.y = 4.0f;

			p1 + p2;

			Assert::IsTrue(p1.x == 7.0f && p1.y == 6.0f);
		}
		TEST_METHOD(OperatorMinus)
		{
			Point2D p1, p2;

			p1.x = 5.0f;
			p1.y = 2.0f;

			p2.x = 1.0f;
			p2.y = 4.0f;

			p1 - p2;

			Assert::IsTrue();
		}
		TEST_METHOD(OperatorPlusEqual)
		{
			Point2D p1, p2;

			p1.x = 5.0f;
			p1.y = 2.0f;

			p2.x = 1.0f;
			p2.y = 4.0f;

			p1 += p2;

			Assert::IsTrue();
		}
		TEST_METHOD(OperatorMinusEqual)
		{
			Point2D p1, p2;

			p1.x = 5.0f;
			p1.y = 2.0f;

			p2.x = 1.0f;
			p2.y = 4.0f;

			p1 -= p2;
		}
		TEST_METHOD(OperatorEqual)
		{
			Point2D p1, p2;

			p1.x = 5.0f;
			p1.y = 2.0f;

			p2.x = 1.0f;
			p2.y = 4.0f;

			p1 == p2;
		}
		TEST_METHOD(OperatorDifferent)
		{
			Point2D p1, p2;

			p1.x = 5.0f;
			p1.y = 2.0f;

			p2.x = 1.0f;
			p2.y = 4.0f;

			p1 != p2;
		}
		TEST_METHOD(DistanceTo)
		{
			Point2D p1, p2;

			p1.x = 5.0f;
			p1.y = 2.0f;

			p2.x = 1.0f;
			p2.y = 4.0f;

			p1.distanceTo(p2);
		}
		TEST_METHOD(TestisZero)
		{
			Point2D p1, p2;

			p1.x = 5.0f;
			p1.y = 2.0f;

			p2.x = 1.0f;
			p2.y = 4.0f;

			p1.isZero();
		}
		TEST_METHOD(TestsetZero)
		{
			Point2D p1, p2;

			p1.x = 5.0f;
			p1.y = 2.0f;

			p2.x = 1.0f;
			p2.y = 4.0f;

			p1.setZero();

		}

	};
}