#include "basemodel.h"
#include <cstdlib>

BaseModel::BaseModel(QObject *parent) :
    QAbstractTableModel(parent)
{
    srand(time(NULL));
}

int BaseModel::rowCount(const QModelIndex &parent) const
{
    return base_element_list.count();
}

int BaseModel::columnCount(const QModelIndex &parent) const
{
    return Last + 1;
}

QVariant BaseModel::data(const QModelIndex &index, int role) const
{
    if (!index.isValid()) {
        return QVariant();
    }

    if (index.row() > base_element_list.count() || index.row() < 0) {
        return QVariant();
    }

    if (role == Qt::DisplayRole) {
        switch (index.column()) {
        case Username: return base_element_list[index.row()]->username();
        case DateCreated: return base_element_list[index.row()]->date_created();
        case StatementName: return base_element_list[index.row()]->statement_name();
        case Description: return base_element_list[index.row()]->description();
        }
    }

    switch (role) {
        case IsHotNews: return base_element_list[index.row()]->is_hot_news();
    }
    return QVariant();
}

void BaseModel::set_data()
{
    for (int i = 0; i < 5; ++i) {
        for (int j = 0; j < 4; ++j) {
                HistoryElement *history_element = new HistoryElement;
                history_element->set_date_created(create_date_time());
                history_element->set_is_hot_news(false);
                switch (i) {
                case 0: history_element->set_usrname("Stefan");break;
                case 1: history_element->set_usrname("Wiesławo"); break;
                case 2: history_element->set_usrname("Karol"); break;
                case 3: history_element->set_usrname("Mieczysław"); break;
                case 4: history_element->set_usrname("Zdzisławo"); break;
                default:
                    break;
                }
                base_element_list.append(history_element);
                if (j == 0) {
                    history_element->set_is_hot_news(true);
                } else {
                    history_element->set_is_hot_news(false);
                }
         }
    }
}

QDateTime BaseModel::create_date_time()
{
    QDateTime date_time;
    date_time.setDate(QDate(2016, rand() % 12 + 1, rand() % 30 + 1));
    date_time.setTime(QTime(rand() % 24 + 1, rand() % 12 + 1, rand() % 59 + 1));
    return date_time;
}

QVariant BaseModel::headerData(int section, Qt::Orientation orientation, int role) const
{
    if (role != Qt::DisplayRole) {
        return QVariant();
    }
    if (orientation == Qt::Horizontal) {
        switch (section) {
        case Username: return tr("Użytkownik");
        case DateCreated: return tr("Data utworzenia");
        case StatementName: return tr("Nazwa komunikatu");
        case Description: return tr("Opis");
        }
    }
    return QVariant();
}

