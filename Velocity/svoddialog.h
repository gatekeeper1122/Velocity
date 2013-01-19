#ifndef SVODDIALOG_H
#define SVODDIALOG_H

// qt
#include <QDialog>
#include <QTreeWidgetItem>
#include <QMenu>
#include <QMessageBox>
#include <QFileDialog>
#include <QUuid>
#include "qthelpers.h"

// xbox
#include "Disc/svod.h"
#include "IO/SvodIO.h"
#include "Stfs/StfsPackage.h"

// forms
#include "svodfileinfodialog.h"
#include "svodtooldialog.h"
#include "multiprogressdialog.h"
#include "imagedialog.h"
#include "metadata.h"
#include "packageviewer.h"
#include "singleprogressdialog.h"

namespace Ui {
class SvodDialog;
}

Q_DECLARE_METATYPE( GDFXFileEntry* )

class SvodDialog : public QDialog
{
    Q_OBJECT
    
public:
    explicit SvodDialog(SVOD *svod, QStatusBar *statusBar, QWidget *parent = 0);
    ~SvodDialog();
    
private slots:
    void showFileContextMenu(QPoint pos);

    void on_btnViewAll_clicked();

    void on_pushButton_clicked();

    void on_txtSearch_textChanged(const QString &arg1);

    void on_btnShowAll_clicked();

    void on_pushButton_3_clicked();

    void on_comboBox_currentIndexChanged(int index);

    void on_treeWidget_itemDoubleClicked(QTreeWidgetItem *item, int column);

private:
    Ui::SvodDialog *ui;
    SVOD *svod;
    QStatusBar *statusBar;
    bool changing;

    void loadListing(QTreeWidgetItem *parent, vector<GDFXFileEntry> *files);

    friend void UpdateProgress(DWORD cur, DWORD total, void *arg);
};

void UpdateProgress(DWORD cur, DWORD total, void *arg);

#endif // SVODDIALOG_H