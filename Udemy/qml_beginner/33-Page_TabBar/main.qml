import QtQuick 2.9
import QtQuick.Window 2.2
import QtQuick.Controls 2.5

Window {
    visible: true
    width: 640
    height: 480
    title: qsTr("Hello World")

    Page{
        id: pageId
        anchors.fill: parent

        SwipeView{
            id: swipeViewId
            anchors.fill: parent
        }

        //footer: TabBar{
        header: TabBar{
            id: tabBarId
            currentIndex: swipeViewId.currentIndex

            TabButton{
                text: "First"
            }

            TabButton{
                text: "Second"
            }

            TabButton{
                text: "Third"
            }
        }
    }
}
