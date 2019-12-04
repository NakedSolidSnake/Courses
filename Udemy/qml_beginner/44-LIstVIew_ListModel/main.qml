import QtQuick 2.9
import QtQuick.Window 2.2

Window {
    visible: true
    width: 640
    height: 480
    title: qsTr("Hello World")

    ListView{
        id: mListViewId
        anchors.fill: parent
        model: mModelId
        delegate: delegateId
    }

    ListModel{
        id: mModelId

        ListElement{
            country : "Brazil"; capital: "Brazilia"
        }

        ListElement{
            country : "USA"; capital: "Washington"
        }
    }

    Component{
        id: delegateId
        Rectangle{
            id: rectangleId
            width: parent.width
            height: 50
            color: "beige"
            border.color: "yellowgreen"
            radius: 10

            Text{
                id: textId
                anchors.centerIn: parent
                font.pointSize: 20
                text: country + " : " + capital
            }

            MouseArea{
                anchors.fill: parent
                onClicked: {
                    console.log("Clicked " + capital)
                }
            }

        }
    }
}
