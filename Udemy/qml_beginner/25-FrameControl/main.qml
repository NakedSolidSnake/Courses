import QtQuick 2.9
import QtQuick.Window 2.2
import QtQuick.Controls 2.5
import QtQuick.Layouts 1.3

Window {
    visible: true
    width: 640
    height: 480
    title: qsTr("Hello World")

    Frame{
        anchors.centerIn: parent
        ColumnLayout{
            Button{
                text: "Button1"
            }
            Button{
                text: "Button2"
            }
            Button{
                text: "Button3"
            }
        }
    }
}
