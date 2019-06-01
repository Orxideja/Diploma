#ifndef LOGICTEST_H
#define LOGICTEST_H

#include <QObject>
#include <QFile>
#include <QHash>
#include <QStringList>
#include <QMap>
#include <QTimer>
#include <QTime>
#include <QDebug>
#include <QXmlStreamReader>

class TestResult {
    int point;
public:
    TestResult():
        point(0) {}

    TestResult(int p) :
        point(p) {}

    TestResult &operator = (int point) {
        this->point = point;
        return *this;
    }
};

class TestInfo {
    QString filename;
    QVector<TestResult> results;
    bool completed;
    int acc;
public:
    TestInfo() = default;
    TestInfo(const QString &str) : filename(str), completed(false), acc(0) { }
    const QString &file() const {
        return filename;
    }
    void addAnswer(int point) {
        TestResult res(point);
        this->results.append(res);
        this->acc += point;
    }
    void complete() { this->completed = true; }
    bool isCompleted() { return this->completed; }
};

class LogicTest : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString test READ test WRITE setTest NOTIFY testChanged)
    Q_PROPERTY(QString question READ question WRITE setQuestion NOTIFY questionChanged)
    Q_PROPERTY(QStringList answers READ answers WRITE setAnswers NOTIFY answersChanged)
    Q_PROPERTY(int state READ state WRITE setstate NOTIFY stateChanged)
    Q_PROPERTY(QVector<int> completed READ completed NOTIFY completedChanged)

    QString m_test;
    QString m_question;
    QStringList m_answers;
    QVector<int> points;
    QMap<QString, TestInfo> test_files;
    TestInfo *currentTest;
    QTimer timer;
    QFile testFile;
    QXmlStreamReader testReader;

    QStringList formAnswerVariants(const QString &rightVar, int varCount=5);
    int shakeAnswers(QStringList &ans);

    int m_state=0;
    void nextQuestion();
    void openTestFile(const QString &test);

public:
    explicit LogicTest(QObject *parent = nullptr);

    QString test() const;
    QString question() const;
    QStringList answers() const;
    int state() const;
    QVector<int> completed() const;


signals:

    void newItem();
    void chooseItem();
    void testChanged(QString arg);
    void questionChanged(QString arg);
    void answersChanged(QStringList arg);
    void stateChanged(int arg);
    void finishTest();
    void completedChanged(QVector<int> arg);

public slots:

    void setTest(QString arg);
    void setQuestion(QString arg);
    void setAnswers(QStringList arg);
    void onTimeout();
    void choose(int index);
    void setstate(int arg);
};

#endif // LOGICTEST_H
