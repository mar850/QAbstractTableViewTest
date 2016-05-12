#include "baseelement.h"

BaseElement::BaseElement()
{

}

void BaseElement::set_usrname(const QString &username)
{
    m_username = username;
}

void BaseElement::set_date_created(const QDateTime &date_time)
{
    m_date_created = date_time;
}

void BaseElement::set_statement_name(const QString &statement_name)
{
    m_statement_name = statement_name;
}

void BaseElement::set_is_hot_news(bool status)
{
    m_is_hot_news = status;
}

QString BaseElement::username()
{
    return m_username;
}

QDateTime BaseElement::date_created()
{
    return m_date_created;
}

QString BaseElement::statement_name()
{
    return m_statement_name;
}

bool BaseElement::is_hot_news()
{
    return m_is_hot_news;
}

