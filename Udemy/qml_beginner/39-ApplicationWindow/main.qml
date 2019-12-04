import QtQuick 2.9
import QtQuick.Window 2.2
import QtQuick.Controls 2.5

ApplicationWindow {
    visible: true
    width: 640
    height: 480
    title: qsTr("Hello World")

    menuBar: MenuBar{
        Menu{
            title: "file"
            Action{
                id: newActionId
                text: qsTr("&New")
                icon.source: ""
                onTriggered: {
                    // This is available in all editors.
                    console.log("Clicked on new")
                }
            }

            MenuSeparator{}

            Action{
                id: closeActionId
                text: qsTr("&Close")
                icon.source: ""
                onTriggered: {
                    // This is available in all editors.
                    console.log("Clicked on Close")
                    close()
                }
            }
        }
    }

    header: ToolBar{
        Row{
            anchors.fill: parent

            ToolButton{
                action: newActionId
            }

            ToolButton{
                action: closeActionId
            }
        }
    }

    footer: TabBar{

    }
}
