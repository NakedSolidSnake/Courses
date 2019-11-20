import QtQuick 2.12
import QtQuick.Window 2.12

Window {
    visible: true
    width: 640
    height: 480
    title: qsTr("Qt Global Object")

    property var fonts: Qt.fontFamilies()

    Rectangle{
        width: 300
        height: 100
        color: "red"
        anchors.centerIn: parent
        MouseArea{
            anchors.fill: parent
            onClicked: {

                for(var i = 0; i < fonts.length; i++){
                    console.log("[" + i + "] : " +fonts[i] )
                }

                var mName = "Cristiano Silva"
                var mNameHash = Qt.md5(mName)
                console.log("Name hash: " + mNameHash)

                //open a url
                //Qt.openUrlExternally("http://www.google.com.br")

                //open file
                //Qt.openUrlExternally("file:///media/solid/videos/Livros/d6fbef1920263958496f0204a5b3339cc06b.pdf")

                //show platfrom
                console.log(Qt.platform.os)

                console.log("Quitting the App")
                Qt.quit()
            }
        }
    }
}
