#ifndef CERTIFICATEDIALOG_H
#define CERTIFICATEDIALOG_H

// qt
#include <QDialog>
#include <QComboBox>
#include <QMessageBox>
#include "qthelpers.h"

// xbox360
#include <Stfs/StfsDefinitions.h>

namespace Ui {
class CertificateDialog;
}

class CertificateDialog : public QDialog
{
    Q_OBJECT
    
public:
    explicit CertificateDialog(Certificate *cert, QWidget *parent = 0);
    ~CertificateDialog();
    
private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

private:
    Ui::CertificateDialog *ui;
    Certificate *cert;

    QComboBox *cmbxConsoleType;
};

#endif // CERTIFICATEDIALOG_H