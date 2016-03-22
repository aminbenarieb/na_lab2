#ifndef QPAINTWIDGET_H
#define QPAINTWIDGET_H

#include <QWidget>
#include <QVarLengthArray>

class QPaintEvent;

class QPaintWidget : public QWidget
{
    Q_OBJECT
public:
    QPaintWidget(QWidget * parent = 0);
     QVector <QPointF> funcArray;
     QVector <QPointF> curveArray;


protected:
    void paintEvent(QPaintEvent *);
};

#endif // QPAINTWIDGET_H
