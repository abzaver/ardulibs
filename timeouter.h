#ifndef timeouter_h
#define timeouter_h


class timeouter
{
public:
    timeouter(void);
    void setDelay(unsigned long v);
    unsigned long getDelay();
    void start(void);
    bool isOver(void);
    int  getSecondsUntilOver(void);
private:
    unsigned long delay;
    unsigned long last_set;
};

#endif