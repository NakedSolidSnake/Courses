import QtQuick 2.9
import QtQuick.Window 2.2
import QtQuick.Controls 2.5

Window {
    visible: true
    width: 640
    height: 480
    title: qsTr("Hello World")

    Column{
        width: parent
        spacing: 40

        Label{
            width: parent.width
            wrapMode: Label.Wrap
            horizontalAlignment: Qt.AlignHCenter
            text: "A know used to let the user choose a value from a range"
            font.pointSize: 15
        }

        Dial{
            anchors.horizontalCenter: parent.horizontalCenter
            from: 1
            to: 100
            value: 50

            onValueChanged: {
                console.log("Current value: " + Math.ceiling(value))
            }
        }
    }
}
