import QtQuick 2.9
import QtQuick.Window 2.2
import QtQuick.Controls 2.5

Window {
    visible: true
    width: 640
    height: 480
    title: qsTr("Hello World")

    Column{
        spacing: 20
        anchors.centerIn: parent

        Row{
            spacing: 30
            width: 300

            Label{
                width: 100
                height: 50
                wrapMode: Label.Wrap
                horizontalAlignment: Qt.AlignHCenter
                verticalAlignment: Qt.AlignVCenter
                text: "First Name : "
            }

            TextField{
                id: tfId
                width: 200
                height: 50
                placeholderText: "Type your first name"
            }
        }

        Button{
            id: btId
            text: "Submit"

            onClicked: {
                console.log(tfId.text)
            }
        }
    }
}
