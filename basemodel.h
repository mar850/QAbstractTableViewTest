#ifndef BASEMODEL_H
#define BASEMODEL_H

#include "historyelement.h"
#include "statementelement.h"
#include <QAbstractTableModel>
#include <QDateTime>

class BaseModel : public  QAbstractTableModel
{
    Q_OBJECT

public:
    enum ColumnName {
        Username = Qt::DisplayRole,
        DateCreated = 1,
        StatementName = 2,
        Description = 3,
        IsHotNews = 4,
        Last = StatementName,
    };

    BaseModel(QObject *parent = NULL);
    int rowCount(const QModelIndex &parent) const;
    int columnCount(const QModelIndex &parent) const;
    QVariant data(const QModelIndex &index, int role) const;
    void set_data();
    QDateTime create_date_time();

    QList<HistoryElement*> base_element_list;
    QVariant headerData(int section, Qt::Orientation orientation, int role) const;
};

#endif // BASEMODEL_H
