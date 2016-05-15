#include "customsortfilterproxymodel.h"
#include "basemodel.h"
#include <QDebug>

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
    qDebug() << "sortujemyProxymodel";
    QVariant left_element =  sourceModel()->data(left);
    QVariant right_element = sourceModel()->data(right);

    if (left_element.type() == QVariant::DateTime) {
        return left_element.toDateTime() > right_element.toDateTime();
    }
    return false;
}

QVariant CustomSortFilterProxyModel::data(const QModelIndex &index, int role) const
{
    QModelIndex index_source = mapToSource(index);
    qDebug() << "dataProxyModel";
    if (!index_source.isValid()) {
        return QVariant();
    }

    BaseModel *base_model = qobject_cast<BaseModel*>(sourceModel());
    if (!base_model) {
        return QVariant();
    }
    if (index_source.row() > base_model->base_element_list.count() || index_source.row() < 0) {
        return QVariant();
    }

    if (role == Qt::DisplayRole) {
        switch (index_source.column()) {
        qDebug() << "column " << index_source.column();
        case BaseModel::Username: return base_model->base_element_list[index.row()]->username();
        case BaseModel::DateCreated: return base_model->base_element_list[index.row()]->date_created();
        case BaseModel::StatementName: return base_model->base_element_list[index.row()]->statement_name();
        case BaseModel::Description: return base_model->base_element_list[index.row()]->description();
        }
    }
    return QVariant();
}
