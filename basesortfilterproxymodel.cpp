#include "basesortfilterproxymodel.h"
#include <QDebug>
#include <QDateTime>

BaseSortFilterProxyModel::BaseSortFilterProxyModel(QObject *parent) :
    QSortFilterProxyModel(parent)
{

}

bool BaseSortFilterProxyModel::lessThan(const QModelIndex &left, const QModelIndex &right) const
{
    QVariant left_element =  sourceModel()->data(left);
    QVariant right_element = sourceModel()->data(right);

    if (left_element.type() == QVariant::DateTime) {
        qDebug() << "sortujemy";
        return left_element.toDateTime() > right_element.toDateTime();
    }
    return false;
}

