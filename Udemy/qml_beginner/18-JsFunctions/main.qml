import QtQuick 2.12
import QtQuick.Window 2.12

Window {
    visible: true
    width: 640
    height: 480
    title: qsTr("Hello World")

    function min(a, b){
        return Math.min(a, b)
    }

    Rectangle{
        id: mRectId
        width: min(500, 400)
        height: 100
        anchors.centerIn: parent
        color: "blue"
    }

    MouseArea{
        id: mMouseId
        anchors.fill: parent

        function sayMessage(){
            console.log("Hello there")
        }

        onClicked: {
            sayMessage()
        }
    }

    Component.onCompleted: {
        console.log("The width of rect is :" + min(500, 400))
        mMouseId.sayMessage()
    }
}
