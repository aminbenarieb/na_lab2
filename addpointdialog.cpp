#include "addpointdialog.h"
#include "congif.h"

#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QGridLayout>

AddPointDialog::AddPointDialog(QWidget* pwgt/*= 0*/)
    : QDialog(pwgt, Qt::WindowTitleHint | Qt::WindowSystemMenuHint)
{

    textFieldP = new QLineEdit;
    QLabel* labelP = new QLabel(kDialogLabelTextP);
    labelP->setBuddy(textFieldP);
    QPushButton* pcmdOk = new QPushButton(kDialogBtnTextOK);
    QPushButton* pcmdCancel = new QPushButton(kDialogBtnTextCancel);
    connect(pcmdOk, SIGNAL(clicked()), SLOT(accept()));
    connect(pcmdCancel, SIGNAL(clicked()), SLOT(reject()));

    //Layout setup
    QGridLayout* ptopLayout = new QGridLayout;
    ptopLayout->addWidget(labelP, 0, 0);
    ptopLayout->addWidget(textFieldP, 1, 1);
    ptopLayout->addWidget(pcmdOk, 2,0);
    ptopLayout->addWidget(pcmdCancel, 2, 1);
    setLayout(ptopLayout);

}

QString AddPointDialog::P() const {
    return textFieldP->text();
}

