import QtQuick 2.12
import QtQuick.Window 2.12

Window {
    visible: true
    width: 640
    height: 480
    title: qsTr("Hello World")

    Rectangle{
        id : rectId
        anchors.fill: parent

        Text {
            id: label
            x: 24
            y: 24

            property int spacePresses: 0

            text: "Spaced pressed: " + spacePresses + " times"

            onTextChanged: {
                console.log("text changed to: ", text)
            }

            focus: true

            Keys.onSpacePressed: {
                increment()
                printKey(Keys.value)
            }

            Keys.onEscapePressed: {
                spacePresses = 0
            }

            function increment(){
                spacePresses = spacePresses + 1
            }

            function printKey(value){
                console.log("Key pressed: " + value)
            }
        }
    }
}
