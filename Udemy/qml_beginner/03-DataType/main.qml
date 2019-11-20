import QtQuick 2.12
import QtQuick.Window 2.12
/*
  Look for var in help to know more
  */



Window {
    visible: true
    width: 640
    height: 480
    title: qsTr("QML Data type demo")

    property string mString: "Hello World"
    property int mInt: 45
    property bool isFemale: false
    property double mDouble: 77.5
    property url mUrl: "www.google.com"

    property var anArray: [1, 2, 3, "four", "five", (function() { return "six"; })]

    Rectangle{
        width: 200
        height: 100 + mInt

        anchors.centerIn: parent
        color:  "yellow"

        Text {
            id: mTextId
            anchors.centerIn: parent
            text: mString
            font.bold: isFemale? true : false
        }

        MouseArea{
            anchors.fill: parent
            onClicked: {
                console.log("Clicked")
            }
        }
    }

    Component.onCompleted: {
        console.log("The value of mString is : " + mString)
        console.log("The value of mInt is : " + mInt)

        if(isFemale){
           console.log("You are a woman")
        }else{
           console.log("You are a man")
        }
         console.log("The value of mDouble is : " + mDouble)
         console.log("The value of mUrl is : " + mUrl)

        anArray.forEach(function(value, index){
            if(index === 5){
                console.log(value())
            }else{
                console.log(value)
            }
        })

        for(var i = 0; i < anArray.length; i++){
            if(i === 5){
                console.log(anArray[i]());
            }else{
                console.log(anArray[i]);
            }

        }
    }
}
