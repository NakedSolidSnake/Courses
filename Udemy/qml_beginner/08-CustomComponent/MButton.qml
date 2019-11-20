import QtQuick 2.0
Item{
    id : rootId
    //expose to outside
    property alias buttonText: buttonTextId.text
    signal buttonClicked
    width: containerRectId.width
    height: containerRectId.height

    Rectangle{
        id : containerRectId
        width: buttonTextId.implicitWidth + 20
        height: buttonTextId.implicitHeight + 20
        color: "red"
        border{
            color: "blue"
            width: 3
        }

        Text {
            id: buttonTextId
            text: "Button"
            anchors.centerIn: parent
        }

        MouseArea{
            anchors.fill: parent
            onClicked: {
                rootId.buttonClicked()
            }
        }
    }
}


