#include "scpkeywords.h"

ScpKeywords::ScpKeywords()
{

}
const char * ScpKeywords::keywords(int set) const
{

    if(set == 2)
    {
        return "define function";
    }

    return QsciLexerCPP::keywords(set);
}
