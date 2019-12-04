import QtQuick 2.9
import QtQuick.Window 2.2
import QtQuick.Controls 2.5
import Qt.labs.platform 1.1
import QtQuick.Dialogs 1.2

Window {
    visible: true
    width: 640
    height: 480
    title: qsTr("Hello World")

    Column{
        spacing: 20
        anchors.centerIn: parent

        Button{
            text: "Choose File or Folder"
            anchors.horizontalCenter: parent.horizontalCenter
            onClicked: {
                fileDialogId.open()
            }
        }

        Text{
            id: textId
            text: "User hasn't choosen yet"
            wrapMode: Text.Wrap
        }

        FileDialog{
            id: fileDialogId
            title: "Choose File or Folder"
            selectFolder: false
            selectMultiple: true

            onAccepted: {
//                textId.text = fileUrls

                for( var i = 0; i < fileUrls.length; i++){
                    console.log("Value " + i + " is : " + fileUrls[i])
                }
            }

            onRejected: {

            }
        }
    }
}
