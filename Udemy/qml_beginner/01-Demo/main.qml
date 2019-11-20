import QtQuick 2.12
import QtQuick.Window 2.12

Window {
    visible: true
    width: 640
    height: 480
    title: qsTr("Hello World")

    Text {
        anchors.centerIn: parent
        text: qsTr("Hello World")
        color: "red"
        font.pointSize: 20
    }

    Component.onCompleted: {
        console.log("Complete")
    }
}
