#ifndef FOOTBALLTEAM_H
#define FOOTBALLTEAM_H

#include <QObject>
#include <QQmlListProperty>
#include <QVector>
#include <player.h>

class FootballTeam : public QObject
{
    Q_OBJECT

    Q_PROPERTY(QString title READ title WRITE setTitle NOTIFY titleChanged)
    Q_PROPERTY(QString coach READ coach WRITE setCoach NOTIFY coachChanged)
    Q_PROPERTY(Player * captain READ captain WRITE setCaptain NOTIFY captainChanged)
    Q_PROPERTY(QQmlListProperty<Player> players READ players WRITE setPlayers NOTIFY playersChanged)



public:
    explicit FootballTeam(QObject *parent = nullptr);

    QString title() const;
    QString coach() const;
    Player * captain() const;

    void setTitle(QString title);
    void setCoach(QString coach);
    void setCaptain(Player * captain);
    QQmlListProperty<Player> players() const;
    void setPlayers(QQmlListProperty<Player> players);

    void appendPlayerCustom(Player *);
    int playerCountCustom()const;
    Player *playerCustom(int) const;
    void clearPlayersCustom();

signals:
    void titleChanged(QString title);
    void coachChanged(QString coach);
    void captainChanged(Player * captain);
    void playersChanged(QQmlListProperty<Player> players);



public slots:

private:
    QString m_title;
    QString m_coach;
    Player * m_captain;
    QVector<Player*> m_players;

    static void appendPlayer(QQmlListProperty<Player> *, Player *);
    static int playerCount(QQmlListProperty<Player> *);
    static Player* player(QQmlListProperty<Player> *, int);
    static void clearPlayers(QQmlListProperty<Player> *);

};



#endif // FOOTBALLTEAM_H
