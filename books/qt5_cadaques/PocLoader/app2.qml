import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.5
import QtQuick.Layouts 1.3

Window{
    id: rootApp2
    visible: true
    width: 640
    height: 480

    Rectangle{
        anchors.centerIn: parent
        ColumnLayout{
            Text {
                Layout.alignment: Qt.AlignCenter
                id: txId
                text: qsTr("App 2")
            }

            Rectangle{
                Layout.alignment: Qt.AlignCenter
                color: "blue"
                width: 100
                height: 100
                Text{
                    anchors.centerIn: parent
                    text: "Rectangle app2"
                }
            }
        }
    }
}
