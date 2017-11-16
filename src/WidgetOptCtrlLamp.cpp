#include "WidgetOptCtrlLamp.h"


WidgetOptCtrlLamp::WidgetOptCtrlLamp(uint8_t ucItem)
{
    _Item=ucItem;
    memset(pCmdSwitchTopic,0,sizeof(pCmdSwitchTopic));
    memset(pDataSwitchStatusTopic,0,sizeof(pDataSwitchStatusTopic));
    memset(pDataLightIntensityTopic,0,sizeof(pDataLightIntensityTopic));

    sprintf(pCmdSwitchTopic,"channel/optCtrlLamp_%d/cmd/switch",_Item);
    sprintf(pDataSwitchStatusTopic,"channel/optCtrlLamp_%d/data/status",_Item);
    sprintf(pDataLightIntensityTopic,"channel/optCtrlLamp_%d/data/illumination",_Item);
}

WidgetOptCtrlLamp::~WidgetOptCtrlLamp()
{

}

void WidgetOptCtrlLamp::begin(void (*UserCallBack)(void))
{
    _EventCb=UserCallBack;
    IntoRobot.subscribe(pCmdSwitchTopic, NULL, this);
}

char WidgetOptCtrlLamp::getLightSwitch(void)
{
    return _switchKey;
}

void WidgetOptCtrlLamp::displayLampStatus(uint8_t ucVal)
{
    IntoRobot.publish(pDataSwitchStatusTopic,ucVal);
}

void WidgetOptCtrlLamp::displayLightIntensity(float fLightIntensity)
{
    IntoRobot.publish(pDataLightIntensityTopic,fLightIntensity);
}

void WidgetOptCtrlLamp::control(uint8_t ucPin, uint8_t ucVal)
{
    pinMode(ucPin,OUTPUT);
    digitalWrite(ucPin, ucVal);
    displayLampStatus(ucVal);
}

void WidgetOptCtrlLamp::widgetBaseCallBack(uint8_t *payload, uint32_t len)
{
    if(payload[0] == '1')
    {
        _switchKey=1;
    }
    else
    {
        _switchKey=0;
    }
    _EventCb();
}

