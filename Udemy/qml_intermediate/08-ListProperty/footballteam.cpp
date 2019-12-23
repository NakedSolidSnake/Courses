#include "footballteam.h"

FootballTeam::FootballTeam(QObject *parent) : QObject(parent)
{

}

QString FootballTeam::title() const
{
    return m_title;
}

QString FootballTeam::coach() const
{
    return m_coach;
}

Player *FootballTeam::captain() const
{
    return m_captain;
}

void FootballTeam::setTitle(QString title)
{
    if (m_title == title)
        return;

    m_title = title;
    emit titleChanged(m_title);
}

void FootballTeam::setCoach(QString coach)
{
    if (m_coach == coach)
        return;

    m_coach = coach;
    emit coachChanged(m_coach);
}

void FootballTeam::setCaptain(Player *captain)
{
    if (m_captain == captain)
        return;

    m_captain = captain;
    emit captainChanged(m_captain);
}

QQmlListProperty<Player> FootballTeam::players() const
{
    return QQmlListProperty<Player>(this, this,
                                    &FootballTeam::appendPlayer,
                                    &FootballTeam::playerCount,
                                    &FootballTeam::player,
                                    &FootballTeam::clearPlayers);
}

void FootballTeam::setPlayers(QQmlListProperty<Player> players)
{
    if (m_players == players)
        return;

    m_players = players;
    emit playersChanged(m_players);
}

void FootballTeam::appendPlayerCustom(Player *player)
{
    m_players.append(player);
}

int FootballTeam::playerCountCustom() const
{
    return m_players.count();
}

Player *FootballTeam::playerCustom(int index) const
{
    return m_players.at(index);
}

void FootballTeam::clearPlayersCustom()
{
    m_players.clear();
}

void FootballTeam::appendPlayer(QQmlListProperty<Player> *list, Player *player)
{
    reinterpret_cast<FootballTeam *>(list->data)->appendPlayerCustom(player);
}

int FootballTeam::playerCount(QQmlListProperty<Player> *list)
{
    return  reinterpret_cast<FootballTeam *>(list->data)->playerCountCustom();
}

Player *FootballTeam::player(QQmlListProperty<Player> *list, int index)
{
    return reinterpret_cast<FootballTeam *>(list->data)->playerCustom(index);
}

void FootballTeam::clearPlayers(QQmlListProperty<Player> *list)
{
    return reinterpret_cast<FootballTeam *>(list->data)->clearPlayersCustom();
}
