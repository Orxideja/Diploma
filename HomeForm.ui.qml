import QtQuick 2.12
import QtQuick.Controls 2.5

Page {
    id: general
    width: 501
    height: 351
    property alias textField: textField
    wheelEnabled: true
    spacing: 0
    clip: false
    font.capitalization: Font.MixedCase

    title: qsTr("Программа для тестирования")

    Label {
        id: nameLab
        height: 31
        text: qsTr("Введите свои имя и фамилию:")
        horizontalAlignment: Text.AlignHCenter
        verticalAlignment: Text.AlignVCenter
        anchors.right: parent.right
        anchors.rightMargin: 65
        anchors.verticalCenter: parent.verticalCenter
        anchors.left: parent.left
        anchors.leftMargin: 50
        clip: true
        anchors.verticalCenterOffset: -92
        font.pointSize: 15
        renderType: Text.QtRendering
    }

    TextField {
        id: textField
        x: 69
        y: 105
        width: 363
        height: 32
        text: qsTr("")
        font.pointSize: 8
        visible: true
        horizontalAlignment: Text.AlignHCenter
        // @disable-check M223
        onTextChanged: {
            if (text.length > 0) button.visible = true
            else button.visible = false
        }
    }

    Button {
        id: button
        x: 349
        y: 197
        width: 83
        height: 32
        visible: false
        text: qsTr("ОК")
        clip: true
        focusPolicy: Qt.ClickFocus
        display: AbstractButton.TextBesideIcon
        // @disable-check M223
        onPressed: {
            // @disable-check M222
            user.name = textField.text
            textField.visible = false
            nameLab.text = `Привет, ${user.name}`
            button.visible = false
            ltest.test = 'social'
        }
    }
}




/*##^## Designer {
    D{i:1;anchors_width:358}
}
 ##^##*/
