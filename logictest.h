#ifndef LOGICTEST_H
#define LOGICTEST_H

#include <QObject>
#include <QFile>
#include <QHash>
#include <QStringList>
#include <QTimer>
#include <QTime>
#include <QDebug>

class LogicTest : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString question READ question WRITE setQuestion NOTIFY questionChanged)
    Q_PROPERTY(QStringList answers READ answers WRITE setAnswers NOTIFY answersChanged)
    Q_PROPERTY(int state READ state WRITE setstate NOTIFY stateChanged)

    QString m_question;
    QStringList m_answers;
    QTimer timer;

    QStringList formAnswerVariants(const QString &rightVar, int varCount=5);
    int shakeAnswers(QStringList &ans);

    int m_state=0;

public:
    explicit LogicTest(QObject *parent = nullptr);

    QString question() const;
    QStringList answers() const;
    int state() const;

signals:

    void newItem();
    void chooseItem();
    void questionChanged(QString arg);
    void answersChanged(QStringList arg);
    void stateChanged(int arg);

public slots:

    void setQuestion(QString arg);
    void setAnswers(QStringList arg);
    void onTimeout();
    void choose(int index);
    void setstate(int arg);
};

#endif // LOGICTEST_H
