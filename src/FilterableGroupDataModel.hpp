/*
 * FilterableGroupDataModel.hpp
 *
 *  Created on: Oct 21, 2012
 *      Author: James Paul Muir
 */

#ifndef FILTERABLEGROUPDATAMODEL_HPP_
#define FILTERABLEGROUPDATAMODEL_HPP_

#include <QtCore/QObject>
#include <bb/cascades/GroupDataModel>

class FilterableGroupDataModel : public bb::cascades::GroupDataModel
{
Q_OBJECT
        Q_PROPERTY(QString filterText READ filterText WRITE setFilterText NOTIFY filterTextChanged FINAL)
        Q_PROPERTY(QString filterAttribute READ filterAttribute WRITE setFilterAttribute NOTIFY filterAttributeChanged FINAL)

public:
        FilterableGroupDataModel(QObject *parent = 0);
        virtual ~FilterableGroupDataModel();


        virtual QVariant data(const QVariantList& indexPath);


        void setFilterText(QString filterText);
        void setFilterAttribute(QString attribute);
        QString filterText();
        QString filterAttribute();
        Q_INVOKABLE void clearFilter();


        bool isFiltered(const QVariantList& indexPath);

signals:
        void filterTextChanged(QString filterText);
        void filterAttributeChanged(QString filterAttribute);

private:
        bb::cascades::DataModel* m_fullDataModel;
    QString mFilterText;
    QString mFilterAttribute;
    QList<QVariantMap> mOriginalItems;
    bool mFirstRun;
    bb::cascades::ItemGrouping::Type mOriginalGrouping;
    int mCount;
};

#endif /* FILTERABLEGROUPDATAMODEL_HPP_ */
