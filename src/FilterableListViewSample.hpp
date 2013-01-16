// Default empty project template
#ifndef FilterableListViewSample_HPP_
#define FilterableListViewSample_HPP_

#include <QObject>

namespace bb { namespace cascades { class Application; }}

/*!
 * @brief Application pane object
 *
 *Use this object to create and init app UI, to create context objects, to register the new meta types etc.
 */
class FilterableListViewSample : public QObject
{
    Q_OBJECT
public:
    FilterableListViewSample(bb::cascades::Application *app);
    virtual ~FilterableListViewSample() {}
};


#endif /* FilterableListViewSample_HPP_ */
