import QtQuick 2.9
import QtQuick.Window 2.2
import QtQuick.Controls 2.5

Window {
    visible: true
    width: 640
    height: 480
    title: qsTr("Hello World")

    SwipeView{
        id: swipeViewId
        anchors.fill: parent
        currentIndex: pageIndicatorId.currentIndex

        Image {
            id: image1
            source: "qrc:/images/ruim.png"
        }

        Image {
            id: image2
            source: "qrc:/images/ruim.png"
        }

        Image {
            id: image3
            source: "qrc:/images/ruim.png"
        }
    }

    PageIndicator{
        id: pageIndicatorId
        anchors.bottom: parent.bottom

        currentIndex: swipeViewId.currentIndex
        interactive: true

        count : swipeViewId.count
    }
}
