import QtQuick 2.12
import QtQuick.Controls 2.5

Page {
    id: page
    transformOrigin: Item.BottomRight

    title: qsTr("Социальный тест")

    Text {
        id: element
        x: 46
        y: 26
        width: 251
        height: 26
        text: qsTr("1. Имеете ли Вы опыт работы с заказчиком? ")
        font.pixelSize: 12
    }

    RadioButton {
        id: radioButton
        x: 46
        y: 69
        width: 95
        height: 20
        text: qsTr("Нет")
    }

    RadioButton {
        id: radioButton1
        x: 46
        y: 117
        width: 158
        height: 20
        text: qsTr("В составе команды")
    }

    RadioButton {
        id: radioButton2
        x: 46
        y: 159
        width: 170
        height: 20
        text: qsTr("Самостоятельно -1-3 лет")
    }

    RadioButton {
        id: radioButton3
        x: 46
        y: 200
        width: 199
        height: 20
        text: qsTr("Самостоятельно более 3 лет")
    }
}

/*##^## Designer {
    D{i:5;anchors_height:20;anchors_width:199;anchors_x:46;anchors_y:200}
}
 ##^##*/
