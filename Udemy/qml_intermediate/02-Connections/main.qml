import QtQuick 2.9
import QtQuick.Window 2.2

Window {
    visible: true
    width: 640
    height: 480
    title: qsTr("Hello World")

    Column{
        Rectangle{
            width: 100
            height: 100
            color: "red"

            MouseArea{
                id: redRectId
                anchors.fill: parent
                onClicked: {
                    console.log("Clicked in the red rectangle")
                }

            }
        }

        Rectangle{
            width: 100
            height: 100
            color: "blue"

            Connections{
                target: redRectId
                onClicked:{
                    console.log("red signal received in blue rectangle")
                    blueTextId.text = "Ok"
                }
            }

            Text {
                id: blueTextId
                text: "NOk"
            }
        }

        Rectangle{
            width: 100
            height: 100
            color: "green"

            Connections{
                target: redRectId
                onClicked:{
                    console.log("red signal green in blue rectangle")
                    greenTextId.text = "OK"
                }
            }

            Text {
                id: greenTextId
                text: "NOk"
            }
        }
    }
}
