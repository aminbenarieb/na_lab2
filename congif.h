#ifndef CONGIF_H
#define CONGIF_H

#include "math.h"

#define kTextTitle "Среднеквадратичное приближение"
#define kBtnCalcGraphText "Постоить график"
#define kBtnChangeP "Изменить вес"
#define kBtnQuitText "Выйти"
#define kLabelDotCount "Кол-во точек"
#define kLineEditPlaceHolderDotCount "3"

#define kDialogLabelTextP "Новый вес"
#define kDialogBtnTextOK "ОК"
#define kDialogBtnTextCancel "Отмена"

#define kDrawPointRadius 3
#define kDrawPenWidth 1

#define kmin(a, b) ( ( a < b) ? a : b )
#define kmax(a, b) ( ( a > b) ? a : b )

#define kRadianToDegree(radian) ( radian*180/M_PI )
#define kDegreeToRadian(degree) ( degree*M_PI/180 )

#define N 6
#define f(x) ( 100 * cos ( kDegreeToRadian (x) ) )

#endif // CONGIF_H
