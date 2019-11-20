import QtQuick 2.12
import QtQuick.Window 2.12

Window {
    visible: true
    width: 640
    height: 480
    title: qsTr("Mouse Area")

    Rectangle{
        id : containerRectId
        width: parent.width
        height: 200
        color: "beige"

        Rectangle{
            id: movingRectId
            width: 50
            height: width
            color: "blue"

            MouseArea{
                anchors.fill: parent
                hoverEnabled: true
                onHoveredChanged: {
                    if(containsMouse === true){
                        movingRectId.color = "green"
                    }else{
                        movingRectId.color = "blue"
                    }
                }
            }

        }

        MouseArea{
            anchors.fill: parent
            onClicked: {
                console.log(mouse.x)
                movingRectId.x = mouse.x
                movingRectId.y = mouse.y
            }

            onWheel: {
                console.log("X : " + wheel.x + " y : " + wheel.y + " angle: " + wheel.angleDelta)
            }
        }
    }

    Rectangle{
        id: dragContainerId
        anchors.top: containerRectId.bottom
        width: parent.width
        height: 200
        color: "blue"

        Rectangle{
            id: dragRectId
            width: 50
            height: width
            color: "yellow"
        }

        Rectangle{
            id: staticRectId
            x : 150
            y : 0
            width: 50
            height: width
            color: "yellow"
        }

        MouseArea {
            anchors.fill: parent
            drag.target: dragRectId
            drag.axis: Drag.XandYAxis
            drag.minimumX: 0
            drag.maximumX: dragContainerId.width - dragRectId.width
            drag.minimumY: 0
            drag.maximumY: dragContainerId.height - dragRectId.height

            onReleased: {
                console.log("x: " + mouse.x + " y: " + mouse.y)
            }

            onMouseXChanged: {
                console.log("x: " + mouse.x)
                if(mouse.x === staticRectId.x){
                    console.log("crashed!!!")
                    dragRectId.x = staticRectId.x - staticRectId.width
                }
            }

        }
    }
}
