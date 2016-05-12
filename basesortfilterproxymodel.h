#ifndef BASESORTFILTERPROXYMODEL_H
#define BASESORTFILTERPROXYMODEL_H
#include <QSortFilterProxyModel>

class BaseSortFilterProxyModel : public QSortFilterProxyModel
{
    Q_OBJECT
public:
    BaseSortFilterProxyModel(QObject *parent = NULL);

protected:
    bool lessThan(const QModelIndex &left, const QModelIndex &right) const;
};

#endif // BASESORTFILTERPROXYMODEL_H
