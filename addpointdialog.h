#ifndef ADDPOINTDIALOG_H
#define ADDPOINTDIALOG_H

#include <QDialog>

class QLineEdit;

class AddPointDialog : public QDialog
{
    Q_OBJECT

private:
    QLineEdit* textFieldP;

public:
    AddPointDialog(QWidget* pwgt = 0);
    QString P() const;

signals:
public slots:

};

#endif // ADDPOINTDIALOG_H
