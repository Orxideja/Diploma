import QtQuick 2.12
import QtQuick.Controls 2.5

Page {
    id: element1
    anchors.fill: parent

    TextArea {
        id: textArea
        width: 476
        height: 143
        text: ltest.description
        anchors.top: parent.top
        anchors.topMargin: 100
        anchors.horizontalCenterOffset: 0
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
        id: button
        width: 260
        height: 57
        text: qsTr("Пройти тестирование")
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.top: textArea.bottom
        focusPolicy: Qt.ClickFocus
        display: AbstractButton.TextBesideIcon
        transformOrigin: Item.Center
        anchors.topMargin: 45
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
        width: 261
        height: 56
        text: qsTr("Пропустить тестирование")
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.top: button.bottom
        focusPolicy: Qt.ClickFocus
        display: AbstractButton.TextBesideIcon
        transformOrigin: Item.Center
        anchors.topMargin: 31
        visible: true
        clip: true
        // @disable-check M223
        onPressed: {
            // @disable-check M222
            ltest.skipTest()
        }
    }
}

/*##^## Designer {
    D{i:0;autoSize:true;height:480;width:640}
}
 ##^##*/
