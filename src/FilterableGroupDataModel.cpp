/*
 * FilterableGroupDataModel.cpp
 *
 *  Created on: Oct 21, 2012
 *      Author: James Paul Muir
 */

#include "FilterableGroupDataModel.hpp"

using namespace bb::cascades;

FilterableGroupDataModel::FilterableGroupDataModel(QObject *parent)
:   GroupDataModel(parent), mFilterText(""), mFirstRun(true)
{

}

FilterableGroupDataModel::~FilterableGroupDataModel() {

}

QVariant FilterableGroupDataModel::data(const QVariantList& indexPath)
{

        QVariant data = GroupDataModel::data(indexPath);

        if(mFilterText == NULL || mFilterText == ""){
                return data;
        }

        QVariantMap dataMap = data.toMap();

        QString str = dataMap[mFilterAttribute].value<QString>();

        if(str.contains(mFilterText, Qt::CaseInsensitive)){

                return data;
        }

        return QVariant::Invalid;

}

QString FilterableGroupDataModel::filterText()
{

        return mFilterText;
}

void FilterableGroupDataModel::setFilterText(QString filterText)
{
        filterText = filterText.trimmed();
        if(mFirstRun) {
                QList<QVariantMap> items = toListOfMaps();
                mOriginalItems = items;
                mOriginalGrouping = grouping();
                mFirstRun = false;
        }
        if (mFilterText == ""){
                clearFilter();
        }

        mFilterText = filterText;
        setGrouping(ItemGrouping::None);

        QVariantMap item;
        QList<QVariantMap> filteredItems;

        clear();
        foreach(item, mOriginalItems){
                QString str = item[mFilterAttribute].value<QString>();
                if(str.contains(mFilterText, Qt::CaseInsensitive)){
                        insert(item);
                }
        }
        emit itemsChanged(bb::cascades::DataModelChangeType::AddRemove);
}



void FilterableGroupDataModel::setFilterAttribute(QString attribute)
{
        mFilterAttribute = attribute;
}

QString FilterableGroupDataModel::filterAttribute()
{
        return mFilterAttribute;
}

void FilterableGroupDataModel::clearFilter()
{
        mFilterText = "";
        setGrouping(mOriginalGrouping);
        clear();
        insertList(mOriginalItems);

        emit itemsChanged(bb::cascades::DataModelChangeType::AddRemove);
}


bool FilterableGroupDataModel::isFiltered(const QVariantList& indexPath)
{
        if(mFilterText == NULL || mFilterText == ""){
                return true;
        }

        QVariant data = m_fullDataModel->data(indexPath);
        QVariantMap dataMap = data.toMap();

        QString str = dataMap[mFilterAttribute].value<QString>();
        return str.contains(mFilterText, Qt::CaseInsensitive);
}
