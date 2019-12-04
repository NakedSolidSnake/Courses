import QtQuick 2.9
import QtQuick.Window 2.2
import QtQuick.Controls 2.5

Window {
    visible: true
    width: 640
    height: 480
    title: qsTr("Hello World")

    Column{
        width: parent.width
        spacing: 20

        Switch{
            id: switchWifiId
            text: "Wifi"
        }

        Button{
            id: buttonId

            onClicked: {
                if(switchWifiId.checked){
                    console.log("Wifi On")
                }else{
                    console.log("Wifi Off")
                }
            }
        }
    }
}
