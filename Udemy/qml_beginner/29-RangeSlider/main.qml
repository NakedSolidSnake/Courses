import QtQuick 2.9
import QtQuick.Window 2.2
import QtQuick.Controls 2.5

Window {
    visible: true
    width: 640
    height: 480
    title: qsTr("Hello World")

    Row{
        width: parent.width
        spacing: 40

        RangeSlider{
            orientation: Qt.Vertical
            from: 1
            to : 100

            first.value: 25

            second.value: 75

            first.onValueChanged: {
                console.log(first.value)
            }

            second.onValueChanged: {
                console.log(second.value)
            }
        }

    }
}
