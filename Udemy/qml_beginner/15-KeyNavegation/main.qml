import QtQuick 2.12
import QtQuick.Window 2.12

Window {
    visible: true
    width: 640
    height: 480
    title: qsTr("Hello World")

    Row{
        anchors.centerIn: parent
        Rectangle{
            id: firstRectId
            width: 200
            height: width
            border.color: "black"
            color: "green"
            focus: true

            onFocusChanged: {
                if(focus === true){
                    color = "red"
                }else{
                    color = "green"
                }
            }

            Keys.onDigit5Pressed: {
                console.log("I am Rect1")
            }

            KeyNavigation.right: secondtRectId
        }

        Rectangle{
            id: secondtRectId
            width: 200
            height: width
            border.color: "black"
            color: "blue"

            onFocusChanged: {
                if(focus === true){
                    color = "red"
                }else{
                   color = "blue"
                }
            }

            Keys.onDigit5Pressed: {
                console.log("I am Rect2")
            }
            KeyNavigation.left : firstRectId
        }
    }
}
