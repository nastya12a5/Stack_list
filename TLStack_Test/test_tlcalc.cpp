#include "../FwrdList_Stack/TLCalc.h"
#include <math.h>
#include "gtest.h"

TEST(TLCalc, can_create_calc_with_right_infix)
{
	TLCalc calc("3*2");
	std::string s = "3*2";
	EXPECT_EQ(1, s == calc.GetInfix());
}
TEST(TLCalc, true_in_right_expr)
{
	TLCalc calc ("2+(3*5)");
	std::string s = "2+(3*5)";
	EXPECT_EQ(true, calc.CheckExpression());
}
TEST(TLCalc, false_in_wrong_expr)
{
	std::string s = "2+(3*5";
	TLCalc calc ("2+(3*5");
	EXPECT_EQ(false, calc.CheckExpression());
}
TEST(TLCalc, right_long_calc)
{
	TLCalc calc( "(((2+2.5)*4^2/2)-5)*5/2.5");
	
	EXPECT_EQ(calc.Calc(), 62);
}

TEST(TLCalc, can_set_infix)
{
	TLCalc calc("3*2");
	std::string s = "2+2";
	calc.SetInfix(s);
	EXPECT_EQ(1, s == calc.GetInfix());
}

TEST(TLCalc, can_calculate_postfix)
{
	TLCalc calc("5+4");
	EXPECT_EQ(9, calc.CalcPostfix());
}


TEST(TLCalc, can_calculate_no_postfix)
{
	TLCalc calc("5/2+4");
	EXPECT_EQ(6.5, calc.Calc());
}





