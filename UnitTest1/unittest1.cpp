#include "stdafx.h"
#include "CppUnitTest.h"
#include "../Project1/Point2D.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{		
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestPoint2D)
		{
			Point2D p1, p2;

			p1.x = 5.0f;
			p1.y = 2.0f;

			p2.x = 1.0f;
			p2.y = 4.0f;

			p1 - p2;
			p1 + p2;
			p1 += p2;
			p1 -= p2;
			p1 == p2;
			p1 != p2;

			p1.distanceTo(p2);
			p1.setZero();
			p1.isZero();

		}

	};
}