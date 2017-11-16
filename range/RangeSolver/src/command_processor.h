/*********************************************************************
 *  AUTHOR: Tomas Soltys                                             *
 *  FILE:   command_processor.h                                      *
 *  GROUP:  Range                                                    *
 *  TYPE:   header file (*.h)                                        *
 *  DATE:   26-th August 2013                                        *
 *                                                                   *
 *  DESCRIPTION: Command processor class declaration                 *
 *********************************************************************/

#ifndef __COMMAND_PROCESSOR_H__
#define __COMMAND_PROCESSOR_H__

#include <QObject>
#include <QCoreApplication>
#ifdef _WIN32
#include <QWinEventNotifier>
#include <windows.h>
#else
#include <QSocketNotifier>
#endif

class CommandProcessor : public QObject
{

    Q_OBJECT

    protected:

        //! Processing is enabled.
        bool enabled;
#ifdef _WIN32
        //! Windows event notifier.
        QWinEventNotifier *stdinNotifier;
#else
        //! Standard input notifier.
        QSocketNotifier *stdinNotifier;
#endif

    public:

        //! Constructor.
        explicit CommandProcessor(QCoreApplication *application = 0);

        //! Start listening and processing.
        void setEnabled(bool enabled);
        
    public slots:

        //! Run processor.
        void readStdin(int socket);
        
};

#endif // __COMMAND_PROCESSOR_H__
