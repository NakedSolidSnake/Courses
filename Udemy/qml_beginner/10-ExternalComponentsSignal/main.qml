import QtQuick 2.12
import QtQuick.Window 2.12

Window {
    visible: true
    width: 640
    height: 480
    title: qsTr("External Components with signals and slots")

    Notifier{
        id: notifierId
        target: receiverId
        rectColor: "yellowgreen"
    }

    Receiver{
        id: receiverId
        rectColor: "dodgerblue"
        anchors.right: parent.right
    }
//    Component.onCompleted: {
//        notifierId.notify.connect(receiverId.receiveInfo) //connect signal and slot
//    }
}
