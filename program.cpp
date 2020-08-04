//console

#include <iostream>
#include <Windows.h>
#include <TlHelp32.h>
#include <thread>




using namespace std;
int main()
{
    HANDLE process;
    HWND hwnd;

    do {
        hwnd = FindWindowA(0, "APP Window Title Name");
        Sleep(50);
    } while (!hwnd);

    DWORD pid;
    GetWindowThreadProcessId(hwnd, &pid);
    process = OpenProcess(PROCESS_ALL_ACCESS, FALSE, pid);

    DWORD buffer = 0;
  
   while(true)
   { 
  
       if (GetKeyState(VK_SHIFT) & 0x8000) // button key for the process
       {
           buffer-=5;
           WriteProcessMemory(process, (LPVOID)(0x0EB37B3C - 4), &buffer, sizeof(buffer), 0); //write memory return buffer value
       }

     
      
       ReadProcessMemory(process, (LPVOID)(0x0EB37B3C - 4), &buffer, sizeof(buffer), 0); // read memory return buffer value
       cout << "Value: " << buffer << endl;

   Sleep(1);
   }
}

