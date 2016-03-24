#ifndef CALCULATIONKIT_H
#define CALCULATIONKIT_H

#include <QVarLengthArray>
#include <QVector>
#include <QPointF>

class CalculationKit
{
public:
    CalculationKit(int, double, double, QVector <double>, QVector <double>, QVector <double>);
    QVector <QPointF> calculate();

private:
    // Approximation
    int dotCount;
    double screenWidth;
    double screenHeight;
    QVector <double> vX;
    QVector <double> vY;
    QVector <double> vP;

    //
    double scalarMultXX(int, int );
    double scalarMultYX(int);


    // Gaus
    int rowCount;
    int columCount;
    QVector <  QVector <double> >  matrix;
    QVector <double> rightPart;
    QVector <double> result;
    void sortRows(int);
    int solveMatrix();

};

#endif // CALCULATIONKIT_H
