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
<<<<<<< HEAD
			Point2D punt,p2;

			p2.x = 2.0f;
			p2.y = 5.0f;

			punt.x = 5.0f;
			punt.y = 8.0f;

			punt += p2;

			return punt;
=======
			Point2D punt, p2;

			punt.x = 5.0f;
			punt.y = 8.0f;

			p2.x = 2.0f;
			p2.y = 4.0f;

			punt -= p2;
>>>>>>> origin/master

			
		}

	};
}