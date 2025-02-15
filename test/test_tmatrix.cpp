#include "tmatrix.h"

#include <gtest.h>

TEST(TDynamicMatrix, can_create_matrix_with_positive_length)
{
	ASSERT_NO_THROW(TDynamicMatrix<int> m(5));
}

TEST(TDynamicMatrix, cant_create_too_large_matrix)
{
	ASSERT_ANY_THROW(TDynamicMatrix<int> m(MAX_MATRIX_SIZE + 1));
}

TEST(TDynamicMatrix, throws_when_create_matrix_with_negative_length)
{
	ASSERT_ANY_THROW(TDynamicMatrix<int> m(-5));
}

TEST(TDynamicMatrix, can_create_copied_matrix)
{
	TDynamicMatrix<int> m(5);
	
	ASSERT_NO_THROW(TDynamicMatrix<int> m1(m));
}

TEST(TDynamicMatrix, copied_matrix_is_equal_to_source_one)
{
	TDynamicMatrix<int> m1(2);
	m1[0][0] = 2;
	m1[0][1] = 4;
	m1[1][0] = 6;
	m1[1][1] = 8;
	
	TDynamicMatrix<int> m2(m1);
	
	EXPECT_EQ(m1, m2);
}

TEST(TDynamicMatrix, copied_matrix_has_its_own_memory)
{
	TDynamicMatrix<int> m1(2);
	m1[0][0] = 1; 
	m1[0][1] = 3;
	m1[1][0] = 5;
	m1[1][1] = 7;
	
	TDynamicMatrix<int> m2(m1);
	m2[0][0] = 2;
	m2[0][1] = 4;
	m2[1][0] = 6;
	m2[1][1] = 8;
	
	EXPECT_EQ(m1[0][0], 1);
	EXPECT_EQ(m2[0][0], 2);
}

TEST(TDynamicMatrix, can_get_size)
{
	TDynamicMatrix<int> m(5);
	
	EXPECT_EQ(5, m.size());
}

TEST(TDynamicMatrix, can_set_and_get_element)
{
	TDynamicMatrix<int> m(2);
	m[1][1] = 1;
	
	EXPECT_EQ(m[1][1], 1);
}

TEST(TDynamicMatrix, throws_when_set_element_with_negative_index)
{
	TDynamicMatrix<int> m(2);
	
	ASSERT_ANY_THROW(m.at(- 1,1) = 2);
}

TEST(TDynamicMatrix, throws_when_set_element_with_too_large_index)
{
	TDynamicMatrix<int> m(2);
	
	ASSERT_ANY_THROW(m.at(5, 2) = 2);
}

TEST(TDynamicMatrix, can_assign_matrix_to_itself)
{
	TDynamicMatrix<int> m(2);
	
	ASSERT_NO_THROW(m = m);
}

TEST(TDynamicMatrix, can_assign_matrix_to_itself_correct)
{
	TDynamicMatrix<int> m(2);
	m[0][0] = 2;
	m[0][1] = 4;
	m[1][0] = 6;
	m[1][1] = 8;

	m = m;
	
	EXPECT_EQ(4, m[0][1]);
}

TEST(TDynamicMatrix, can_assign_matrices_of_equal_size)
{
	TDynamicMatrix<int> m1(2);
	TDynamicMatrix<int> m2(2);

	ASSERT_NO_THROW(m2 = m1);
}

TEST(TDynamicMatrix, can_assign_matrices_of_equal_size_correct)
{
	TDynamicMatrix<int> m1(2);
	m1[0][0] = 1;
	m1[0][1] = 3;
	m1[1][0] = 5;
	m1[1][1] = 7;

	TDynamicMatrix<int> m2(2);
	m2 = m1;

	EXPECT_EQ(3, m2[0][1]);
}

TEST(TDynamicMatrix, assign_operator_change_matrix_size)
{
	TDynamicMatrix<int> m1(2);
	m1[0][0] = 2;
	m1[0][1] = 4;
	m1[1][0] = 6;
	m1[1][1] = 8;

	TDynamicMatrix<int> m2(5);
	m2 = m1;

	EXPECT_EQ(2, m2.size());
}

TEST(TDynamicMatrix, can_assign_matrices_of_different_size)
{
	TDynamicMatrix<int> m1(2);
	TDynamicMatrix<int> m2(5);
	
	ASSERT_NO_THROW(m2 = m1);
}

TEST(TDynamicMatrix, can_assign_matrices_of_different_size_correct)
{
	TDynamicMatrix<int> m1(2);
	m1[0][0] = 1;
	m1[0][1] = 3;
	m1[1][0] = 5;
	m1[1][1] = 7;

	TDynamicMatrix<int> m2(5);
	m2 = m1;

	EXPECT_EQ(3, m2[0][1]); 
}

TEST(TDynamicMatrix, compare_equal_matrices_return_true)
{
	TDynamicMatrix<int> m1(2);
	m1[0][0] = 2;
	m1[0][1] = 4;
	m1[1][0] = 6;
	m1[1][1] = 8;

	TDynamicMatrix<int> m2(2);
	m2 = m1;

	EXPECT_TRUE(m1 == m2);
}

TEST(TDynamicMatrix, compare_matrix_with_itself_return_true)
{
	TDynamicMatrix<int> m(2);
	m[0][0] = 1;
	m[0][1] = 3;
	m[1][0] = 5;
	m[1][1] = 7;

	EXPECT_TRUE(m == m); 
}

TEST(TDynamicMatrix, matrices_with_different_size_are_not_equal)
{
	TDynamicMatrix<int> m1(2);
	TDynamicMatrix<int> m2(5);

	EXPECT_NE(m1, m2);   
}

TEST(TDynamicMatrix, can_multiply_matrix_by_scalar)
{
	TDynamicMatrix<int> m1(2);
	
	ASSERT_NO_THROW(m1 * 2);
}

TEST(TDynamicMatrix, can_multiply_matrix_by_scalar_correct)
{
	TDynamicMatrix<int> m1(2);
	m1[0][0] = 1;
	m1[0][1] = 3;
	m1[1][0] = 5;
	m1[1][1] = 7;
	m1 = m1 * 2;

	TDynamicMatrix<int> m2(2);
	m2[0][0] = 2;
	m2[0][1] = 6;
	m2[1][0] = 10;
	m2[1][1] = 14;

	EXPECT_EQ(m1, m2);
}

TEST(TDynamicMatrix, can_multiply_matrix_by_vector_with_equal_size)
{
	TDynamicMatrix<int> m(2);
	TDynamicVector<int> v(2);
	
	ASSERT_NO_THROW(m * v);
}

TEST(TDynamicMatrix, can_multiply_matrix_by_vector_with_equal_size_correct)
{
	TDynamicMatrix<int> m(2);
	m[0][0] = 1;
	m[0][1] = 3;
	m[1][0] = 5;
	m[1][1] = 7;
	
	TDynamicVector<int> v(2);
	v[0] = 2;
	v[1] = 4;

	TDynamicVector<int> res(2);
	res[0] = 14;
	res[1] = 38;
	
	EXPECT_EQ(res, m * v);
}

TEST(TDynamicMatrix, cant_multiply_matrix_by_vector_with_not_equal_size)
{
	TDynamicMatrix<int> m(2);
	TDynamicVector<int> v(5);

	ASSERT_ANY_THROW(m * v);
}

TEST(TDynamicMatrix, can_add_matrices_with_equal_size)
{
	TDynamicMatrix<int> m1(2);
	TDynamicMatrix<int> m2(2);
	
	ASSERT_NO_THROW(m1 + m2);
}

TEST(TDynamicMatrix, can_add_matrices_with_equal_size_correct)
{
	TDynamicMatrix<int> m1(2);
	m1[0][0] = 2;
	m1[0][1] = 4;
	m1[1][0] = 6;
	m1[1][1] = 8;

	TDynamicMatrix<int> m2(2);
	m2[0][0] = 1;
	m2[0][1] = 3;
	m2[1][0] = 5;
	m2[1][1] = 7;

	TDynamicMatrix<int> m3(2);
	m3[0][0] = 3;
	m3[0][1] = 7;
	m3[1][0] = 11;
	m3[1][1] = 15;
	
	EXPECT_EQ(m3, m1 + m2);
}

TEST(TDynamicMatrix, cant_add_matrices_with_not_equal_size)
{
	TDynamicMatrix<int> m1(2);
	TDynamicMatrix<int> m2(5);

	ASSERT_ANY_THROW(m1 + m2);
}

TEST(TDynamicMatrix, can_subtract_matrices_with_equal_size)
{
	TDynamicMatrix<int> m1(2);
	TDynamicMatrix<int> m2(2);
	
	ASSERT_NO_THROW(m1 - m2);
}

TEST(TDynamicMatrix, can_subtract_matrices_with_equal_size_correct)
{
	TDynamicMatrix<int> m1(2);
	m1[0][0] = 2;
	m1[0][1] = 4;
	m1[1][0] = 6;
	m1[1][1] = 8;

	TDynamicMatrix<int> m2(2);
	m2[0][0] = 1;
	m2[0][1] = 3;
	m2[1][0] = 5;
	m2[1][1] = 7;

	TDynamicMatrix<int> m3(2);
	m3[0][0] = 1;
	m3[0][1] = 1;
	m3[1][0] = 1;
	m3[1][1] = 1;
	
	EXPECT_EQ(m3, m1 - m2);
}

TEST(TDynamicMatrix, cant_subtract_matrices_with_not_equal_size)
{
	TDynamicMatrix<int> m1(2);
	TDynamicMatrix<int> m2(5);

	ASSERT_ANY_THROW(m1 - m2);
}

TEST(TDynamicMatrix, can_multiply_matrices_with_equal_size)
{
	TDynamicMatrix<int> m1(2);
	TDynamicMatrix<int> m2(2);
	
	ASSERT_NO_THROW(m1 * m2);
}

TEST(TDynamicMatrix, can_multiply_matrices_with_equal_size_correct)
{
	TDynamicMatrix<int> m1(2);
	m1[0][0] = 2;
	m1[0][1] = 4;
	m1[1][0] = 6;
	m1[1][1] = 8;

	TDynamicMatrix<int> m2(2);
	m2[0][0] = 1;
	m2[0][1] = 3;
	m2[1][0] = 5;
	m2[1][1] = 7;

	TDynamicMatrix<int> m3(2); 
	m3[0][0] = 22;
	m3[0][1] = 34;
	m3[1][0] = 46;
	m3[1][1] = 74;
	
	EXPECT_EQ(m3, m1 * m2);
}

TEST(TDynamicMatrix, cant_multiply_matrices_with_not_equal_size)
{
	TDynamicMatrix<int> m1(2);
	TDynamicMatrix<int> m2(5);

	ASSERT_ANY_THROW(m1 * m2);
}
