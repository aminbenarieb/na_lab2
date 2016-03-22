#ifndef CONGIF_H
#define CONGIF_H

#include "math.h"

#define kTextTitle "Среднеквадратичное приближение"
#define kBtnCalcGraphText "Постоить график"
#define kBtnQuitText "Выйти"
#define kLabelDotCount "Кол-во точек"
#define kLineEditPlaceHolderDotCount "3"

#define kDrawPointRadius 3
#define kDrawPenWidth 1

#define kmin(a, b) ( ( a < b) ? a : b )
#define kmax(a, b) ( ( a > b) ? a : b )

#define kRadianToDegree(radian) ( radian*180/M_PI )
#define kDegreeToRadian(degree) ( degree*M_PI/180 )

#define N 10
#define f(x) ( cos ( x ) )

#endif // CONGIF_H
