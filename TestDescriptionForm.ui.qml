import QtQuick 2.4
import QtQuick.Controls 2.5

Item {
    id: element1
    width: 400
    height: 400

    Text {
        id: element
        x: 89
        y: 127
        width: 198
        height: 45
        text: ltest.description
        verticalAlignment: Text.AlignVCenter
        horizontalAlignment: Text.AlignHCenter
        anchors.horizontalCenter: parent.horizontalCenter
        font.pixelSize: 12
    }

    Button {
        id: button
        x: 71
        y: 244
        width: 83
        height: 32
        text: "IN"
        clip: true
        visible: true
        display: AbstractButton.TextBesideIcon
        focusPolicy: Qt.ClickFocus
        // @disable-check M223
        onPressed: {
            // @disable-check M222
            ltest.enterTest()
        }
    }

    Button {
        id: buttonNext
        x: 245
        y: 244
        width: 83
        height: 32
        text: "NEXT"
        clip: true
        visible: true
        display: AbstractButton.TextBesideIcon
        focusPolicy: Qt.ClickFocus
        // @disable-check M223
        onPressed: {
            // @disable-check M222
            ltest.skipTest()
        }
    }
}
