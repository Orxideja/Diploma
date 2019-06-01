#include "logictest.h"
#include <QXmlStreamAttribute>

QStringList LogicTest::formAnswerVariants(const QString& rightVar, int varCount)
{
    Q_UNUSED(varCount);
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

void LogicTest::nextQuestion()
{
    this->testReader.readNext();
    if (testReader.atEnd()) {
        qWarning()<<"end file";
        return;
    }

    while( !testReader.isStartElement() && testReader.name() != "Question" ) {
        this->testReader.readNext();
        if (testReader.atEnd() ) {
            qWarning()<<"end file";
            return;
        }
    }

    QStringList newAns;
    this->points.clear();

    while ( ! (testReader.isEndElement() && testReader.name() == "Question") ) {
        this->testReader.readNext();
        if ( testReader.name() == "Text" ) {
            setQuestion(testReader.readElementText());
        } else if ( testReader.name() == "ans" ) {
            foreach(const QXmlStreamAttribute &attr, testReader.attributes()) {
                if (attr.name().toString() == "point") {
                    this->points.append(attr.value().toInt());
                }
            }
            newAns.append(testReader.readElementText());
        }
    }
    setAnswers(newAns);
}

void LogicTest::openTestFile(const QString &test)
{
    auto filename = test_files[test];
    qDebug()<<"open "<<filename;
    this->testFile.setFileName(filename);
    if (!this->testFile.open(QFile::ReadOnly | QFile::Text))
    {
            qWarning()<<"Can't open file "<<filename;
    } else {
        this->testReader.setDevice(&this->testFile);
    }
}

LogicTest::LogicTest(QObject *parent) :
    QObject(parent)
{
    qDebug()<<Q_FUNC_INFO;
    qsrand(QTime::currentTime().msec());
    timer.setInterval(1*01*1000);
    test_files["social"] = "socialTest.xml";
    test_files["logic"] = "dopTest.xml";
    test_files["prof"] = "profTest.xml";

    connect(&timer, SIGNAL(timeout()), SLOT(onTimeout()));
//    timer.start();
    m_question = QString::fromUtf8("Первый вопрос?");
    m_answers.append(QString::fromUtf8("Да"));
    m_answers.append(QString::fromUtf8("Нет"));
}

QString LogicTest::test() const
{
    return m_test;
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

void LogicTest::setTest(QString arg)
{
    if (m_test != arg) {
        m_test = arg;
        this->openTestFile(m_test);
        this->nextQuestion();
        emit testChanged(arg);
    }
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
        if ( m_answers.size() != points.size() )
            qWarning()<<"points size mismatch"<<this->points;
        else {
            qWarning()<<" -- point = "<<points[index];
        }
        this->nextQuestion();
    }
}

void LogicTest::setstate(int arg)
{
    if (m_state != arg) {
        m_state = arg;
        emit stateChanged(arg);
    }
}
