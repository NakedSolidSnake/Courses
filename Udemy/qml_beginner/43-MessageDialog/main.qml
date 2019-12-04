import QtQuick 2.9
import QtQuick.Window 2.2
import QtQuick.Controls 2.5
import QtQuick.Dialogs 1.2

Window {
    visible: true
    width: 640
    height: 480
    title: qsTr("Hello World")

    Button{
        text: "Push me"
        onClicked: {
            messageDialog.open()
        }
    }

    MessageDialog{
        id: messageDialog
        title: "May I have your attention please"
        text: "It's so cool that you're using Qt Quick."
        standardButtons: StandardButton.Ok | StandardButton.Close

        onAccepted: {
            console.log("And of course you could only agree.")
        }

        onRejected: {
            console.log("Canceled Dialog")
        }

    }
}
