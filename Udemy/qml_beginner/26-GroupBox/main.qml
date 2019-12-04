import QtQuick 2.9
import QtQuick.Window 2.2
import QtQuick.Controls 2.5

Window {
    visible: true
    width: 640
    height: 480
    title: qsTr("Hello World")

    Row{
        Column{
            spacing: 10

            Label{
                width: parent.width
                wrapMode: Label.Wrap
                horizontalAlignment: Qt.AlignHCenter
                text: "A GroupBox wrapping around RadioButtons"
            }

            GroupBox{
                title: "Choose bonus"
                anchors.horizontalCenter: parent.horizontalCenter

                Column{
                    RadioButton{
                        text: "Coke"
                    }

                    RadioButton{
                        text: "Green Tea"
                    }

                    RadioButton{
                        text: "Ice Cream"
                    }
                }
            }
        }

        Column{
            spacing: 10

            Label{
                width: parent.width
                wrapMode: Label.Wrap
                horizontalAlignment: Qt.AlignHCenter
                text: "A GroupBox wrapping around CheckBoxes"
            }

            GroupBox{
                title: "Choose Options"
                anchors.horizontalCenter: parent.horizontalCenter

                Column{

                    CheckBox{
                        text: "With Color"
                    }

                    CheckBox{
                        text: "With Border"
                    }

                    CheckBox{
                        text: "With Format"
                    }

                }
            }
        }
    }


}
