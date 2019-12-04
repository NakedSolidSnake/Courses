import QtQuick 2.9
import QtQuick.Window 2.2
import QtQuick.Controls 2.5

Window {
    visible: true
    width: 640
    height: 480
    title: qsTr("Hello World")

    Flickable{
        width: parent.width
        height: parent.height
        contentHeight: mColumnId.implicitHeight

        Column{
            id : mColumnId
            anchors.fill: parent

            Rectangle{
                color: "red"
                width: parent.width
                height: 200
                Text{
                    anchors.centerIn: parent
                    text: "Element 1"
                    font.pointSize: 30
                    color: "white"
                }
            }

            Rectangle{
                color: "blue"
                width: parent.width
                height: 200
                Text{
                    anchors.centerIn: parent
                    text: "Element 1"
                    font.pointSize: 30
                    color: "white"
                }
            }

            Rectangle{
                color: "yellow"
                width: parent.width
                height: 200
                Text{
                    anchors.centerIn: parent
                    text: "Element 1"
                    font.pointSize: 30
                    color: "white"
                }
            }

            Rectangle{
                color: "magenta"
                width: parent.width
                height: 200
                Text{
                    anchors.centerIn: parent
                    text: "Element 1"
                    font.pointSize: 30
                    color: "white"
                }
            }

        }

//        ScrollBar.vertical: ScrollBar{}
    }
}
