# Telegramm-Admin-Tool
Tool for remote administration of your computer using telegram api
## How it works?
We send a request with parameters (our bot_token and chat_id) using the Requests class, which has a send_request method. Thus, we send a request (with parameters, and a request of the GET type) to the telegram server, receive a response and parse it for possible errors.
## How to download:
git clone --recursive https://github.com/Retr0Wawe/Telegram-Remote-Tool
## Example main:
```cpp
#include "TGBotFunc.hpp"

using namespace Tg;

int WINAPI wWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, PWSTR pCmdLine, int nCmdShow)
{
	Telegram tg("your bot key", "your chat id");

	Init(tg);

	while(tg.Check_Errors()) //example commands
	{
		Delay(0.5);

		std::string last_message = tg.Get_Last_Message();

		if (last_message == "/cmd") {
			tg.Send_Message("/Succes!");
			system("start cmd");
		}

		else if (last_message == "/shutdown") {
			tg.Send_Message("/Succes!");
			system("shutdown -p");
		}

		else if (last_message == "/exit") {
			tg.Send_Message("/Succes!");
			break;
		}

		else if (last_message == "/pwd") {
			tg.Send_Message("/Succes!");
			char buffer[MAX_PATH];

			GetCurrentDirectoryA(MAX_PATH, buffer);
			tg.Send_Message(buffer);
		}
	}
}
```
