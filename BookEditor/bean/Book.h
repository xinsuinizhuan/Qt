#ifndef BOOKINFO_H
#define BOOKINFO_H

#include <QString>

/**
 * ROLE_XXX 和 TYPE_XXX 的使用，都是为了存储自定义数据到 QStandardItem 中，不同类型节点存储的数据可能不一样:
 * 1. 存储 item 的类型: item->setData(TYPE_KP,  ROLE_TYPE);
 * 2. 存储 item 的数据: item->setData(kpCode,   ROLE_CODE);
 *                    item->setData(coverUrl, ROLE_COVER);
 */
extern const int ROLE_TYPE;     // 表示类型的 role
extern const int ROLE_CODE;     // 表示编码的 role
extern const int ROLE_COVER;    // 表示封面的 role (存储封面的 URL)
extern const int ROLE_CODE_EXT; // 表示扩展编码的 role

extern const QString TYPE_PHASE;   // 学段
extern const QString TYPE_SUBJECT; // 学科
extern const QString TYPE_VERSION; // 版本
extern const QString TYPE_BOOK;    // 教材
extern const QString TYPE_KP;      // 知识点
extern const QString TYPE_KP_CODE; // 知识点编码
extern const QString TYPE_CHAPTER; // 章节
extern const QString TYPE_CHAPTER_CODE; // 章节编码

// 存储 code 和 info 对
class CodeInfo {
public:
    CodeInfo(const QString &code, const QString &info);

    QString code;
    QString info; // 学段 > 学科 > 版本 > 教材
};
#endif // BOOKINFO_H
