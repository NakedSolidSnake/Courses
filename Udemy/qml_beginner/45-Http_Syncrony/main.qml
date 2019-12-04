import QtQuick 2.9
import QtQuick.Window 2.2
import QtQuick.Controls 2.5

Window {
    visible: true
    width: 640
    height: 480
    title: qsTr("Hello World")

    function downloadData(url){
        var xhr = new XMLHttpRequest();
        xhr.onreadystatechange = function(){
            if(xhr.readyState === XMLHttpRequest.HEADERS_RECEIVED){
                console.log("HEADERS received")
            }else if(xhr.readyState === XMLHttpRequest.DONE){
                if(xhr.status === 200){
                    textDataId.text = xhr.responseText.toString()
                }else{
                    console.log("Error: " + xhr.status)
                }
            }
        }

        xhr.open("GET", url)
        xhr.send()
    }

    TextArea{
        id: textDataId
        anchors.fill: parent
        textFormat: TextArea.RichText
        text: "HTML Data here"
    }

    MouseArea{
        anchors.fill: parent
        onClicked: {
            downloadData("http://www.icndb.com/")
        }
    }
}
