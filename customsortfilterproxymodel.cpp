#include "customsortfilterproxymodel.h"
#include "basemodel.h"

CustomSortFilterProxyModel::CustomSortFilterProxyModel(QObject *parent) :
    QSortFilterProxyModel(parent)
{

}

QVariant CustomSortFilterProxyModel::headerData(int section, Qt::Orientation orientation, int role) const
{
    if (role != Qt::DisplayRole) {
        return QVariant();
    }
    if (orientation == Qt::Horizontal) {
        switch (section) {
        case BaseModel::Username: return tr("Użytkownik");
        case BaseModel::DateCreated: return tr("Data utworzenia");
        }
    }
    return QVariant();
}

int CustomSortFilterProxyModel::columnCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent)
    return BaseModel::DateCreated + 1;
}

bool CustomSortFilterProxyModel::filterAcceptsRow(int source_row, const QModelIndex &source_parent) const
{
    auto index = this->sourceModel()->index(source_row, 0, source_parent);
    if (index.isValid()) {
       return index.data(BaseModel::IsHotNews).toBool();
    }
    return false;
}

bool CustomSortFilterProxyModel::lessThan(const QModelIndex &left, const QModelIndex &right) const
{
    QVariant left_element =  sourceModel()->data(left);
    QVariant right_element = sourceModel()->data(right);

    if (left_element.type() == QVariant::DateTime) {
        return left_element.toDateTime() > right_element.toDateTime();
    }
    return false;
}
