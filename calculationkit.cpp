#include "calculationkit.h"
#include "QVector"
#include "QPointF"
#include "congif.h"

CalculationKit::CalculationKit(int dotCount, double screenWidth, double screenHeight, QVector <double> vX, QVector <double> vY, QVector <double> vP)
{

    this->dotCount = dotCount;
    this->screenWidth = screenWidth;
    this->screenHeight = screenHeight;
    this->vX = vX;
    this->vY = vY;
    this->vP = vP;

    this->rowCount = dotCount;
    this->columCount = dotCount;

    matrix = QVector< QVector<double> >( dotCount );
    for (int i = 0; i < dotCount; i++)
        matrix[i] = QVector< double >( dotCount );

    rightPart = QVector< double >( dotCount );
    result = QVector< double >( dotCount );

    for (int i = 0; i < dotCount; i++)
    {
        rightPart[i] = 0;
        result[i] = 0;
        for (int j = 0; j < dotCount; j++)
            matrix[i][j] = 0;
    }

}

QVector <QPointF> CalculationKit::calculate()
{

    for (int i = 0; i < this->dotCount; i++)
    {
        for (int j = 0; j < this->dotCount; j++)
        {
            matrix[i][j] = scalarMultXX(i,j);
        }
        rightPart[i] = scalarMultYX(i);
    }
    solveMatrix();

    double y;
    QVector <QPointF> approxArray;
    for (float  j = 0; j < screenWidth; j++)
    {
        y = 0;
        for (int i = 0; i < result.count(); i++)
        {
            y += (result[i] * pow(j, i));
        }
        approxArray.append(QPointF(j, y + screenWidth/2));
    }

    return approxArray;

}

// Стр. 25 - 2.8
double CalculationKit::scalarMultXX(int k, int m)
{
     double res = 0;
     for (int i = 0; i < this->vX.count(); i++)
     {
         res += vP[i] * pow(vX[i], k + m); // (x^k, x^m)
     }
     return res;
 }
double CalculationKit::scalarMultYX(int k)
{
     double res = 0;
     for (int i = 0; i < this->vX.count(); i++)
     {
         res += vP[i] * pow(vX[i], k) * vY[i]; // (y, x^k)
     }
     return res;
 }


#pragma mark Gaus function

void CalculationKit::sortRows(int i)
{
    double max = matrix[i][i];
    int maxIndex = i;
    for (int j = i + 1; j < rowCount; j++)
    {
        if (matrix[j][i] > max)
        {
            max = matrix[j][i];
            maxIndex = j;
        }
    }

    //теперь найден максимальный элемент ставим его на верхнее место
    if (maxIndex > i)//если это не первый элемент
    {
        double temp;

        temp = rightPart[maxIndex];
        rightPart[maxIndex] = rightPart[i];
        rightPart[i] = temp;

        for (int j = 0; j < columCount; j++)
        {
            temp = matrix[maxIndex][j];
            matrix[maxIndex][j] = matrix[i][j];
            matrix[i][j] = temp;
        }
    }
}

int CalculationKit::solveMatrix()
{
    if (rowCount != columCount)
        return 1;

    for (int i = 0; i < rowCount - 1; i++)
    {
        sortRows(i);
        for (int j = i + 1; j < rowCount; j++)
        {
            if (matrix[i][i] != 0) //если главный элемент не 0, то производим вычисления
            {
                double multElement = matrix[j][i] / matrix[i][i];
                for (int k = i; k < columCount; k++)
                    matrix[j][k] -= matrix[i][k] * multElement;
                rightPart[j] -= rightPart[i] * multElement;
            }
            //для нулевого главного элемента просто пропускаем данный шаг
        }
    }

    //ищем решение
    for (int i = (int)(rowCount - 1); i >= 0; i--)
    {
        result[i] = rightPart[i];

        for (int j = (int)(rowCount - 1); j > i; j--)
            result[i] -= matrix[i][j] * result[j];

        if (matrix[i][i] == 0)
            if (rightPart[i] == 0)
                return 2; //множество решений
            else
                return 1; //нет решения

        result[i] /= matrix[i][i];

    }
    return 0;


}
