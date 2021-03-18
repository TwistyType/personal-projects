#NoEnv  ; Recommended for performance and compatibility with future AutoHotkey releases.
; #Warn  ; Enable warnings to assist with detecting common errors.
SendMode Input  ; Recommended for new scripts due to its superior speed and reliability.
SetWorkingDir %A_ScriptDir%  ; Ensures a consistent starting directory.

; Google Search highlighted text
^+c::
{
 Send, ^c
 Sleep 50
 Run, http://www.google.com/search?q=%clipboard%
 Return
}

;Launch SAP Logon
F1::Run "C:\Program Files (x86)\SAP\FrontEnd\SAPgui\saplogon.exe"
return

;Launch YouTube Music App
F7::Run "C:\Users\ashljames\AppData\Local\Programs\youtube-music-desktop-app\YouTube Music Desktop App.exe"
return
