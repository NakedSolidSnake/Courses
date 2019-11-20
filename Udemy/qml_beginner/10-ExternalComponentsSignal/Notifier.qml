import QtQuick 2.0

Item {
    property alias rectColor: notifierRectId.color
    width: notifierRectId.width
    height: notifierRectId.height
    property  int count : 0
    signal notify(string count)//Declare a signal
    property Receiver target: null

    onTargetChanged: {
        notify.connect(target.receiveInfo)
    }


    Rectangle{
        id: notifierRectId
        width: 200
        height: 200
        color: "red"

        Text{
            id: displayTextId
            anchors.centerIn: parent
            font{
                pointSize: 12
            }
            text: count
        }

        MouseArea{
            anchors.fill: parent
            onClicked: {
                count++;
                notify(count)
            }
        }
    }
}
