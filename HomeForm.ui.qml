import QtQuick 2.12
import QtQuick.Controls 2.5

Page {
    id: general
    anchors.fill: parent
    wheelEnabled: true
    spacing: 0
    clip: false
    font.capitalization: Font.MixedCase

    title: qsTr("Программа для тестирования")

    Label {
        id: nameLab
        width: 358
        height: 31
        text: qsTr("Введите свои имя и фамилию:")
        anchors.horizontalCenter: parent.horizontalCenter
        horizontalAlignment: Text.AlignHCenter
        verticalAlignment: Text.AlignVCenter
        anchors.verticalCenter: parent.verticalCenter
        clip: true
        anchors.verticalCenterOffset: -92
        font.pointSize: 15
        renderType: Text.QtRendering
    }

    TextField {
        id: textField
        x: -178
        width: 363
        height: 32
        text: qsTr("")
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.verticalCenterOffset: -23
        font.pointSize: 8
        visible: true
        horizontalAlignment: Text.AlignHCenter
        anchors.verticalCenter: parent.verticalCenter
        // @disable-check M223
        onTextChanged: {
            if (text.length > 0)
                button.visible = true
            else
                button.visible = false
        }
    }

    Button {
        id: button
        y: 70
        width: 163
        height: 51
        visible: false
        text: qsTr("ОК")
        anchors.verticalCenterOffset: 69
        anchors.verticalCenter: parent.verticalCenter
        anchors.horizontalCenterOffset: 3
        anchors.horizontalCenter: parent.horizontalCenter
        clip: true
        focusPolicy: Qt.ClickFocus
        display: AbstractButton.TextBesideIcon
        // @disable-check M223
        onPressed: {
            // @disable-check M222
            ltest.test = 'social'
            user.name = textField.text
            textField.visible = false
            nameLab.text = button.visible = false
            ltest.test = 'social'
        }
    }
}




/*##^## Designer {
    D{i:1;anchors_width:358}
}
 ##^##*/
