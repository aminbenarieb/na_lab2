#include "qpaintwidget.h"
#include "congif.h"

#include <QDebug>
#include <QPainter>

QPaintWidget::QPaintWidget(QWidget * parent) : QWidget(parent)
{
  // Initialization

}

void QPaintWidget::paintEvent(QPaintEvent *) {

    QPainter ppainter(this);

    ppainter.drawPoints(funcArray);
    ppainter.setRenderHint(QPainter::Antialiasing, true);

    for (int i=0; i < funcArray.count()-1; i++)
    {
       ppainter.setPen(QPen(Qt::darkRed, kDrawPenWidth));
       ppainter.drawLine( QPointF(funcArray[i].x(), funcArray[i].y() + this->width()/2 ), QPointF(funcArray[i+1].x(), funcArray[i+1].y() + this->width()/2 ) );
       ppainter.setPen(QPen(Qt::red, kDrawPenWidth));
       ppainter.setBrush(QBrush(Qt::red));
       ppainter.drawEllipse( QPointF(funcArray[i].x(), funcArray[i].y() + this->width()/2 ), kDrawPointRadius, kDrawPointRadius);
    }

    ppainter.setPen(QPen(Qt::blue, kDrawPenWidth));
    ppainter.drawPoints(curveArray);

}
