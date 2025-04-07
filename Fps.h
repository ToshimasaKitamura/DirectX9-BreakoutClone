#pragma once

#include <list>

class Fps final
{
public:
    explicit Fps();
    ~Fps();
    void Wait();
private:
    void UpdateAverage();
    void Regist();
    unsigned GetWaitTime() const;
    std::list<int> _list;
    float _fps;
    unsigned _counter;
};

