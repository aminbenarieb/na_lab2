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
    ppainter.setBrush(QBrush(Qt::transparent));

    ppainter.setPen(QPen(Qt::red, kDrawPenWidth));
    ppainter.drawPoints(funcArray);

    for (int i=0; i < funcArray.count()-1; i++)
       ppainter.drawLine( QPointF(funcArray[i].x(), funcArray[i].y() + this->width()/2 ), QPointF(funcArray[i+1].x(), funcArray[i+1].y() + this->width()/2 ) );

    ppainter.setPen(QPen(Qt::blue, kDrawPenWidth));
    ppainter.drawPoints(curveArray);

}
