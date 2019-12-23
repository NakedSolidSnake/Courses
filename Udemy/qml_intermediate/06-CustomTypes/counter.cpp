#include "counter.h"

Counter::Counter(QObject *parent) : QObject(parent),
    mTimer(new QTimer(this)),
    m_count(0),
    m_up(true)
{
    mTimer->setInterval(500);

    connect(mTimer, &QTimer::timeout, [=](){
        if(m_up) {
            ++m_count;
        }else{
            --m_count;
        }

        emit countChanged(m_count);
    });
}

int Counter::count() const
{
    return m_count;
}

bool Counter::up() const
{
    return m_up;
}

void Counter::setCount(int count)
{
    if (m_count == count)
        return;

    m_count = count;
    emit countChanged(m_count);
}

void Counter::setUp(bool up)
{
    if (m_up == up)
        return;

    m_up = up;
    emit upChanged(m_up);
}

void Counter::start()
{
    mTimer->start();
}

void Counter::stop()
{
    mTimer->stop();
}
