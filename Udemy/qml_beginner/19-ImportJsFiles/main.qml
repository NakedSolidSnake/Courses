import QtQuick 2.12
import QtQuick.Window 2.12
import "utilities.js" as Utilities


Window {
    visible: true
    width: 640
    height: 480
    title: qsTr("Hello World")

    Rectangle{
        width: 300
        height: 100
        color: "yellowgreen"
        anchors.centerIn: parent

        Text{
            text: "Click me"
            anchors.centerIn: parent
        }

        MouseArea{
            anchors.fill: parent
            onClicked: {
//                console.log("Hello There")
                Utilities.greeting()
                console.log("ages: " + Utilities.combineAges(31, 33))
                console.log("sub: " + Utilities.subtract(31, 33))
            }
        }
    }
}
