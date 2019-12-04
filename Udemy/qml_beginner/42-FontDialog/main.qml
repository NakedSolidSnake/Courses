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
            text: "Change Font"
            anchors.horizontalCenter: parent.horizontalCenter
            onClicked: {
                fontDialogId.open()
            }
        }

        Text{
            id: textId
            text: "Hello World"
        }

        FontDialog{
            id: fontDialogId
            title: "Choose Font"
            font : Qt.font({family: "Arial", pointSize:24, weight: Font.Normal})

            onAccepted: {
                console.log("Choose font : " + font)
                textId.font = fontDialogId.font
            }

            onRejected: {
                console.log("Dialog Rejected")
            }

        }

    }
}
