import QtQuick 2.9
import QtQuick.Window 2.2
import QtQuick.Controls 2.5

Window {
    visible: true
    width: 640
    height: 480
    title: qsTr("Hello World")

    Column{
        width: parent.width
        spacing: 20

        Button{
            text: "Start"
            anchors.horizontalCenter: parent.horizontalCenter
            onClicked: {
                progressBarId.value = 78
            }
        }

        Dial{
            from: 1
            to: 100
            anchors.horizontalCenter: parent.horizontalCenter
            onValueChanged: {
                progressBarId.value = value
            }
        }

        ProgressBar{
            id: progressBarId
            from: 1
            to: 100
            value: 40
            anchors.horizontalCenter: parent.horizontalCenter
        }

        ProgressBar{
            id: progressBarId1
            indeterminate: true
            anchors.horizontalCenter: parent.horizontalCenter
        }
    }
}
