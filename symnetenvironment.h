#ifndef SYMNETENVIRONMENT_H
#define SYMNETENVIRONMENT_H


#include "environmentpath.h"

class SymnetEnvironment : public EnvironmentPath
{
    public:
        SymnetEnvironment();
    // TODO : var ?
    // else remove with kleeenvironment
    private:
        void execute();
};

#endif // SYMNETENVIRONMENT_H
