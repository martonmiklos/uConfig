#include "componentelectricaldelegate.h"

#include "componentpinsitemmodel.h"

#include <QDebug>
#include <QComboBox>

ComponentElectricalDelegate::ComponentElectricalDelegate(QObject *parent)
    : QItemDelegate(parent)
{
}

QWidget *ComponentElectricalDelegate::createEditor(QWidget *parent, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    if (index.column() == ComponentPinsItemModel::PinElecType)
    {
        QComboBox *combobox = new QComboBox(parent);
        for (int i=0; i<=Pin::NotConnected; i++)
            combobox->addItem(Pin::electricalTypeDesc(static_cast<Pin::ElectricalType>(i)), i);
        return combobox;
    }
    else
    {
        return QItemDelegate::createEditor(parent, option, index);
    }
}

void ComponentElectricalDelegate::setEditorData(QWidget *editor, const QModelIndex &index) const
{
    if (index.column() == ComponentPinsItemModel::PinElecType)
    {
        int value = index.model()->data(index, Qt::EditRole).toInt();
        QComboBox *combobox = static_cast<QComboBox*>(editor);
        int id = combobox->findData(value, Qt::UserRole);
        combobox->setCurrentIndex(id);
        combobox->showPopup();
    }
    else
    {
        return QItemDelegate::setEditorData(editor, index);
    }
}

void ComponentElectricalDelegate::setModelData(QWidget *editor, QAbstractItemModel *model, const QModelIndex &index) const
{
    if (index.column() == ComponentPinsItemModel::PinElecType)
    {
        QComboBox *combobox = static_cast<QComboBox*>(editor);
        int value = combobox->currentData(Qt::UserRole).toInt();
        model->setData(index, value, Qt::EditRole);
    }
    else
    {
        return QItemDelegate::setModelData(editor, model, index);
    }
}

void ComponentElectricalDelegate::updateEditorGeometry(QWidget *editor, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    if (index.column() == ComponentPinsItemModel::PinElecType)
    {
        editor->setGeometry(option.rect);
    }
    else
    {
        return QItemDelegate::updateEditorGeometry(editor, option, index);
    }
}
