#include "pch.h"
#include "../Domain/Matrix.h"
#include "../Domain/Task1.h"
#include "../Domain/Task2.h"
#include "../Domain/RandomGenerator.h"
#include "../Domain/IStreamGenerator.h"

TEST(matrix_dataTest, Constructor) {
    matrix<int> matrix_data(3, 3);
    EXPECT_EQ(matrix_data.get_rows(), 3);
    EXPECT_EQ(matrix_data.get_cols(), 3);
}

TEST(matrix_dataTest, SetAndGetElement) {
    matrix<int> matrix_data(3, 3);
    matrix_data.set_element(1, 1, 42);
    EXPECT_EQ(matrix_data.get_element(1, 1), 42);
}

TEST(matrix_dataTest, FillWithConstantValue) {
    matrix<int> matrix_data(2, 2);
    matrix_data.fill([]() { return 5; });
    EXPECT_EQ(matrix_data.get_element(0, 0), 5);
    EXPECT_EQ(matrix_data.get_element(0, 1), 5);
    EXPECT_EQ(matrix_data.get_element(1, 0), 5);
    EXPECT_EQ(matrix_data.get_element(1, 1), 5);
}

TEST(matrix_dataTest, InsertRow) {
    matrix<int> matrix_data(2, 2);
    std::vector<int> newRow = { 7, 8 };
    matrix_data.insert_row(1, newRow);
    EXPECT_EQ(matrix_data.get_rows(), 3);
    EXPECT_EQ(matrix_data.get_element(1, 0), 7);
    EXPECT_EQ(matrix_data.get_element(1, 1), 8);
}

TEST(random_generatorTest, GeneratesIntegerInRange) {
    random_generator<int> generator(1, 10);
    for (int i = 0; i < 100; ++i) {
        int value = generator.generate();
        EXPECT_GE(value, 1);
        EXPECT_LE(value, 10);
    }
}

TEST(random_generatorTest, GeneratesFloatInRange) {
    random_generator<float> generator(1.0f, 10.0f);
    for (int i = 0; i < 100; ++i) {
        float value = generator.generate();
        EXPECT_GE(value, 1.0f);
        EXPECT_LE(value, 10.0f);
    }
}

TEST(i_stream_generatorTest, GeneratesIntegerFromInput) {
    std::istringstream input("42");
    i_stream_generator<int> generator(input);
    EXPECT_EQ(generator.generate(), 42);
}

TEST(i_stream_generatorTest, GeneratesFloatFromInput) {
    std::istringstream input("3.14");
    i_stream_generator<float> generator(input);
    EXPECT_FLOAT_EQ(generator.generate(), 3.14f);
}

TEST(Task1Test, ReplacesMaxInColumnWithZero) {
    Task1<int> task(3, 3);
    task.fill([]() { return 5; });
    task.matrix_data.set_element(1, 0, 42);
    task.perform_task();
    EXPECT_EQ(task.matrix_data.get_element(1, 0), 0);
}

TEST(Task1Test, HandlesSingleColumnmatrix_data) {
    Task1<int> task(3, 1);
    task.fill([]() { return 5; });
    task.matrix_data.set_element(2, 0, 99);
    task.perform_task();
    EXPECT_EQ(task.matrix_data.get_element(2, 0), 0);
}

TEST(Task2Test, InsertsRowAfterRowContainingMaxAbsValue) {
    Task2<int> task(3, 3);
    task.fill([]() { return 5; });
    task.matrix_data.set_element(1, 1, 100);
    task.perform_task();
    EXPECT_EQ(task.matrix_data.get_rows(), 4);
    EXPECT_EQ(task.matrix_data.get_element(2, 0), 5);
}

TEST(Task2Test, HandlesNoMaxAbsValueFound) {
    Task2<int> task(2, 2);
    task.fill([]() { return 1; });
    task.perform_task();
    EXPECT_EQ(task.matrix_data.get_rows(), 4);
}