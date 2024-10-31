#include "pch.h"
#include "CppUnitTest.h"
#include "../Domain/stack.h"
#include "../Domain/vector.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
    TEST_CLASS(VectorOperationsTests)
    {
    public:

        TEST_METHOD(TestPushBack)
        {
            VectorOperations<int> vecOps;
            vecOps.push_back(5);
            Assert::AreEqual(5, vecOps.back(), L"Ошибка: Некорректное значение последнего элемента после добавления.");
        }

        TEST_METHOD(TestPopBack)
        {
            VectorOperations<int> vecOps;
            vecOps.push_back(5);
            vecOps.pop_back();
            Assert::ExpectException<std::out_of_range>([&vecOps]() { vecOps.back(); }, L"Ошибка: Доступ к элементу из пустого стека не вызвал исключение.");
        }

        TEST_METHOD(TestBack)
        {
            VectorOperations<int> vecOps;
            vecOps.push_back(10);
            Assert::AreEqual(10, vecOps.back(), L"Ошибка: Некорректное значение после добавления элемента.");
        }
    };
}
