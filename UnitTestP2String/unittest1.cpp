#include "stdafx.h"
#include "CppUnitTest.h"

#include "../Project1/P2String.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTestP2String
{		
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(ConstrEmpty)
		{
			P2String s1;

			Assert::IsTrue(s1 == "");
		}
		TEST_METHOD(ConstrChar)
		{
			P2String s1("Hola");
			char *c2 = "Roger";
			P2String s2 = c2;
			char *c3 = NULL;
			P2String s3 = c3;
			P2String s4("%s%d%s", "Tinc", 18, "anys");

			Assert::IsTrue(s1 == "Hola");
			Assert::IsTrue(s2 == "Roger");
			Assert::IsTrue(s3 == "");
			Assert::IsTrue(s4 == "Tinc 18 anys");
		}
		TEST_METHOD(ConstrString)
		{
			P2String s1;
			P2String s2(s1);
			P2String s3("Roger");
			P2String s4(s3);

			Assert::IsTrue(s1 == "");
			Assert::IsTrue(s1 == s2);
			Assert::IsTrue(s3 == "Roger");
			Assert::IsTrue(s3 == s4);
		}
		TEST_METHOD(SameChar)
		{
			P2String s1("Roger");
			char *c1 = NULL;
			char *c2 = "Roger";

			Assert::IsTrue(s1 == "Roger");
			Assert::IsFalse(s1 == c1);
			Assert::IsTrue(s1 == c2);
		}
		TEST_METHOD(NoSameChar)
		{
			P2String s1("Roger");
			char *c1 = NULL;
			char *c2 = "Roger Olasz";

			Assert::IsTrue(s1 != "Roger Olasz");
			Assert::IsTrue(s1 != c1);
			Assert::IsTrue(s1 != c2);
		}
		TEST_METHOD(EqualityString)
		{
			P2String s1("Roger");
			P2String s2("Roger");

			Assert::IsTrue(s1 == s2);
		}
		TEST_METHOD(InequalityString)
		{
			P2String s1("Hello");
			P2String s2("Hello, darling...");

			Assert::IsTrue(s1 != s2);
		}
		TEST_METHOD(CharAssignation)
		{
			P2String s1("Roger");
			P2String s2 = "Roger Olasz";
			char *c = NULL;
			P2String s3 = c;
			P2String s4 = "Roger";

			Assert::IsTrue(s1 != s2);
			Assert::IsTrue(s1 != s2);
			Assert::IsTrue(s1 != s3);
			Assert::IsTrue(s1 == s4);
		}
		TEST_METHOD(StringAssignation)
		{
			P2String s1("Roger");
			P2String s2 = s1;
			P2String s3("Roger Olasz");
			P2String s4 = s3;

			Assert::IsTrue(s1 == s2);
			Assert::IsTrue(s1 != s4);
		}
		TEST_METHOD(PlusChar)
		{
			P2String s1("Roger");
			s1 += "OlaszFuentes";
			Assert::IsTrue(s1 == "RogerOlaszFuentes");
			char *c = NULL;
			s1 += c;
			Assert::IsTrue(s1 == "");
		}
		TEST_METHOD(PlusString)
		{
			P2String s1("Roger");
			P2String s2("Olasz");
			s1 += s2;
			Assert::IsTrue(s1 == "RogerOlasz");
		}
		TEST_METHOD(GetLen)
		{
			P2String s1("Roger");
			P2String s2;

			Assert::IsTrue(s1.getLength() == 5);
			Assert::IsTrue(s2.getLength() == 0);
		}
		TEST_METHOD(GetCapacity)
		{
			P2String s1("Roger");
			P2String s2;

			Assert::IsTrue(s1.capacity() == 6);
			Assert::IsTrue(s2.capacity() == 1);
		}
		TEST_METHOD(GetString)
		{
			P2String s1("Roger");
			P2String s2;

			Assert::IsTrue(strcmp(s1.getString(), "Roger") == 0);
			Assert::IsTrue(strcmp(s2.getString(), "") == 0);
		}
		TEST_METHOD(ClearString)
		{
			P2String s1("Roger");
			s1.clear();

			Assert::IsTrue(strcmp(s1.getString(), "") == 0);
		}

	};
}