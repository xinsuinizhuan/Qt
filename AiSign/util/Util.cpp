#include "Util.h"

#include <QDebug>
#include <QFile>
#include <QTextStream>
#include <QTextCodec>
#include <QString>
#include <QDate>
#include <QCryptographicHash>

#include "bean/Person.h"

/**
 * 保存字符串 content 到 path 对应的文件，编码使用 UTF-8
 *
 * @param content 要保存的字符串
 * @param path    要保存的文件路径
 * @param error   错误信息
 * @return 保存成功返回 true，保存失败返回 false
 */
bool Util::writeStringToFile(const QString &content, const QString &path, QString *error) {
    QFile file(path);

    if (!file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        QString errorString = QString("保存文件 %1 出错：%2").arg(path).arg(file.errorString());
        qDebug().noquote() << errorString;

        if (0 != error) {
            *error = errorString;
        }

        return false;
    }

    QTextStream ts(&file);
    ts.setCodec(QTextCodec::codecForName("UTF8"));
    ts << content;
    file.flush();
    file.close();

    return true;
}

QString Util::formatDate(const QString &date) {
    return QDate::fromString(date, "yyyyMMdd").toString("yyyy 年 MM 月 dd 日");
}

void Util::registerTypes() {
    qRegisterMetaType<Person>("Person");
    qRegisterMetaType<Person>("Person&");
}

QByteArray Util::md5(const QByteArray &data) {
    return QCryptographicHash::hash(data, QCryptographicHash::Md5).toHex();
}
