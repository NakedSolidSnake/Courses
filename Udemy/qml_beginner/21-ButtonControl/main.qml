import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.5
import QtQuick.Layouts 1.3

Window {
    visible: true
    width: 640
    height: 480
    title: qsTr("Hello World")

    RowLayout{
        anchors.left: parent.left
        anchors.right: parent.right

        Button{
            id: button1
            text: "Button 1"
            Layout.fillWidth: true
            onClicked: {
                console.log("Clicked Button 1")
            }

            onDoubleClicked: {
                console.log("Double Clicked Button 1")
            }
        }

        Button{
            id: button2
            text: "Button 2"
            Layout.fillWidth: true

            onClicked: {
                console.log("Clicked Button 2")
            }

            onDoubleClicked: {
                console.log("Double Clicked Button 1")
            }

        }
    }
}
