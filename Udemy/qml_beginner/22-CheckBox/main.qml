import QtQuick 2.9
import QtQuick.Window 2.2
import QtQuick.Controls 2.5

Window {
    visible: true
    width: 640
    height: 480
    title: qsTr("Hello World")

    Column{

        spacing: 20
        anchors.horizontalCenter:  parent.horizontalCenter
        CheckBox{
            text: "Option1"
            checked: true

            onCheckStateChanged: {
                if(checked === true)
                    console.log("Option1 is checked")
            }
        }

        CheckBox{
            text: "Option2"
            checked: false
        }

        CheckBox{
            text: "Option3"
            enabled: false
        }
    }
}
