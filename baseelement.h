#ifndef BASEELEMENT_H
#define BASEELEMENT_H
#include <QString>
#include <QDateTime>

class BaseElement
{
public:
    enum NameElement {
        HistoryElement,
        StatementElement
    };

    BaseElement();
    void set_usrname(const QString &username);
    void set_date_created(const QDateTime &date_time);
    void set_statement_name(const QString &statement_name);
    void set_is_hot_news(bool status);

    QString username();
    QDateTime date_created();
    QString statement_name();
    bool is_hot_news();

private:
    QString m_username;
    QDateTime m_date_created;
    QString m_statement_name;
    bool m_is_hot_news;
};

#endif // BASEELEMENT_H
