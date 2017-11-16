/*
 ************************************************************************
 * 作者:  IntoRobot Team
 * 版本:  V1.0.0
 * 日期:  03-30-15
 ************************************************************************
 功能描述：
 智能光控灯：具有光照强度检测的智能灯，根据光强度控制灯的开关

 所需器件:
 1.GY-30 数字光强度光照传感器
 2.LED灯泡
 3.继电器模块

 接线说明:
 GY-30                       核心板
 1.VIN                       +3.3V
 2.GND                        GND
 3.SDA                        I2C(Wire组)的SDA
 4.SCL                        I2C(Wire组)的SCL
 继电器模块
 1.DC+：                      +5V
 2.DC-：                      GND
 3.IN：                       D0
 4.NO：                       灯的正极
 5.COM：                      +5V
 6.NC：                       悬空
 7.触发选择端：选择跳线与high短接, 即高电平触发。

说明：带有“D”的为数字管脚，带有“A”的为模拟管脚，接线时请确认核心板引脚，避免接线错误。
请注意各核心板的I2C引脚区别，避免接线错误。
 */

#include <gy30.h>
#include <WidgetOptCtrlLamp.h>

#define LAMP_SWITCH_PIN    D0    //定义灯泡控制引脚

WidgetOptCtrlLamp lamp = WidgetOptCtrlLamp();
GY30 gy30;

void lightSwitchCb(void)
{
    if(lamp.getLightSwitch())
    {
        lamp.control(LAMP_SWITCH_PIN,1);
    }
    else
    {
        lamp.control(LAMP_SWITCH_PIN,0);
    }
}

void setup()
{
    //初始化
    gy30.begin();
    //接收灯开关控制
    lamp.begin(lightSwitchCb);
}

void loop()
{
    lamp.displayLightIntensity(gy30.Read());	//上送光照强度值
    delay(3000);
}
