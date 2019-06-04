import QtQuick 2.4
import QtQuick.Controls 2.5

Page {
    id: element333
    anchors.fill: parent

    TextArea {
        id: textArea
        x: 62
        y: 86
        width: 476
        height: 171
        text: ltest.resultArea
        anchors.verticalCenter: parent.verticalCenter
        anchors.horizontalCenter: parent.horizontalCenter
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
        text: qsTr("Выход")
        anchors.bottom: textArea.top
        anchors.top: textArea.bottom
        focusPolicy: Qt.ClickFocus
        display: AbstractButton.TextBesideIcon
        transformOrigin: Item.Center
        anchors.leftMargin: -343
        anchors.topMargin: 46
        anchors.bottomMargin: -254
        anchors.left: textArea.right
        anchors.rightMargin: -353
        anchors.right: textArea.left
        visible: true
        clip: true
        // @disable-check M223
        onPressed: {
            // @disable-check M222
            Qt.quit()
        }
    }
}
