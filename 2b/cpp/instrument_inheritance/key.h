#include <iostream>
using namespace std;
#include "instrument.h"

class Key : public Instrument{
    public:
        Key(string name, string soundDes);
        ~Key();
};