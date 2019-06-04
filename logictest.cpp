#include "logictest.h"
#include <QXmlStreamAttribute>

#include "authorization.h"

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
            this->saveAnswersToFile();
            this->currentTest->complete();
            emit finishTest();
            emit completedChanged(completed());
            this->skipTest();
            if (this->m_test.size())
                emit startTest();
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

void LogicTest::saveAnswersToFile()
{
    QFile file(this->currentTest->file() + ".txt");
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text))
        return;

    QTextStream out(&file);
    out << this->m_user << '\n';
    out << this->currentTest->getStringResults() << '\n';
    out << this->currentTest->summary() << '\n';
    qDebug() << "current result "<< this->currentTest->getStringResults();
    file.close();
}

LogicTest::LogicTest(QObject *parent) :
    QObject(parent)
{
    test_files["social"] = TestInfo("socialTest.xml", QString::fromUtf8("Социальный тест"));
    test_files["logic"] = TestInfo("dopTest.xml", QString::fromUtf8("Тест на дополнительные знания"));
    test_files["prof"] = TestInfo("profTest.xml", QString::fromUtf8("Профессиональный тест"));
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

QVector<int> LogicTest::completed() const
{
    QVector<int> comp;
    int i = 0;
    for(auto &name: this->order) {
        TestInfo test = this->test_files[name];
        if (test.isCompleted()) comp.append(i);
        i++;
    }
    return comp;
}

QString LogicTest::description() const
{
    return this->currentTest->description();
}

void LogicTest::setUser(QString user)
{
    this->m_user = user;
}

void LogicTest::setTest(QString arg)
{
    if (m_test != arg) {
        m_test = arg;
        this->openTestFile(m_test);
        this->nextQuestion();
        emit testChanged(arg);
        emit descriptionChanged(this->currentTest->description());
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

void LogicTest::skipTest() {
    int index = this->order.indexOf(this->m_test);
    if ( index < 0 || index == this->order.size()-1 ) {
        this->m_test.clear();
        emit finishTest();
        return;
    }
    setTest(this->order[index+1]);
}

void LogicTest::enterTest()
{
    emit finishTest();
    emit doEnterTest();
}

