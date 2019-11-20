import QtQuick 2.12
import QtQuick.Window 2.12

Window {
    visible: true
    width: 640
    height: 480
    title: qsTr("Signal and Slots")

    Rectangle{
        id : rectangleId
        width : 200
        height: 300
        color: "red"

        signal greet(string message) //declare signal

        onGreet: {
            console.log("Greet emited")
        }

        function myGreeting(mMessage){
            console.log("Slot received: " + mMessage)
        }

        MouseArea{
            anchors.fill: parent
            onClicked: {
                rectangleId.greet("Hello there") //fire the signal
            }
        }

        Component.onCompleted: {
            rectangleId.greet.connect(rectangleId.myGreeting)
        }
    }
}
