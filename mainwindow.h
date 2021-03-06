#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "customsortfilterproxymodel.h"
#include "basesortfilterproxymodel.h"
#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void init();
private slots:
    void on_filtr_pushButton_clicked();

private:
    Ui::MainWindow *ui;
    CustomSortFilterProxyModel *custom_sort_fileter_proxy_model;
    BaseSortFilterProxyModel *base_sort_filter_proxy_model;
};

#endif // MAINWINDOW_H
