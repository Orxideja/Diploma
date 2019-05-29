#ifndef AUTHORIZATION_H
#define AUTHORIZATION_H

#include <QObject>

class Authorization : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString name READ name WRITE setName NOTIFY nameChanged)

    QString m_name;

public:
    explicit Authorization(QObject *parent = nullptr);
    QString name() const;

signals:
    void nameChanged(QString arg);

public slots:
    void setName(QString arg);
};

#endif // AUTHORIZATION_H
