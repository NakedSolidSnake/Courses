import QtQuick 2.12
import QtQuick.Window 2.12

Window {
    visible: true
    width: 640
    height: 480
    title: qsTr("Basic Elements")

    Item{
        id : containerItemId
        x : 50
        y : 50
        width: 400
        height: 300

        Rectangle{
            anchors.fill: parent
            color: "beige"
            border.color: "black"
        }

        Rectangle{
            x : 0
            y : 10
            width: 50
            height: 50
            color : "red"
            MouseArea{
                anchors.fill: parent
                onClicked: {

                }

            }
        }

        Rectangle{
            x : 60
            y : 10
            width: 50
            height: 50
            color : "green"
            MouseArea{
                anchors.fill: parent
                onClicked: {

                }

            }
        }

        Rectangle{
            x : 120
            y : 10
            width: 50
            height: 50
            color : "blue"
            MouseArea{
                anchors.fill: parent
                onClicked: {

                }

            }
        }

        Rectangle{
            x : 180
            y : 10
            width: 50
            height: 50
            color : "magenta"
            MouseArea{
                anchors.fill: parent
                onClicked: {

                }

            }
        }

        Text {
            x : 100
            y : 100
            id: mTextId
            text: qsTr("This is My Text")
            font{
                family: "Helvetica"
                pointSize: 13
                bold: true
            }

//            font.pointSize: 20
            color: "gray"
        }

        Image {
            id: name
            x : 10
            y : 150

            source: "file:///home/solid/Pictures/6WL54_1.jpg"
        }
    }
}
