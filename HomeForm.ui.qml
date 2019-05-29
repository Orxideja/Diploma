import QtQuick 2.12
import QtQuick.Controls 2.5

Page {
    id: general
    width: 501
    height: 351
    wheelEnabled: true
    spacing: 0
    clip: false
    font.capitalization: Font.MixedCase

    title: qsTr("Программа для тестирования")

    Label {
        width: 348
        height: 23
        text: qsTr("Введите свои имя и фамилию:")
        clip: true
        anchors.verticalCenterOffset: -92
        anchors.horizontalCenterOffset: -14
        font.pointSize: 15
        renderType: Text.QtRendering
        anchors.centerIn: parent
    }

    TextInput {
        id: textInput
        x: 69
        y: 131
        width: 363
        height: 22
        color: "#060606"
        horizontalAlignment: Text.AlignLeft
        padding: 1
        rightPadding: 1
        bottomPadding: 1
        leftPadding: 1
        topPadding: 1
        passwordCharacter: qsTr("●")
        autoScroll: false
        echoMode: TextInput.Normal
        activeFocusOnPress: true
        cursorVisible: true
        font.capitalization: Font.MixedCase
        font.kerning: true
        font.preferShaping: true
        selectionColor: "#111211"
        renderType: Text.NativeRendering
        clip: true
        inputMask: ""
        font.pixelSize: 12
    }

    Button {
        id: button
        x: 349
        y: 197
        text: qsTr("ОК")
        clip: true
        focusPolicy: Qt.ClickFocus
        display: AbstractButton.TextBesideIcon
    }
}



































/*##^## Designer {
    D{i:2;anchors_height:22;anchors_width:363;anchors_x:69;anchors_y:131}
}
 ##^##*/
