import QtQuick 2.9
import QtQuick.Window 2.2
import QtQuick.Dialogs 1.2
import QtQuick.Controls 2.5

Window {
    visible: true
    width: 640
    height: 480
    title: qsTr("Hello World")

    Column{
        spacing: 20
        anchors.centerIn: parent

        Button{
            text: "Choose Color"
            anchors.horizontalCenter: parent.horizontalCenter
            onClicked: {
                colorDialogId.open()
            }
        }

        Rectangle{
            width: 200
            height: 200
            id : rectangleId
            border.color: "black"
            border.width: 8
            anchors.horizontalCenter: parent.horizontalCenter
        }

        ColorDialog{
            id: colorDialogId
            title: "Please choose a color"

            onAccepted: {
                console.log("User choose a color: " + color)
                rectangleId.color = color
            }

            onCurrentColorChanged: {
                console.log("Current color changed")
            }

            onRejected: {
                console.log("Rejected")
            }
        }
    }
}
