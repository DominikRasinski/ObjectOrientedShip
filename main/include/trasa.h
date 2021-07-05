#ifndef TRASA_H
#define TRASA_H


class trasa
{
    friend class rejs;
    friend class statek;
    public:
        trasa();
        virtual ~trasa();

        void insertIdOfPorts();

        int setEconimicSpeed(int valueOfEconomicSpeed);
        int getEconomicSpeed();

    protected:

    private:
        int economicSpeed;

        int portStartName;
        int portTargetName;

        int insertPortStartName(int portStartName);
        int insertPortTargetName(int portTargetName);
        int whatACourse(int portStartName, int portTargetName);

        int howLongItTake(int rangeArray);
        void setValueDays(float value);
        float readCurectDays();
        float convertKMtoMM(int rangeArray);
        float curectDays;
};

#endif // TRASA_H
