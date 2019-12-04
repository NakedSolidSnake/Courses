import QtQuick 2.9
import QtQuick.Window 2.2
import QtQuick.Controls 2.5

Window {
    visible: true
    width: 640
    height: 480
    title: qsTr("Hello World")

    Column{
        SpinBox{
            id: sbId
            editable: true
            value: 50
            from: 0
            to: 100

            onValueChanged: {
                console.log(sbId.value)
            }

            onEnabledChanged: {
                console.log("finished")
            }
        }
    }
}
