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
        spacing: 20

        Slider{
            from:1
            to : 100
            value: 40

            onValueChanged: {
                console.log(value)
            }
        }

    }
}
