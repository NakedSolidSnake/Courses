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
        spacing: 40
        Label{
            width: parent.width
            wrapMode: Label.Wrap
            horizontalAlignment: Qt.AlignHCenter
            text: "Delayed Button. Use it when you want to prevent accidental cklicks"
            font.pointSize: 15
        }

        DelayButton{
            property bool activated: false
            text: "DelayButton"
            anchors.horizontalCenter: parent.horizontalCenter
            delay: 1000

            onPressed: {
                if(activated === true)
                {
                    console.log("Button is Clicked")
                    activated = false;
                }
            }

            onActivated: {
                console.log("Button Activated")
                activated = true
            }

            onProgressChanged: {
                console.log(progress)
            }
        }
    }
}
