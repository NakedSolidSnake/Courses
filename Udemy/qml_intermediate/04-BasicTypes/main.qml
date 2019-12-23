import QtQuick 2.9
import QtQuick.Window 2.2
import QtQuick.Controls 2.5

Window {
    visible: true
    width: 640
    height: 480
    title: qsTr("Hello World")

    Connections{
        target: CppClass
        onSendInt:{
            console.log("This is a QML: sendInt signal cought")
            mText.text = val
        }
    }

   Column{
       Button{
           id: mButton
           text: "Click me"
           onClicked: {
               CppClass.cppSlot()
           }
       }

       Text {
           id: mText
           text:"Default"
       }
   }

}
