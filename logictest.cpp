#include "logictest.h"

QStringList LogicTest::formAnswerVariants(const QString& rightVar, int varCount)
{
    QStringList ans(rightVar);
    shakeAnswers(ans);
    qWarning()<<ans;
    return ans;
}

int LogicTest::shakeAnswers(QStringList &ans)
{
    QString rightAns = ans.first();
    ans.removeFirst();
    int shift = qrand()%ans.size();
    ans.insert(shift, rightAns);
    return shift;
}

LogicTest::LogicTest(QObject *parent) :
    QObject(parent)
{
    qDebug()<<Q_FUNC_INFO;
    qsrand(QTime::currentTime().msec());
    timer.setInterval(1*01*1000);
    connect(&timer, SIGNAL(timeout()), SLOT(onTimeout()));
//    timer.start();
    m_question = QString::fromUtf8("Первый вопрос?");
    m_answers.append(QString::fromUtf8("Да"));
    m_answers.append(QString::fromUtf8("Нет"));
}

QString LogicTest::question() const
{
    return m_question;
}

QStringList LogicTest::answers() const
{
    return m_answers;
}

int LogicTest::state() const
{
    return m_state;
}

void LogicTest::setQuestion(QString arg)
{
    if (m_question != arg) {
        m_question = arg;
        emit questionChanged(arg);
    }
}

void LogicTest::setAnswers(QStringList arg)
{
    if (m_answers != arg) {
        m_answers = arg;
        emit answersChanged(arg);
    }
}

void LogicTest::onTimeout()
{
    emit newItem();
    timer.stop();
}

void LogicTest::choose(int index)
{
    if(index>=0&&index<m_answers.size())
    {

//            emit chooseItem();
//            timer.start();
//            setstate(1);
        qDebug()<<"Choose "<<index;
    }
}

void LogicTest::setstate(int arg)
{
    if (m_state != arg) {
        m_state = arg;
        emit stateChanged(arg);
    }
}
