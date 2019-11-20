import QtQuick 2.12
import QtQuick.Window 2.12

Window {
    visible: true
    width: 640
    height: 480
    title: qsTr("Hello World")

    Column{
        MButton{
            id: button1Id
            color: "green"
            focus: true

            onFocusChanged: {
                if(focus === true){
                    color = "red"
                }else{
                   color = "green"
                }
            }

            KeyNavigation.down: button2Id
        }

        MButton{
            id: button2Id
            color: "blue"

            onFocusChanged: {
                if(focus === true){
                    color = "red"
                }else{
                   color = "blue"
                }
            }

            KeyNavigation.up: button1Id
        }
    }
}
