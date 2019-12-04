import QtQuick 2.9
import QtQuick.Window 2.2
import QtQuick.Controls 2.5

Window {
    visible: true
    width: 640
    height: 480
    title: qsTr("Hello World")

    function downloadData(url, callback){
        var xhr = new XMLHttpRequest()

        xhr.onreadystatechange = function(){
            if(xhr.readyState === XMLHttpRequest.HEADERS_RECEIVED){

            }else if(xhr.readyState === XMLHttpRequest.DONE){
                if(xhr.status === 200){
                    callback(xhr.responseText.toString())
                }else{
                    callback(null)
                }
            }
        }

        xhr.open("GET", url)
        xhr.send()
    }

    TextArea{
        id: textAreaId
        anchors.fill: parent
        textFormat: TextArea.RichText
        text: "HTML Data Here"
    }

    MouseArea{
        anchors.fill: parent
        onClicked: {
            downloadData("http://www.icndb.com/", function(response){
                if(response){
                    textAreaId.text = response
                }else{
                    textAreaId.text = "Error"
                }
            })
        }
    }
}
