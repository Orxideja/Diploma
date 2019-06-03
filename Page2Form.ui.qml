import QtQuick 2.12
import QtQuick.Controls 2.5

Page {
    width: 600
    height: 400

    title: qsTr("Профессиональный тест")

    Button {
        id: button1
        x: 190
        y: 323
        text: qsTr("Пропустить тестирование")
        anchors.bottom: parent.bottom
        anchors.top: parent.top
        focusPolicy: Qt.ClickFocus
        display: AbstractButton.TextBesideIcon
        transformOrigin: Item.Center
        anchors.leftMargin: 190
        anchors.topMargin: 323
        anchors.bottomMargin: 37
        anchors.left: parent.left
        anchors.rightMargin: 190
        anchors.right: parent.right
        visible: true
        clip: true
    }

    Button {
        id: button
        x: 190
        y: 249
        text: qsTr("Пройти тестирование")
        anchors.bottom: parent.bottom
        anchors.top: parent.top
        focusPolicy: Qt.ClickFocus
        display: AbstractButton.TextBesideIcon
        transformOrigin: Item.Center
        anchors.leftMargin: 190
        anchors.topMargin: 249
        anchors.bottomMargin: 111
        anchors.left: parent.left
        anchors.rightMargin: 190
        anchors.right: parent.right
        visible: true
        clip: true
    }

    TextArea {
        id: textArea
        x: 62
        y: 86
        width: 476
        height: 143
        text: "Профессиональный тест\n"
        textFormat: Text.RichText
        horizontalAlignment: Text.AlignHCenter
        renderType: Text.QtRendering
        readOnly: true
        verticalAlignment: Text.AlignVCenter
        placeholderText: ""
        font.pointSize: 10
    }


}
