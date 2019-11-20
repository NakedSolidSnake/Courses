import QtQuick 2.12
import QtQuick.Window 2.12

Window {
    visible: true
    width: 640
    height: 480
    title: qsTr("Hello World")

    Column{
        MButton{
            buttonText: "Button 1"
            onButtonClicked: {
                console.log("Button Clicked " + buttonText)
            }
        }

        MButton{

            buttonText: "Button 2"
            onButtonClicked: {
                console.log("Button Clicked " + buttonText)
            }
        }
    }
}
