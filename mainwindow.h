#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QtGui>
#include <QMainWindow>
#include <QApplication>
#include <QDebug>
#include <QMessageBox>

#include "addpointdialog.h"
#include "ui_mainwindow.h"
#include "qpaintwidget.h"
#include "congif.h"
#include "calculationkit.h"

class MainWindow : public  QMainWindow, public Ui::MainWindow
{
    Q_OBJECT

public:
    //explicit MainWindow(QMainWindow *parent = 0);
    ~MainWindow();

    MainWindow(QMainWindow* pwgt = 0) : QMainWindow(pwgt) {

        setupUi(this);

        this->setWindowTitle(kTextTitle);

        //***** QPaintWidget Settings ******

        wgt->setMouseTracking(true);
        wgt->installEventFilter(this);
        wgt->setAutoFillBackground(true);
        QPalette Pal = palette();
        Pal.setColor(QPalette::Background, Qt::white);
        wgt->setPalette(Pal);

        //*******************************

        //***** TableView Settings ******

        tableWidget->setColumnCount(4);
        tableWidget->setFixedWidth(160);
        tableWidget->setColumnWidth(0,26);
        tableWidget->setColumnWidth(1,46);
        tableWidget->setColumnWidth(2,46);
        tableWidget->setColumnWidth(3,46);

        tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
        tableWidget->setSelectionMode(QAbstractItemView:: SingleSelection);
        tableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);
        tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Fixed);
        tableWidget->horizontalHeader()->setSectionsClickable(false);

        tableWidget->setHorizontalHeaderItem(0, new QTableWidgetItem("№"));
        tableWidget->setHorizontalHeaderItem(1, new QTableWidgetItem("X"));
        tableWidget->setHorizontalHeaderItem(2, new QTableWidgetItem("Y"));
        tableWidget->setHorizontalHeaderItem(3, new QTableWidgetItem("P"));

        tableWidget->verticalHeader()->setVisible(false);

        tableWidget->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        tableWidget->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);

        QItemSelectionModel *sm = tableWidget->selectionModel();
        connect(sm, SIGNAL(currentRowChanged(QModelIndex,QModelIndex)),
                this, SLOT(pointSelected(QModelIndex)));
        //*******************************

        //***** Buttons Settings ******
        pushButtonCalcGraph->setText(kBtnCalcGraphText);
        pushButtonQuit->setText(kBtnQuitText);
        pushButtonChangeP->setText(kBtnChangeP);
        //*******************************


        //***** Labels Settings ******
        labelDotCount->setText(kLabelDotCount);
        //*******************************

        //***** LineEdit Settings ******
        lineEditDotCount->setPlaceholderText(kLineEditPlaceHolderDotCount);


        //*******************************
        QObject::connect(pushButtonCalcGraph, SIGNAL(clicked()), this, SLOT(actionCalcGraph()) );
        QObject::connect(pushButtonQuit, SIGNAL(clicked()), this, SLOT(actionQuit()) );
        QObject::connect(pushButtonChangeP, SIGNAL(clicked()), this, SLOT(actionEditPoint()) );
        //*******************************

    }

public slots:
    void actionSetUp()
    {
        for (double x = 0; x < wgt->width(); x += wgt->width() / N)
        {
            tableWidget->insertRow(tableWidget->rowCount());
            tableWidget->setItem(tableWidget->rowCount()-1, 0,  new QTableWidgetItem(QString::number(tableWidget->rowCount())));
            tableWidget->setItem(tableWidget->rowCount()-1, 1,  new QTableWidgetItem(QString::number( x )));
            tableWidget->setItem(tableWidget->rowCount()-1, 2,  new QTableWidgetItem(QString::number( f(x) )));
            tableWidget->setItem(tableWidget->rowCount()-1, 3,  new QTableWidgetItem(QString::number( 1 )));

            wgt->funcArray.append( QPointF(x, f(x) ));

        }
        updateScreen();
    }
    void actionQuit(){
        QApplication::quit();
    }
    void actionCalcGraph(){

        bool isNumber = false;
        int dotNumber = lineEditDotCount->text().toInt(&isNumber);
        if (isNumber)
        {
            QVector <double> vX;
            QVector <double> vY;
            QVector <double> vP;

            //Gettings info from table/
            for (int i = 0; i < tableWidget->rowCount(); i ++)
            {
                QTableWidgetItem *itemX = tableWidget->item(i, 1);
                QTableWidgetItem *itemY = tableWidget->item(i, 2);
                QTableWidgetItem *itemP = tableWidget->item(i, 3);

                double x,y,p;
                bool isXDouble, isYDouble, isPDouble;

                x = itemX->text().toDouble(&isXDouble);
                y = itemY->text().toDouble(&isYDouble);
                p = itemP->text().toDouble(&isPDouble);

                if ( ! ( isXDouble && isYDouble &&  isPDouble) )
                {
                    showMsg( QString("Неверное данные в строке таблицы %1 🌝").arg(QString::number(i)) );
                    return;
                }

                vX.append(x);
                vY.append(y);
                vP.append(p);

            }
            /*************************/

            CalculationKit calcInstance = CalculationKit(dotNumber,wgt->width(), wgt->height(), vX, vY, vP);
            wgt->curveArray = calcInstance.calculate();
            updateScreen();
        }
        else
        {
            showMsg( "Кол-во должно быть положительным целым числом 🌝" );
        }

    }
    void actionEditPoint(){

            if (tableWidget->currentRow() >= 0)
            {
                AddPointDialog* addDialog = new AddPointDialog;
                if (addDialog->exec() == QDialog::Accepted) {

                    double newP = addDialog->P().toFloat();
                    QTableWidgetItem *itemP = tableWidget->item(tableWidget->currentRow(), 3);
                    itemP->setText(QString::number(newP));

                    actionCalcGraph();
                    updateScreen();


                }
                delete addDialog;

            }

        }

private:
    bool eventFilter(QObject *, QEvent *);
    void updateScreen()
    {
        wgt->update();
    }
    void showMsg(QString );

protected:
    void showEvent(QShowEvent *e){
        QWidget::showEvent(e);
        QCoreApplication::processEvents();

        actionSetUp();
    }


};

#endif // MAINWINDOW_H

