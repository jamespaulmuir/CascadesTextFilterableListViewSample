#include "FilterableListViewSample.hpp"

#include <bb/cascades/Application>
#include <bb/cascades/QmlDocument>
#include <bb/cascades/AbstractPane>

#include "FilterableGroupDataModel.hpp"

using namespace bb::cascades;

FilterableListViewSample::FilterableListViewSample(bb::cascades::Application *app)
: QObject(app)
{
	qmlRegisterType<FilterableGroupDataModel>("com.jamespaulmuir", 1, 0, "FilterableGroupDataModel");

    QmlDocument *qml = QmlDocument::create("asset:///main.qml").parent(this);
    AbstractPane *root = qml->createRootObject<AbstractPane>();
    app->setScene(root);
}

