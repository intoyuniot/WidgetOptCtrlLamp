#ifndef WIDGET_OPT_CTRL_LAMP_H_
#define WIDGET_OPT_CTRL_LAMP_H_

#include "application.h"

class WidgetOptCtrlLamp: public WidgetBaseClass
{
    public:
        WidgetOptCtrlLamp(uint8_t ucItem = 0);
        ~WidgetOptCtrlLamp();
        void begin(void (*UserCallBack)(void) = NULL);
        char getLightSwitch(void);
        void displayLampStatus(uint8_t ucVal);
        void control(uint8_t ucPin, uint8_t ucVal);
        void displayLightIntensity(float fLightIntensity);

    private:
        char pCmdSwitchTopic[64];
        char pDataSwitchStatusTopic[64];
        char pDataLightIntensityTopic[64];
        char _switchKey=0;
        uint8_t _Item=0;
        void (*_EventCb)(void);
        void widgetBaseCallBack(uint8_t *payload, uint32_t len);
};

#endif

