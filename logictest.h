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

    QString toString() const {
        return QString::number(this->point);
    }
};

class TestInfo {
    QString filename;
    QString desc;
    QVector<TestResult> results;
    bool completed;
    int acc;
public:
    TestInfo() = default;
    TestInfo(const QString &str, const QString &d) : filename(str), desc(d), completed(false), acc(0) { }

    const QString &file() const {
        return filename;
    }

    const QString &description() const {
        return this->desc;
    }

    void addAnswer(int point) {
        TestResult res(point);
        this->results.append(res);
        this->acc += point;
    }
    int summary() const {
        return this->acc;
    }
    void complete() { this->completed = true; }
    bool isCompleted() { return this->completed; }

    QString getStringResults() const {
        QString result;
        for (auto &&res: this->results) {
            result += res.toString() + " ";
        }
        return result;
    }

};

class LogicTest : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString test READ test WRITE setTest NOTIFY testChanged)
    Q_PROPERTY(QString question READ question WRITE setQuestion NOTIFY questionChanged)
    Q_PROPERTY(QStringList answers READ answers WRITE setAnswers NOTIFY answersChanged)
    Q_PROPERTY(QVector<int> completed READ completed NOTIFY completedChanged)
    Q_PROPERTY(QString description READ description NOTIFY descriptionChanged)

    QString m_test;
    QString m_question;
    QStringList m_answers;
    QVector<int> points;
    QMap<QString, TestInfo> test_files;
    TestInfo *currentTest;
    QTimer timer;
    QFile testFile;
    QXmlStreamReader testReader;
    QStringList order {"social", "prof", "logic"};
    QString m_user;

    void nextQuestion();
    void openTestFile(const QString &test);
    void saveAnswersToFile();

public:
    explicit LogicTest(QObject *parent = nullptr);

    QString test() const;
    QString question() const;
    QStringList answers() const;
    QVector<int> completed() const;
    QString description() const;

signals:

    void newItem();
    void chooseItem();
    void testChanged(QString arg);
    void questionChanged(QString arg);
    void answersChanged(QStringList arg);

    void startTest();
    void finishTest();
    void doEnterTest();
    void completedChanged(QVector<int> arg);
    void descriptionChanged(QString description);

public slots:

    void setUser(QString user);
    void setTest(QString arg);
    void setQuestion(QString arg);
    void setAnswers(QStringList arg);
    void onTimeout();
    void choose(int index);
    void skipTest();
    void enterTest();
};

#endif // LOGICTEST_H
