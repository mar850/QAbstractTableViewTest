#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "historyelement.h"
#include "basemodel.h"
#include "basesortfilterproxymodel.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    init();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::init()
{
    BaseModel *base_model = new BaseModel(this);
    BaseSortFilterProxyModel *base_sort_filter_proxy_model = new BaseSortFilterProxyModel(this);
    base_sort_filter_proxy_model->setSourceModel(base_model);
    base_model->set_data();
    ui->orginal_tableView->setModel(base_sort_filter_proxy_model);
    ui->orginal_tableView->horizontalHeader()->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->orginal_tableView->setSelectionMode(QAbstractItemView::NoSelection);
    ui->orginal_tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->orginal_tableView->horizontalHeader()->setStretchLastSection(true);
    ui->orginal_tableView->setSortingEnabled(true);
    ui->orginal_tableView->horizontalHeader()->setSortIndicatorShown(true);
    ui->orginal_tableView->horizontalHeader()->setSortIndicator(BaseModel::DateCreated, Qt::DescendingOrder);
    base_sort_filter_proxy_model->sort(BaseModel::DateCreated, Qt::DescendingOrder);

    custom_sort_fileter_proxy_model = new CustomSortFilterProxyModel(this);
    custom_sort_fileter_proxy_model->setSourceModel(base_model);
    ui->custom_tableView->horizontalHeader()->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->custom_tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->custom_tableView->setSelectionMode(QAbstractItemView::SingleSelection);
    ui->custom_tableView->setModel(custom_sort_fileter_proxy_model);
    ui->custom_tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->custom_tableView->horizontalHeader()->setStretchLastSection(true);
    ui->custom_tableView->setSortingEnabled(true);
    ui->custom_tableView->horizontalHeader()->setSortIndicatorShown(true);
    ui->custom_tableView->horizontalHeader()->setSortIndicator(BaseModel::DateCreated, Qt::DescendingOrder);
    base_sort_filter_proxy_model->setDynamicSortFilter(true);
    base_sort_filter_proxy_model->sort(BaseModel::DateCreated, Qt::DescendingOrder);

}

void MainWindow::on_filtr_pushButton_clicked()
{
    custom_sort_fileter_proxy_model->setFilterWildcard(ui->username_lineEdit->text());
    custom_sort_fileter_proxy_model->setFilterKeyColumn(0);
    custom_sort_fileter_proxy_model->setFilterFixedString(ui->username_lineEdit->text());
}
