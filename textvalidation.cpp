#include "textvalidation.h"

TextValidation::TextValidation()
{

}


bool TextValidation::IsDate(QString text)
{
    return DATE.exactMatch(text);
}

bool TextValidation::IsFIO(QString text)
{
    return FIO.exactMatch(text);
}

bool TextValidation::IsNumber(QString text)
{
    bool ok;
    int num = text.toInt(&ok, 10);
    if (ok== true && num>0)
        return true;
    else return false;
}

bool TextValidation::IsPhone(QString text)
{
    return PHONE.exactMatch(text);
}
