import QtQuick 2.12
import QtQuick.Window 2.12

Window {
    visible: true
    width: 640
    height: 480

    title: qsTr("TextEdit")

    Flickable{
        id: mFlickableId
        width: textInputId.width
        contentHeight: textInputId.implicitHeight
        height: 300
        clip : true
        anchors.centerIn: parent

        TextEdit{
            id: textInputId
            anchors.centerIn: parent
            width: 240
//            text: "<b>Hello</b> <i>World!</i>"
            text: "<p>TCP-IP possui 4 camadas sendo que o início se dá com o programa conversando na camada de aplicação. Nesta camada você vai encontrar protocolos como o SMTP (para e-mail), FTP (para transferência de arquivos) e HTTP (para navegar na internet) e cada tipo de programa fala para um protocolo diferente da camada de Aplicação, dependendo do propósito do programa.
</p><p>Depois de processar a requisição, o protocolo na camada de Aplicação vai falar com outro protocolo na camada de Transporte, usualmente o TCP. Esta camada é responsável por pegar o dado enviado pela camada de Aplicação, dividindo este dado em pacotes a fim de enviar ele para a camada inferior, a da Internet. Também, durante o recebimento do dados, a camada de Transporte é responsável por colocar os pacotes de dados recebidos da camada de Internet em ordem (os dados podem ser recebidos fora de ordem) e também checar se o conteúdo dos pacotes estão intactos.
</p><p>Na camada da Internet, nós temos o IP (Internet Protocol), que pega os pacotes recebidos da camada de Transporte e adiciona uma informação de endereço virtual. Exemplo: adiciona o endereço do computador que está enviando dados e o endereço do computador que vai receber estes dados. Estes endereços virtuais são chamados de endereços IP. Então o pacote é enviado para a camada inferior, Interface de Rede e quando dos dados chegam nesta camada, eles são chamados de datagramas.
</p><p>A Interface de Rede vai pegar os pacotes enviados pela camada de Internet e enviar através da rede (ou receber da rede, se o computador estiver recebendo dados). O que vai ter dentro desta camada vai depender do tipo de rede que o computador estiver inserido. Hoje em dia, o tipo de rede mais utilizado para comunicação entre computadores é a Ethernet (que é avaliada em diferentes faixas de velocidade) e pode ser cabeada (cabo de par trançado CAT5 ou CAT6) ou WI-FI (sem fio). Ainda dentro da camada de Interface de Rede Ethernet, você deve encontrar camadas Ethernet como a LLC (Logic Link Control), MAC (Media Access Control) e a Física que é o meio físico (cabo por exemplo). Os pacotes transmitidos através da rede são chamados de quadros.
</p>"
            wrapMode: TextEdit.Wrap
            textFormat: TextEdit.RichText
            font {
                family : "Helvetica"
                pointSize: 20
            }
            color: "blue"
            focus: true

            onEditingFinished: {
                console.log("The current text is : " + text)
            }

        }
    }

    Rectangle{
        id: mRectId
        width: 200
        height: 100
        color: "red"
        anchors.top: mFlickableId.bottom

        MouseArea{
            anchors.fill: parent
            onClicked: {
                console.log("The new text is : " + textInputId.text)
            }
        }
    }


}
