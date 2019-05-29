import QtQuick 2.12
import QtQuick.Controls 2.5

Page {
    id: general
    width: 640
    height: 480
    wheelEnabled: true
    spacing: 0
    clip: false
    font.capitalization: Font.MixedCase

    title: qsTr("Программа для тестирования")

    Label {
        width: 320
        height: 33
        text: qsTr("Введите свои имя и фамилию:")
        anchors.verticalCenterOffset: -49
        anchors.horizontalCenterOffset: 0
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.verticalCenter: parent.verticalCenter
        clip: true
        font.pointSize: 15
        renderType: Text.QtRendering
    }

    TextInput {
        id: textInput
        color: "#060606"
        text: ""
        anchors.leftMargin: 160
        anchors.topMargin: 229
        anchors.rightMargin: 160
        anchors.bottomMargin: 229
        anchors.fill: parent
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
        renderType: Text.QtRendering
        clip: true
        inputMask: ""
        font.pixelSize: 12
    }

    Button {
        id: button
        text: qsTr("ОК")
        anchors.leftMargin: 407
        anchors.topMargin: 289
        anchors.rightMargin: 160
        anchors.bottomMargin: 165
        anchors.fill: parent
        clip: true
        focusPolicy: Qt.ClickFocus
        display: AbstractButton.TextBesideIcon
    }
}

























































/*##^## Designer {
    D{i:1;anchors_height:23;anchors_width:348}D{i:2;anchors_height:22;anchors_width:363;anchors_x:"-173";anchors_y:48}
D{i:3;anchors_x:170;anchors_y:128}
}
 ##^##*/
