#ifndef DEVICECONTENTVIEWER_H
#define DEVICECONTENTVIEWER_H

// forms
#include "profileeditor.h"
#include "packageviewer.h"

// qt
#include <QDialog>
#include <QStatusBar>
#include <QList>
#include <QTreeWidgetItem>
#include <QProgressBar>

// std
#include <iostream>
#include <vector>

// xbox
#include "Fatx/XContentDevice.h"
#include "Fatx/FatxDriveDetection.h"

namespace Ui {
class DeviceContentViewer;
}

void DisplayProgress(void *arg, bool finished);

class DeviceContentViewer : public QDialog
{
    Q_OBJECT
    
public:
    explicit DeviceContentViewer(QStatusBar *statusBar, QWidget *parent = 0);
    ~DeviceContentViewer();

    void LoadDevices();
    
private slots:
    void on_treeWidget_itemDoubleClicked(QTreeWidgetItem *item, int column);
    void showContextMenu(const QPoint &pos);
    void on_treeWidget_currentItemChanged(QTreeWidgetItem *current, QTreeWidgetItem *previous);
    void on_btnViewPackage_clicked();

private:
    Ui::DeviceContentViewer *ui;
    QStatusBar *statusBar;
    QList<XContentDevice*> devices;
    StfsPackage *currentPackage;
    QProgressBar *progressBar;

    void resizeEvent(QResizeEvent *);

    void LoadSharedItemCategory(QString category, std::vector<XContentDeviceSharedItem> *items, QTreeWidgetItem *parent, QString iconPath);
    void LoadDevicesp();
    void ClearSidePanel();

    friend void DisplayProgress(void *arg, bool finished);
};

#endif // DEVICECONTENTVIEWER_H