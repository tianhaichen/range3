/*********************************************************************
 *  AUTHOR: Tomas Soltys                                             *
 *  FILE:   progress_bar.cpp                                         *
 *  GROUP:  Range                                                    *
 *  TYPE:   source file (*.cpp)                                      *
 *  DATE:   23-1h November 2012                                      *
 *                                                                   *
 *  DESCRIPTION: Progress bar class definition                       *
 *********************************************************************/

#include "progress_bar.h"

ProgressBar::ProgressBar(QWidget *parent)
    : QProgressBar(parent)
{
    this->setTextVisible(true);
    this->pulseTimer = new QTimer(this);
    this->pulseTimer->setInterval(100);
    QObject::connect(this->pulseTimer,&QTimer::timeout,this,&ProgressBar::pulse);
}

void ProgressBar::startPulse(void)
{
    this->setRange(0,0);
    this->QProgressBar::setValue(0);
    this->pulseTimer->start();
}

void ProgressBar::stopPulse(void)
{
    if (this->pulseTimer->isActive())
    {
        this->pulseTimer->stop();
    }
}

void ProgressBar::setValue(int value)
{
    this->setFormat(this->message + " (" + QString::number(value) + " %)");
    this->QProgressBar::setValue(value);
}

void ProgressBar::setMessage(const QString &message)
{
    this->message = message;
    this->setFormat(this->message);
}

void ProgressBar::pulse(void)
{
    this->QProgressBar::setValue(this->value() + 2);
}