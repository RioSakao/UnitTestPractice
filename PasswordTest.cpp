/**
 * Unit Tests for Password class
 **/

#include <gtest/gtest.h>
#include "Password.h"

class PasswordTest : public ::testing::Test
{
protected:
	PasswordTest() {}		   // constructor runs before each test
	virtual ~PasswordTest() {} // destructor cleans up after tests
	virtual void SetUp() {}	   // sets up before each test (after constructor)
	virtual void TearDown() {} // clean up after each test, (before destructor)
};

TEST(PasswordTest, smoke_test)
{
	ASSERT_TRUE(1 == 1);
}
TEST(PasswordTest, single_letter_password)
{
	Password my_password;
	int actual = my_password.count_leading_characters("Z");
	ASSERT_EQ(1, actual);
}
TEST(PasswordTest, letters_repeated_at_end)
{
	Password my_password;
	int actual = my_password.count_leading_characters("Zoo");
	ASSERT_EQ(1, actual);
}
TEST(PasswordTest, number_in_password) // sad test case
{
	Password my_password;
	int actual = my_password.count_leading_characters("1");
	ASSERT_EQ(1, actual);
}

TEST(PasswordTest, space_in_password) // sad test case
{
	Password my_password;
	int actual = my_password.count_leading_characters(" ");
	ASSERT_EQ(1, actual);
}
TEST(PasswordTest, mixedcase_in_password) // happy test case
{
	Password my_password;
	bool actual = my_password.has_mixed_case("Aa");
	ASSERT_EQ(true, actual);
}
TEST(PasswordTest, singlecase_in_password) // sad test case
{
	Password my_password;
	bool actual = my_password.has_mixed_case(" A");
	ASSERT_EQ(false, actual);
}

TEST(PasswordTest, set_password)
{
	Password my_password;
	my_password.set("Rsakao021356");
}

TEST(PasswordTest, auth_password)
{
	Password my_password;
	bool actual = my_password.authenticate("Rsakao021356");
	ASSERT_EQ(true, actual);
}

TEST(PasswordTest, empty_password)
{
	Password my_password;
	my_password.set("");
}

TEST(PasswordTest, short_password)
{
	Password my_password;
	my_password.set("abcD");
}

TEST(PasswordTest, same_char_password)
{
	Password my_password;
	my_password.set("aaaaabc346575678eA");
}
TEST(PasswordTest, same_password)
{
	Password my_password;
	my_password.set("ChicoCA-95929");
}

TEST(PasswordTest, only_lower_password)
{
	Password my_password;
	my_password.set("acdgrdijfrh12345");
}