import QtQuick 2.12
import QtQuick.Window 2.12

Window {
    visible: true
    width: 640
    height: 480
    title: qsTr("Hello World")

    Rectangle{
        id: containerRectId
        width: 300
        height: 100
        border.color: "black"
        anchors.fill: parent

        Rectangle{
            id: topLeftRectId
            width: 100
            height: width
            color: "magenta"
        }

        Rectangle{
            id: bottomLeftRectId
            width: 100
            height: width
            color: "steelblue"

            anchors.left: topLeftRectId.right
        }

        Rectangle{
            id: rect3Id
            width: 100
            height: width
            color: "blue"

            anchors.left: bottomLeftRectId.right
            anchors.top: bottomLeftRectId.bottom
        }
    }
}
