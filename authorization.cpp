#include "authorization.h"

Authorization::Authorization(QObject *parent) : QObject(parent)
{

}

QString Authorization::name() const
{
    return m_name;
}

void Authorization::setName(QString arg)
{
    if (m_name != arg) {
        m_name = arg;
        emit nameChanged(arg);
    }
}
