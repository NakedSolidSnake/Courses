import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.5
import QtQuick.Layouts 1.3


Window {
    id: root
    visible: true
    width: 640
    height: 480
    title: qsTr("Hello World")

    Rectangle{
        width: parent.width
        height: parent.height

        ColumnLayout{
            anchors.fill: parent
            spacing: 10
            Text {
                Layout.alignment: Qt.AlignCenter
                id: txId
                text: qsTr("Main Screen")
            }

            Rectangle{
                width: 400
                height:400
                radius: 25
                border.width: 1
                Layout.alignment: Qt.AlignCenter

                RowLayout{
                    spacing: 20
                    Button{
                        id :btCallApp1
                        text: "Call App1"

                        onClicked: {
                            loaderApp1.source = "app1.qml"
                        }
                    }

                    Button{
                        id: btCallApp2
                        text: "Call App2"

                        onClicked: {
                            loaderApp2.source = "app2.qml"
                        }
                    }
                }
            }
        }
    }

    Loader{
        id: loaderApp1
    }

    Loader{
        id: loaderApp2
    }
}
