import QtQuick 2.12
import QtQuick.Window 2.12

Window {
    visible: true
    width: 640
    height: 480
    title: qsTr("Key Attached Property")

    Rectangle{
        id: containedRect
        anchors.centerIn: parent
        width: 300
        height: 50
        color: "dodgerblue"
        focus: true

        Keys.onDigit1Pressed: {
            console.log("Pressed on Key 1")
        }

        Keys.onPressed: {
//            console.log("Key: " + event.key)

//            if(event.key === Qt.Key_0){
//                console.log("Key 0 Pressed")
//            }

            if((event.key === Qt.Key_5) && (event.modifiers & Qt.ControlModifier)){
                console.log("[SHIFT] + 5")
            }

            if((event.key === Qt.Key_5) &&
                    (event.modifiers & Qt.ControlModifier)){
                console.log("[SHIFT] + 5")
            }
        }
    }
}
