import QtQuick 2.9
import QtQuick.Window 2.2
import QtQuick.Controls 2.5
import QtQuick.Layouts 1.3

Window {
    visible: true
    width: 640
    height: 480
    title: qsTr("Hello World")

    function fetchJokes(url, callback){
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

    ColumnLayout{
        anchors.fill: parent
        spacing: 0

        ListModel{
            id: mLIstModel

        }

        ListView{
            id: lvId
            model: mLIstModel
            delegate: delegateId

            Layout.fillWidth: true
            Layout.fillHeight: true
        }

        SpinBox{
            id: sbId
            Layout.fillWidth: true
            value: 10
        }

        Button{
            id: btId
            Layout.fillWidth: true
            text: "Fetch"

            onClicked: {
                fetchJokes("http://api.icndb.com/jokes/random/" + sbId.value, function(response){

                    if(response){
                        var object = JSON.parse(response)

                        object.value.forEach(function(joke){
                         mLIstModel.append({"joke" : joke.joke})
                        })
                    }else{
                        console.log("Something went wrong")
                    }

                })
            }
        }

        Component{
            id: delegateId
            Rectangle{
                id: rectId
                width: parent.width
                height: txtId.implicitHeight + 30
                color: "beige"
                border.color: "yellowgreen"
                radius: 5

                Text{
                    id: txtId
                    width: parent.width
                    height: parent.height
                    anchors.centerIn: parent
                    text: joke
                    font.pointSize: 13
                    wrapMode: Text.WordWrap
                    verticalAlignment: Text.AlignVCenter
                    horizontalAlignment: Text.AlignHCenter
                }

            }


        }
    }
}
