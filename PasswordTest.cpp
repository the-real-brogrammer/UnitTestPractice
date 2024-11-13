/**
 * Unit Tests for Password class
**/

#include <gtest/gtest.h>
#include "Password.h"

class PasswordTest : public ::testing::Test
{
	protected:
		PasswordTest(){} //constructor runs before each test
		virtual ~PasswordTest(){} //destructor cleans up after tests
		virtual void SetUp(){} //sets up before each test (after constructor)
		virtual void TearDown(){} //clean up after each test, (before destructor)
};

TEST(PasswordTest, single_letter_password)
{
	Password my_password;
	int actual = my_password.count_leading_characters("Z");
	ASSERT_EQ(1, actual);
}

TEST(PasswordTest, upper_lower)
{
	Password a_pass;
	int actual = a_pass.has_mixed_case("Aa");
	ASSERT_EQ(1, actual);
}

TEST(PasswordTest, upper_lower_multiple)
{
	Password a_pass;
	int actual = a_pass.has_mixed_case("AaBbCcDdEe");
	ASSERT_EQ(1, actual);
}

TEST(PasswordTest, no_mixed_lower)
{
	Password a_pass;
	int actual = a_pass.has_mixed_case("aaaa");
	ASSERT_EQ(0, actual);
}


TEST(PasswordTest, no_mixed_upper)
{
	Password a_pass;
	int actual = a_pass.has_mixed_case("AAAA");
	ASSERT_EQ(0, actual);
}

TEST(PasswordTest, no_mixed_crazy)
{
	Password a_pass;
	int actual = a_pass.has_mixed_case("!@#$%^&*()0987654321`~=+][|}{';:,.<>?");
	ASSERT_EQ(0, actual);
}
