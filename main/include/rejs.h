#ifndef REJS_H
#define REJS_H
#include <trasa.h>

class rejs : public trasa
{
    public:
        rejs();
        virtual ~rejs();

        void addDays(int d1, int m1, int y1);

    protected:

    private:
        int d;
        int m;
        int y;
        bool isLeap(int y);
        void revoffsetDays(int offset, int y, int *d, int *m);
        int offsetDays(int d, int m, int y);
};

#endif // REJS_H
