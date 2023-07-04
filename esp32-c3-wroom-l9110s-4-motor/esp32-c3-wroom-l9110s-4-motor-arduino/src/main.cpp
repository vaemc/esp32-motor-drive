#include <Arduino.h>
#include <iostream>
#include <string>
#include <unordered_map>
#include <functional>
#include <WiFiManager.h>
#include <WebSocketsServer.h>
#include <MecanumWheel.h>

WebSocketsServer webSocket = WebSocketsServer(8686);
std::unordered_map<std::string, std::function<void()>> controlMethodMap;

uint32_t getChipId()
{
  uint32_t chipId = 0;
  for (int i = 0; i < 17; i = i + 8)
  {
    chipId |= ((ESP.getEfuseMac() >> (40 - i)) & 0xff) << i;
  }

  return chipId;
}

void webSocketEvent(uint8_t num, WStype_t type, uint8_t *payload, size_t length)
{

  switch (type)
  {
  case WStype_TEXT:
    String text = (char *)payload;
    Serial.println(text);

    auto it = controlMethodMap.find(text.c_str());
    if (it != controlMethodMap.end())
    {
      it->second();
    }

    break;
  }
}

void initMotorDriver()
{
  MecanumWheel car(Motor(7, 6), Motor(5, 4), Motor(10, 1), Motor(18, 19));

  controlMethodMap = {
      {"forward", [&car]()
       { car.moveForward(); }},
      {"backward", [&car]()
       { car.moveBackward(); }},
      {"left", [&car]()
       { car.moveLeft(); }},
      {"right", [&car]()
       { car.moveRight(); }},
      {"forwardLeft", [&car]()
       { car.moveTopLeft(); }},
      {"backwardLeft", [&car]()
       { car.moveBottomLeft(); }},
      {"forwardRight", [&car]()
       { car.moveTopRight(); }},
      {"backwardRight", [&car]()
       { car.moveBottomRight(); }},
      {"clockwise", [&car]()
       { car.rotateClockwise(); }},
      {"counterclockwise", [&car]()
       { car.rotateCounterClockwise(); }},
      {"stop", [&car]()
       { car.stop(); }},
  };
}

void setup()
{
  Serial.begin(115200);

  // 获取芯片ID并生成配网热点名称
  uint32_t chipId = getChipId();
  char apName[50];
  sprintf(apName, "%s%u", "小车配网热点-", chipId);

  WiFiManager wm;
  bool res;
  res = wm.autoConnect(apName); // WiFi配网热点

  webSocket.begin();                 // 启动WebSocket服务器
  webSocket.onEvent(webSocketEvent); // 设置WebSocket事件处理函数

  String ipString = WiFi.localIP().toString();
  Serial.println("手机连接地址: ws://" + ipString + ":8686");

  initMotorDriver(); // 初始化电机驱动
}

void loop()
{
  webSocket.loop(); // 处理WebSocket事件
}
