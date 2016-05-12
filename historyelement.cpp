#include "historyelement.h"

HistoryElement::HistoryElement()
{

}

void HistoryElement::set_descritpion(const QString &description)
{
    m_description = description;
}

QString HistoryElement::description()
{
    return m_description;
}

