import QtQuick 2.4
import QtQuick.Controls 2.5

Page {
    id: element333
    width: 600
    height: 400

    TextArea {
        id: textArea
        x: 62
        y: 86
        width: 476
        height: 143
        text: ltest.description
        textFormat: Text.RichText
        horizontalAlignment: Text.AlignHCenter
        readOnly: true
        renderType: Text.QtRendering
        verticalAlignment: Text.AlignVCenter
        font.pointSize: 10
        placeholderText: ""
    }

    Button {
        id: button333
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
        // @disable-check M223
        onPressed: {
            // @disable-check M222
            ltest.enterTest()
        }
    }

    Button {
        id: button1
        x: -3
        y: 0
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
        // @disable-check M223
        onPressed: {
            // @disable-check M222
            ltest.skipTest()
        }
    }
}
