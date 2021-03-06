#include "Book.h"

const int ROLE_TYPE  = Qt::UserRole + 2;    // 表示类型的 role
const int ROLE_CODE  = Qt::UserRole + 3;    // 表示编码的 role
const int ROLE_COVER = Qt::UserRole + 4;    // 表示封面的 role
const int ROLE_CODE_EXT = Qt::UserRole + 5; // 表示扩展编码的 role

const QString TYPE_PHASE   = "phase";   // 学段
const QString TYPE_SUBJECT = "subject"; // 学科
const QString TYPE_VERSION = "version"; // 版本
const QString TYPE_BOOK    = "book";    // 教材
const QString TYPE_KP      = "kp";      // 知识点
const QString TYPE_KP_CODE = "kp_code"; // 知识点编码
const QString TYPE_CHAPTER = "chapter"; // 章节
const QString TYPE_CHAPTER_CODE = "chapter_code"; // 章节编码

CodeInfo::CodeInfo(const QString &code, const QString &info) : code(code), info(info) {

}
