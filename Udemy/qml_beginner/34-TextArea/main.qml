import QtQuick 2.9
import QtQuick.Window 2.2
import QtQuick.Controls 2.5

Window {
    visible: true
    width: 640
    height: 480
    title: qsTr("Hello World")

    Column{
        spacing : 40
        width: parent.width

        Label{
            width: parent.width
            wrapMode: Label.Wrap
            horizontalAlignment: Qt.AlignHCenter
            text: "TextArea is a multi-line text editor"
        }

        Frame{
            width: parent.width
            TextArea{
                width: 600
                height: 150
                anchors.horizontalCenter: parent.horizontalCenter
                color: "red"
                wrapMode: TextArea.Wrap
                text: "This is a very but very very very very very very very very very very very very very very very very very very very very very very very very very very very very very very very very long text"
            }
        }


    }
}
