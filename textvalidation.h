#ifndef TEXTVALIDATION_H
#define TEXTVALIDATION_H

#include <QObject>

class TextValidation
{
public:
    TextValidation();
    bool IsDate(QString text);
    bool IsFIO(QString text);
    bool IsNumber(QString text);
    bool IsPhone(QString text);

private:

    QRegExp DATE = ("[0-9]{4}-(0[1-9]|1[012])-(0[1-9]|1[0-9]|2[0-9]|3[01])");
    QRegExp FIO = ("[А-ЯЁа-яё]+\\s[А-ЯЁ]\\.[А-ЯЁ]\\.");
    QRegExp PHONE = ("[0-9]{3}-[0-9]{2}-[0-9]{2}");

};

#endif // TEXTVALIDATION_H
