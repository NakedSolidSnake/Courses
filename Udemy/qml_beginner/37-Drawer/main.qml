import QtQuick 2.9
import QtQuick.Window 2.2
import QtQuick.Controls 2.5
import QtQuick.Layouts 1.3

ApplicationWindow {
    id : windowId
    visible: true
    width: 640
    height: 480
    title: qsTr("Hello World")

    header: ToolBar{
        height: 50
        background:  Rectangle{
            color: "mintcream"
        }

        RowLayout{
            spacing: 0
            anchors.fill: parent

            ToolButton{
                background: Rectangle{
                    color: "mintcream"
                }

                icon.source: "/icon/icon/drawer.png"

                onClicked: {
                    console.log("Toolbutton clicked")
                    drawerId.open()
                }
            }

            Label{
                id: lbTitle
                text: "Drawer demo"
                font.pixelSize: 20
                elide: Label.ElideRight
                horizontalAlignment: Qt.AlignHCenter
                verticalAlignment: Qt.AlignVCenter
                Layout.fillWidth: true
            }
        }
    }

    Drawer{
        id: drawerId
        width: Math.min(windowId.width, windowId.height) * 2/3
        height: windowId.height
        interactive: true

        Column{
            spacing: 0
            width: parent.width

            Button{
                width: parent.width
                height: 50
                text: "Item 1"
                font.pointSize: 20
                background: Rectangle{
                    color: "beige"
                }

                Layout.fillWidth: true

                onClicked: {
                    console.log("Item 1 choosed")
                    drawerId.close()
                }
            }

            Button{
                width: parent.width
                height: 50
                text: "Item 2"
                font.pointSize: 20
                background: Rectangle{
                    color: "beige"
                }

                Layout.fillWidth: true

                onClicked: {
                    console.log("Item 2 choosed")
                    drawerId.close()
                }
            }

            Button{
                width: parent.width
                height: 50
                text: "Item 3"
                font.pointSize: 20
                background: Rectangle{
                    color: "beige"
                }

                Layout.fillWidth: true

                onClicked: {
                    console.log("Item 3 choosed")
                    drawerId.close()
                }
            }
        }
    }
}
