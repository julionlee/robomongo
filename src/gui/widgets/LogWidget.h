#ifndef LOGWIDGET_H
#define LOGWIDGET_H

#include <QWidget>
#include <QPlainTextEdit>
#include "domain/MongoManager.h"
#include "events/MongoEvents.h"
#include "settings/ConnectionRecord.h"

namespace Robomongo
{
    class MainWindow;

    /**
     * Log panel
     */
    class LogWidget : public QWidget
    {
        Q_OBJECT

    private:

        /*
        ** Main window this widget belongs to
        */
        MainWindow *_mainWindow;

        /*
        ** Log text box
        */
        QPlainTextEdit *_logTextEdit;

        /**
         * @brief MongoManager
         */
        MongoManager &_mongoManager;
        Dispatcher &_dispatcher;

    public:

        /*
        ** Constructs log widget panel for main window
        */
        LogWidget(MainWindow *mainWindow);

        bool event(QEvent *event);

    public slots:
        void addMessage(const QString &message);

    private:
        void handle(const SomethingHappened *event);
        void handle(const ConnectingEvent *event);
    };

}


#endif // LOGWIDGET_H
