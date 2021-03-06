import QtQuick 2.9
import QtQuick.Window 2.2
import QtQuick.Controls 1.4
import QtQuick.Layouts 1.3

Window {
    visible: true
    width: 640
    height: 480
    title: qsTr("Hello World")

    SplitView {
          anchors.fill: parent
          orientation: Qt.Horizontal

          Rectangle {
              width: 200
              Layout.maximumWidth: 400
              color: "lightblue"
              Text {
                  text: "View 1"
                  anchors.centerIn: parent
              }
          }
          Rectangle {
              id: centerItem
              Layout.minimumWidth: 50
              Layout.fillWidth: true
              color: "lightgray"
              Text {
                  text: "View 2"
                  anchors.centerIn: parent
              }
          }
          Rectangle {
              width: 200
              color: "lightgreen"
              Text {
                  text: "View 3"
                  anchors.centerIn: parent
              }
          }
      }
}
