#ifndef STATEMENTELEMENT_H
#define STATEMENTELEMENT_H

#include "baseelement.h"
#include <QStringList>
class StatementElement : public BaseElement
{
public:
    StatementElement();
    QStringList line();
    void set_line(const QStringList &line);
private:
    QStringList m_line;
};

#endif // STATEMENTELEMENT_H
