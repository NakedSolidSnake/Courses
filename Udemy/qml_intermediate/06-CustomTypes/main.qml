import QtQuick 2.12
import QtQuick.Window 2.12
import com.solid.counter 1.0
import QtQuick.Controls 2.5

Window {
    visible: true
    width: 640
    height: 480
    title: qsTr("Hello World")

    Counter{
        id: mCounter
    }

    Column{
        anchors.centerIn: parent
        spacing: 10

        Rectangle{
            width: parent.width
            height: 200
            radius: 20
            color: (mCounter.count >= 0) ? "green" : "red"

            Text {
                id: mText
                text: mCounter.count
                anchors.centerIn: parent
            }
        }

        Row{
            spacing: 10



            Button{
                id: btStart
                text: "Start"
                onClicked: {
                    mCounter.start()
                }

            }

            Button{
                id: btStop
                text: "Stop"
                onClicked: {
                    mCounter.stop()
                }
            }

            Button{
                id: btUp
                text: "Up"
                onClicked: {
                    mCounter.up = true
                }
            }

            Button{
                id: btDown
                text: "Down"
                onClicked: {
                    mCounter.up = false
                }
            }
        }
    }
}
