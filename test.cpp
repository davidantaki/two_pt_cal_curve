#include <iostream>
#include "TwoPtCalCurve.h"

bool TestCase1()
{
   TwoPtCalCurve<int>::CalPoint calPt1;
   calPt1.expX = 0;
   calPt1.refY = 0;

   TwoPtCalCurve<int>::CalPoint calPt2;
   calPt2.expX = 5;
   calPt2.refY = 5;

   TwoPtCalCurve<int> calCurve(calPt1, calPt2);

   if (calCurve.calibrateVal(2) == 2)
      return true;
   return false;
}

bool TestCase2()
{
   TwoPtCalCurve<float>::CalPoint calPt1;
   calPt1.expX = 20.3;
   calPt1.refY = 28.968;

   TwoPtCalCurve<float>::CalPoint calPt2;
   calPt2.expX = 1.4;
   calPt2.refY = 1.852;

   TwoPtCalCurve<float> calCurve(calPt1, calPt2);

   if (calCurve.calibrateVal(4.5) >= 6.28 && calCurve.calibrateVal(4.5) <= 6.30)
      return true;
   return false;
}

bool TestCase3()
{
   TwoPtCalCurve<float>::CalPoint calPt1;
   calPt1.expX = 1.4;
   calPt1.refY = 1.852;

   TwoPtCalCurve<float>::CalPoint calPt2;
   calPt2.expX = 20.3;
   calPt2.refY = 28.968;

   TwoPtCalCurve<float> calCurve(calPt1, calPt2);

   if (calCurve.calibrateVal(4.5) >= 6.28 && calCurve.calibrateVal(4.5) <= 6.30)
      return true;
   return false;
}

int main(int argc, char *argv[])
{
   std::cout << "TestCase1 returned: " << TestCase1() << std::endl;
   std::cout << "TestCase2 returned: " << TestCase2() << std::endl;
   std::cout << "TestCase3 returned: " << TestCase3() << std::endl;

   std::cout << "Testing complete";
}