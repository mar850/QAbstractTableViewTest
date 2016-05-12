#ifndef HISTORYELEMENT_H
#define HISTORYELEMENT_H

#include <baseelement.h>

class HistoryElement : public BaseElement
{
public:
    HistoryElement();
    void set_descritpion(const QString &description);
    QString description();

private:
    QString m_description;
};

#endif // HISTORYELEMENT_H
