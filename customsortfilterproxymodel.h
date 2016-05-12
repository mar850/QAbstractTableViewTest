#ifndef CUSTOMSORTFILTERPROXYMODEL_H
#define CUSTOMSORTFILTERPROXYMODEL_H
#include <QSortFilterProxyModel>

class CustomSortFilterProxyModel : public QSortFilterProxyModel
{
    Q_OBJECT
public:
    CustomSortFilterProxyModel(QObject *parent = NULL);
    QVariant headerData(int section, Qt::Orientation orientation, int role) const;
    int columnCount(const QModelIndex &parent) const;

    // QSortFilterProxyModel interface
protected:
    bool filterAcceptsRow(int source_row, const QModelIndex &source_parent) const;
    bool lessThan(const QModelIndex &left, const QModelIndex &right) const;
};

#endif // CUSTOMSORTFILTERPROXYMODEL_H
