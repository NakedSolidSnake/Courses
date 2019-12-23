import QtQuick 2.9
import QtQuick.Window 2.2
import QtQuick.Controls 2.5
import QtQuick.Layouts 1.3

Window {
    visible: true
    width: 640
    height: 480
    title: qsTr("Hello World")

    ColumnLayout{
        spacing: 0
        anchors.fill : parent

        ListView{
            id: listView
            model: 30
            delegate: Rectangle{
                width: parent.width
                height: textId.implicitHeight + 30
                color: "beige"
                border.color: "yellowgreen"
                radius: 5

                Text {
                    id: textId
                    width: parent.width
                    height: parent.height
                    anchors.centerIn: parent
                    text: modelData
                    font.pointSize: 13
                    wrapMode: Text.WordWrap
                    verticalAlignment: Text.AlignVCenter
                    horizontalAlignment: Text.AlignHCenter
                }
            }

            Layout.fillHeight: true
            Layout.fillWidth: true
        }

        Button{
            id: mButton
            anchors.horizontalCenter: parent.horizontalCenter
            text: "Fetch"
            onClicked: {
                var val = spinBox.value
                console.log("val: " + val)
                Wrapper.fetchPosts(val)
            }
        }

        SpinBox{
            id: spinBox
            anchors.horizontalCenter: parent.horizontalCenter

            from: 1
            to : 10

        }
    }




}
