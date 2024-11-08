#include "pch.h"
#include "../Domain/Vector.h"
#include "../Domain/stack.h"

TEST(Vector_vector_True) {
    Vector<int> vec;
    EXPECT_EQ(vec.get_size(), 0);        
    EXPECT_EQ(vec.get_capacity(), 1);    
}
  

TEST(push_back_element_true) {
    VectorOperations<int> vec_ops;
    vec_ops.push_back(10); 
    EXPECT_EQ(vec_ops.back(), 10);  
}



TEST(back_element_true) {
    VectorOperations<int> vec_ops;
    vec_ops.push_back(5);  
    vec_ops.push_back(10);
    EXPECT_EQ(vec_ops.back(), 10); 
}

TEST(pop_back_element_true) {
    VectorOperations<int> vec_ops;
    vec_ops.push_back(30);  
    vec_ops.push_back(40);
    vec_ops.pop_back();  
    EXPECT_EQ(vec_ops.back(), 30);
}

TEST(copy_constructor_vectors_true) {
    VectorOperations<int> vec_ops1;
    vec_ops1.push_back(1);
    vec_ops1.push_back(2);
    vec_ops1.push_back(3);
    VectorOperations<int> vec_ops2 = vec_ops1;
    EXPECT_EQ(vec_ops2.back(), 3);
    vec_ops1.push_back(4);
    EXPECT_EQ(vec_ops1.back(), 4);
    EXPECT_EQ(vec_ops2.back(), 3);
}

TEST(move_constructor_vectors_true) {
    Vector<int> vec1;
    vec1.push_back(10);
    vec1.push_back(20);

    Vector<int> vec2 = std::move(vec1);

    EXPECT_EQ(vec2.get_size(), 2);
    EXPECT_EQ(vec2[0], 10);
    EXPECT_EQ(vec2[1], 20);

    EXPECT_EQ(vec1.get_size(), 0);
}