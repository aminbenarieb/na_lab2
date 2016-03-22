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

    ppainter.setPen(QPen(Qt::green, kDrawPenWidth));
    ppainter.drawPoints(funcArray);

    ppainter.setPen(QPen(Qt::blue, kDrawPenWidth));
    ppainter.drawPoints(curveArray);

}
