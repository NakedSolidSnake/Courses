#include <QDebug>
#include "appwrapper.h"
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>


AppWrapper::AppWrapper(QObject *parent) : QObject(parent),
    mNetManager(new QNetworkAccessManager(this)),
    mNetReply(nullptr),
    mDataBuffer(new QByteArray)
{

}

void AppWrapper::fetchPosts(int number)
{
    const QUrl API_ENDPOINT("http://api.icndb.com/jokes/random/" + QString::number(number));

    QNetworkRequest request;
    request.setUrl(API_ENDPOINT);

    mNetReply = mNetManager->get(request);

    connect(mNetReply, &QIODevice::readyRead, this, &AppWrapper::dataReadyRead);
    connect(mNetReply, &QNetworkReply::finished, this, &AppWrapper::dataReadFinished);


}

void AppWrapper::removeLast()
{

}

QStringList AppWrapper::jokes() const
{
    return mJokes;
}

void AppWrapper::dataReadyRead()
{
    mDataBuffer->append(mNetReply->readAll());
}

void AppWrapper::dataReadFinished()
{
    //Parse Json
    if(mNetReply->error()){
        qDebug() << "There was some error: " << mNetReply->errorString();
    }else{
        QJsonDocument doc = QJsonDocument::fromJson(*mDataBuffer);
        QJsonObject data = doc.object();

        QJsonArray array = data["value"].toArray();

        for (int i{0}; i < array.size(); i++) {
            QJsonObject object = array.at(i).toObject();
            QString joke = object["joke"].toString();

            qDebug() << joke;
            mJokes.append(joke);
        }
    }
}
