# SimpleSteamSession
## Overview
SimpleSteamSession is an Unreal Engine 5 plugin that allows you to connect and expose a Blueprints API, behind Steam backend (SteamWorks). <br>
- It manages <b>session</b> creation, join, quit, update (of all parameters which are available during session) and it handles all disconnections and callbacks. Also it retrieves information about friendlist and user.
- Blueprints nodes are available in order to call this plugin API. <br>
- Project example includes: "Main menu" where you can create a lobby, "Main game map" that includes a "Pause menu" (pressing P). <br> During pause, you can invite friends, open and close the lobby joinability only if you are the host.
- You can check blueprints implementation inside "WBP_PauseMenu" widget, "BP_SimpleSessionGameInstance" game instance and all other assets used. C++ code is also completely available and documented.

This plugin is inspired by <i>Advanced Session</i> plugin: https://github.com/mordentral/AdvancedSessionsPlugin. <br>

## Setup (using this plugin in personal projects)
- Download this project and unzip it (beware this repo includes an example project and the plugin)
- Copy or move "../SimpleSteamSession/Plugins/PNetworking" folder into "Plugins" folder in your project or your engine, if not present you must create it (the name must be "Plugins")
- Rebuild your project
- Modify your "DefaultEngine.ini" file ("Config/DefaultEngine.ini") adding this prompt if not existing, only in your personal projects:
```
/Script/Engine.GameEngine]
+NetDriverDefinitions=(DefName="GameNetDriver",DriverClassName="OnlineSubsystemSteam.SteamNetDriver",DriverClassNameFallback="OnlineSubsystemUtils.IpNetDriver")

[OnlineSubsystem]
DefaultPlatformService=Steam

[OnlineSubsystemSteam]
bEnabled=true
SteamDevAppId=480

; If using Sessions. Need to be false/commented if using Steam lobbies.
; bInitServerOnClient=true

[/Script/OnlineSubsystemSteam.SteamNetDriver]
NetConnectionClassName="OnlineSubsystemSteam.SteamNetConnection"
```
- Open your project and enable "PNetworking" plugin check if this plugin is recognized (under Edit/Plugins toolbar menu)<br><br>
  <img width="1188" height="219" alt="image" src="https://github.com/user-attachments/assets/9928ced9-10f9-4439-8e7b-cfc2cd356b6a" space="100"/><br><br>
- Inherit your Game Instance blueprint from "USimpleSteamSessionGameInstance" class (it will initialize all networking callbacks)
- If there are some compiling troubles, try adding this .dll file: "Plugins/PNetworking/Source/PNetworking/Public/steam/lib/steamapi64.dll" into the "Plugins/PNetworking/Binaries/Win64" folder <br><br>
- More docs: https://dev.epicgames.com/documentation/en-us/unreal-engine/online-subsystem-steam-interface-in-unreal-engine

## Compatibility and usage
- Remember to keep opened the Steam Client in order to connect to the Steam backend, when you start to play your game
- Because of OSS (Online Subsystem Steam) does not include all SteamWorks API, to access avatars we imported "SteamWorks API" under Steam folder: "Plugins/PNetworking/Source/PNetworking/Public/steam"
- This APIs are public, and compatible until UE 5.4.X version. In order to use a newer version of SteamWorks API, if necessary, check here: <br> https://partner.steamgames.com/doc/home and replace all .dll files, but keep the "lib" folder
