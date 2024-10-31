#include "pch.h"
#include "CppUnitTest.h"
#include "../Domain/vector.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
    TEST_CLASS(VectorTests)
    {
    public:
        TEST_METHOD(TestIncreaseSize)
        {
            Vector<int> vec;
            vec.increase_size();
            vec.get_data()[0] = 10;
            Assert::AreEqual((size_t)1, vec.get_size(), L"Ошибка: Некорректный размер после добавления элемента.");
            Assert::AreEqual(10, vec.get_data()[0], L"Ошибка: Некорректное значение после добавления элемента.");
        }

        TEST_METHOD(TestCopyConstructor)
        {
            Vector<int> vec;
            vec.increase_size();
            vec.get_data()[0] = 42;
            Vector<int> copyVec = vec;
            Assert::AreEqual(copyVec.get_size(), vec.get_size(), L"Ошибка: Копия не совпадает по размеру.");
            Assert::AreEqual(copyVec.get_data()[0], vec.get_data()[0], L"Ошибка: Копия не совпадает по данным.");
        }

        TEST_METHOD(TestMoveConstructor)
        {
            Vector<int> vec;
            vec.increase_size();
            vec.get_data()[0] = 42;

            Vector<int> movedVec = std::move(vec);
            Assert::AreEqual((size_t)1, movedVec.get_size(), L"Ошибка: Размер перемещенного вектора не совпадает.");
            Assert::AreEqual(42, movedVec.get_data()[0], L"Ошибка: Некорректные данные в перемещенном векторе.");
            Assert::IsNull(vec.get_data(), L"Ошибка: Исходный вектор не освобожден после перемещения.");
        }

        TEST_METHOD(TestCopyAssignment)
        {
            Vector<int> vec1;
            vec1.increase_size();
            vec1.get_data()[0] = 42;

            Vector<int> vec2;
            vec2 = vec1;

            Assert::AreEqual(vec1.get_size(), vec2.get_size(), L"Ошибка: Размеры векторов не совпадают после присваивания.");
            Assert::AreEqual(vec1.get_data()[0], vec2.get_data()[0], L"Ошибка: Данные векторов не совпадают после присваивания.");
        }

        TEST_METHOD(TestResize)
        {
            Vector<int> vec;
            vec.increase_size();
            vec.increase_size();
            Assert::AreEqual((size_t)2, vec.get_capacity(), L"Ошибка: Вместимость не увеличена в два раза после изменения размера.");
        }
    };
}
