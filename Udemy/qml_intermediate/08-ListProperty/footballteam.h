#ifndef FOOTBALLTEAM_H
#define FOOTBALLTEAM_H

#include <QObject>

class FootballTeam : public QObject
{
    Q_OBJECT
public:
    explicit FootballTeam(QObject *parent = nullptr);

signals:

public slots:
};

#endif // FOOTBALLTEAM_H