import QtQuick 2.12
import QtQuick.Window 2.12

Window {
    visible: true
    width: 640
    height: 480
    title: qsTr("Properties and Handlers")

    property string mFirstName: "Cristiano"

    onMFirstNameChanged: {
        console.log("The firstname changed to : " + mFirstName)
    }

    Rectangle{
        width: 300
        height: 100
        color: "greenyellow"
        anchors.centerIn: parent

        MouseArea{
            anchors.fill: parent
            onClicked: {
                mFirstName = "Marcelo"
            }
        }

    }

    Component.onCompleted: {
        console.log("The firstname is " + mFirstName)
    }
}
