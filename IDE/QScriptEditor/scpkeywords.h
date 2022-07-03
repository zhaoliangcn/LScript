#ifndef SCPKEYWORDS_H
#define SCPKEYWORDS_H

#include <Qsci/qscilexercpp.h>

class ScpKeywords :public QsciLexerCPP
{
public:
    ScpKeywords();
public:
    const char *keywords(int set) const;
};

#endif // SCPKEYWORDS_H
