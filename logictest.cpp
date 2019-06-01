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
        qWarning()<<"first end file";
        emit finishTest();
        return;
    }

    while( !testReader.isStartElement() && testReader.name() != "Question" ) {
        this->testReader.readNext();
        if (testReader.atEnd() ) {
            qWarning()<<"end file";
            this->currentTest->complete();
            emit finishTest();
            emit completedChanged(completed());
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
    this->currentTest = &test_files[test];
    qDebug()<<"open "<<this->currentTest->file();
    this->testFile.setFileName(currentTest->file());
    if (!this->testFile.open(QFile::ReadOnly | QFile::Text))
    {
            qWarning()<<"Can't open file "<<currentTest->file();
    } else {
        this->testReader.setDevice(&this->testFile);
    }
}

LogicTest::LogicTest(QObject *parent) :
    QObject(parent)
{
    test_files["social"] = TestInfo("socialTest.xml");
    test_files["logic"] = TestInfo("logic.xml");
    test_files["prof"] = TestInfo("profTest.xml");
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

QVector<int> LogicTest::completed() const
{
    QStringList order {"social", "prof", "logic"};
    QVector<int> comp;
    int i = 0;
    for(auto &name: order) {
        TestInfo test = this->test_files[name];
        if (test.isCompleted()) comp.append(i);
        i++;
    }
    return comp;
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
        qDebug()<<"Choose "<<index;
        if ( m_answers.size() != points.size() )
            qWarning()<<"points size mismatch"<<this->points;
        else {
            qWarning()<<" -- point = "<<points[index];
            this->currentTest->addAnswer(points[index]);
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

