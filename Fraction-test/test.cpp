#include "pch.h"
#include "UFract.h"
#include "TFract.cpp"

TFract f1(1, 3);
TFract f2(2, 3);
TFract f3(5, 6);
TFract f4(3, 7);
TFract f5(9, 10);
TFract f6(-2, 3);
TFract f7(-4, 6);
TEST(TFractTest, CreateTest) {
  EXPECT_EQ(TFract(2, 10).getTFractString(), "1/5");
  EXPECT_EQ(TFract(1, 3).getTFractString(), "1/3");
  EXPECT_EQ(TFract(10, 3).getTFractString(), "10/3");
  EXPECT_EQ(TFract(5, 6).getTFractString(), "5/6");
  EXPECT_EQ(TFract(3, 7).getTFractString(), "3/7");
  EXPECT_EQ(TFract(12, 24).getTFractString(), "1/2");
  EXPECT_EQ(TFract(0, 99).getTFractString(), "0/1");
  EXPECT_EQ(TFract(-3, 7).getTFractString(), "-3/7");
  EXPECT_EQ(TFract(-2, -24).getTFractString(), "1/12");
  EXPECT_EQ(TFract(-1, 0).getTFractString(), "0/1");
}

TEST(TFractTest, CreateTestString) {
 	EXPECT_EQ(TFract("2/10").getTFractString(), "1/5");
	EXPECT_EQ(TFract("1/3").getTFractString(), "1/3");
	EXPECT_EQ(TFract("10/3").getTFractString(), "10/3");
	EXPECT_EQ(TFract("5/6").getTFractString(), "5/6");
	EXPECT_EQ(TFract("3/7").getTFractString(), "3/7");
	EXPECT_EQ(TFract("12/24").getTFractString(), "1/2");
	EXPECT_EQ(TFract("0/99").getTFractString(), "0/1");
	EXPECT_EQ(TFract("-3/7").getTFractString(), "-3/7");
	EXPECT_EQ(TFract("-2/-24").getTFractString(), "1/12");
	EXPECT_EQ(TFract("-1/0").getTFractString(), "0/1");
}

TEST(TFractTest, AddTest) {
	EXPECT_EQ(f1.add(f2).getTFractString(), TFract(1, 1).getTFractString());
	EXPECT_EQ(f1.add(f3).getTFractString(), TFract(7, 6).getTFractString());
	EXPECT_EQ(f1.add(f4).getTFractString(), TFract(16, 21).getTFractString());
	EXPECT_EQ(f1.add(f5).getTFractString(), TFract(37,30).getTFractString());
	EXPECT_EQ(f1.add(f6).getTFractString(), TFract(-1, 3).getTFractString());
	EXPECT_EQ(f1.add(f7).getTFractString(), TFract(-1, 3).getTFractString());
}

TEST(TFractTest, SubTest) {
	EXPECT_EQ(f1.sub(f2).getTFractString(), TFract(-1, 3).getTFractString());
	EXPECT_EQ(f1.sub(f3).getTFractString(), TFract(-1, 2).getTFractString());
	EXPECT_EQ(f1.sub(f4).getTFractString(), TFract(-2, 21).getTFractString());
	EXPECT_EQ(f1.sub(f5).getTFractString(), TFract(-17, 30).getTFractString());
	EXPECT_EQ(f1.sub(f6).getTFractString(), TFract(1, 1).getTFractString());
	EXPECT_EQ(f1.sub(f7).getTFractString(), TFract(1, 1).getTFractString());
}

TEST(TFractTest, MultiplyTest) {
	EXPECT_EQ(f1.multiply(f2).getTFractString(), TFract(2, 9).getTFractString());
	EXPECT_EQ(f1.multiply(f3).getTFractString(), TFract(5, 18).getTFractString());
	EXPECT_EQ(f1.multiply(f4).getTFractString(), TFract(1, 7).getTFractString());
	EXPECT_EQ(f1.multiply(f5).getTFractString(), TFract(3, 10).getTFractString());
	EXPECT_EQ(f1.multiply(f6).getTFractString(), TFract(-2, 9).getTFractString());
	EXPECT_EQ(f1.multiply(f7).getTFractString(), TFract(-2, 9).getTFractString());
}

TEST(TFractTest, DivideTest) {
	EXPECT_EQ(f1.divide(f2).getTFractString(), TFract(1, 2).getTFractString());
	EXPECT_EQ(f1.divide(f3).getTFractString(), TFract(2, 5).getTFractString());
	EXPECT_EQ(f1.divide(f4).getTFractString(), TFract(7, 9).getTFractString());
	EXPECT_EQ(f1.divide(f5).getTFractString(), TFract(10, 27).getTFractString());
	EXPECT_EQ(f1.divide(f6).getTFractString(), TFract(-1, 2).getTFractString());
	EXPECT_EQ(f1.divide(f7).getTFractString(), TFract(-1, 2).getTFractString());
}

TEST(TFractTest, SquareTest) {
	EXPECT_EQ(f1.square().getTFractString(), TFract(1, 9).getTFractString());
	EXPECT_EQ(f2.square().getTFractString(), TFract(4, 9).getTFractString());
	EXPECT_EQ(f3.square().getTFractString(), TFract(25, 36).getTFractString());
	EXPECT_EQ(f4.square().getTFractString(), TFract(9, 49).getTFractString());
	EXPECT_EQ(f5.square().getTFractString(), TFract(81, 100).getTFractString());
	EXPECT_EQ(f6.square().getTFractString(), TFract(4, 9).getTFractString());
}

TEST(TFractTest,MinusTest) {
	EXPECT_EQ(f1.minus().getTFractString(), TFract(-1, 3).getTFractString());
	EXPECT_EQ(f2.minus().getTFractString(), TFract(-2, 3).getTFractString());
	EXPECT_EQ(f3.minus().getTFractString(), TFract(-5, 6).getTFractString());
	EXPECT_EQ(f4.minus().getTFractString(), TFract(-3, 7).getTFractString());
	EXPECT_EQ(f5.minus().getTFractString(), TFract(-9, 10).getTFractString());
	EXPECT_EQ(f6.minus().getTFractString(), TFract(2, 3).getTFractString());
}
TEST(TFractTest, EqualsTest) {
	EXPECT_TRUE(f1.equals(f1));
	EXPECT_FALSE(f1.equals(f2));
	EXPECT_TRUE(f6.equals(f7));
	EXPECT_FALSE(f1.equals(f3));
}


TEST(TFractTest, GetStringTest) {
	EXPECT_EQ(f1.getTFractString(), "1/3");
	EXPECT_EQ(f2.getTFractString(), "2/3");
	EXPECT_EQ(f3.getTFractString(), "5/6");
	EXPECT_EQ(f4.getTFractString(), "3/7");
	EXPECT_EQ(f5.getTFractString(), "9/10");
}

TEST(TFractTest, GetNumeratorNumber) {
	EXPECT_EQ(f1.getNumeratorNumber(), 1.0);
	EXPECT_EQ(f2.getNumeratorNumber(), 2.0);
	EXPECT_EQ(f3.getNumeratorNumber(), 5.0);
	EXPECT_EQ(f4.getNumeratorNumber(), 3.0);
	EXPECT_EQ(f5.getNumeratorNumber(), 9.0);
	EXPECT_EQ(f6.getNumeratorNumber(), -2.0);
}

TEST(TFractTest, GetNumeratorString) {
	string f1NumeratorString = "1";
	string f2NumeratorString = "2";
	string f3NumeratorString = "5";
	string f4NumeratorString = "3";
	string f5NumeratorString = "9";
	string f6NumeratorString = "-2";
	EXPECT_EQ(f1.getNumeratorString(), f1NumeratorString);
	EXPECT_EQ(f2.getNumeratorString(), f2NumeratorString);
	EXPECT_EQ(f3.getNumeratorString(), f3NumeratorString);
	EXPECT_EQ(f4.getNumeratorString(), f4NumeratorString);
	EXPECT_EQ(f5.getNumeratorString(), f5NumeratorString);
	EXPECT_EQ(f6.getNumeratorString(), f6NumeratorString);
}

TEST(TFractTest, GetDenumeratorNumber) {
	EXPECT_EQ(f1.getDenumeratorNumber(), 3.0);
	EXPECT_EQ(f2.getDenumeratorNumber(), 3.0);
	EXPECT_EQ(f3.getDenumeratorNumber(), 6.0);
	EXPECT_EQ(f4.getDenumeratorNumber(), 7.0);
	EXPECT_EQ(f5.getDenumeratorNumber(), 10.0);
	EXPECT_EQ(f6.getDenumeratorNumber(), 3.0);
}

TEST(TFractTest, GetDenumeratorString) {
	string f1DenumeratorString = "3";
	string f2DenumeratorString = "3";
	string f3DenumeratorString = "6";
	string f4DenumeratorString = "7";
	string f5DenumeratorString = "10";
	string f6DenumeratorString = "3";
	EXPECT_EQ(f1.getDenumeratorString(), f1DenumeratorString);
	EXPECT_EQ(f2.getDenumeratorString(), f2DenumeratorString);
	EXPECT_EQ(f3.getDenumeratorString(), f3DenumeratorString);
	EXPECT_EQ(f4.getDenumeratorString(), f4DenumeratorString);
	EXPECT_EQ(f5.getDenumeratorString(), f5DenumeratorString);
	EXPECT_EQ(f6.getDenumeratorString(), f6DenumeratorString);
}

TEST(TFractTest, GreaterTest) {
	EXPECT_TRUE(f2.isGreater(f1));
	EXPECT_TRUE(f3.isGreater(f1));
	EXPECT_TRUE(f5.isGreater(f4));
	EXPECT_TRUE(f5.isGreater(f7));
	EXPECT_FALSE(f1.isGreater(f2));
	EXPECT_FALSE(f1.isGreater(f3));
	EXPECT_FALSE(f4.isGreater(f5));
	EXPECT_FALSE(f7.isGreater(f5));
}

TEST(TFractTest, ReverseTest) {
	EXPECT_EQ(f1.reverse().getTFractString(), TFract(3, 1).getTFractString());
	EXPECT_EQ(f2.reverse().getTFractString(), TFract(3, 2).getTFractString());
	EXPECT_EQ(f3.reverse().getTFractString(), TFract(6, 5).getTFractString());
	EXPECT_EQ(f4.reverse().getTFractString(), TFract(7, 3).getTFractString());
	EXPECT_EQ(f5.reverse().getTFractString(), TFract(10, 9).getTFractString());
	EXPECT_EQ(f6.reverse().getTFractString(), TFract(-3, 2).getTFractString());
}

TEST(TFractTest, CopyTest) {
	EXPECT_EQ(f1.copy().getTFractString(), TFract(1, 3).getTFractString());
	EXPECT_EQ(f2.copy().getTFractString(), TFract(2, 3).getTFractString());
	EXPECT_EQ(f6.copy().getTFractString(), TFract(-2, 3).getTFractString());
}
