#include "statementelement.h"

StatementElement::StatementElement()
{

}

QStringList StatementElement::line()
{
    return m_line;
}

void StatementElement::set_line(const QStringList &line)
{
    m_line = line;
}

