#include <Windows.h>
#include <tchar.h>
#include <stdio.h>
#include <strsafe.h>


int main()
{
	HANDLE hFile;
	char DataBuffer[] = "This is some test data to write to the file.";
	DWORD dwBytesToWrite = (DWORD)strlen(DataBuffer);
	DWORD dwBytesWritten = 0;
	BOOL bErrorFlag = FALSE;
	// Expected to tell "Hooked!".
	MessageBoxW(NULL, L"Not hooked...", L"MinHook Sample", MB_OK);

	hFile = CreateFileW(L"C:\\Users\\aviad\\Documents\\test\\HidingDLL.dll",                // name of the write
		GENERIC_WRITE,          // open for writing
		0,                      // do not share
		NULL,                   // default security
		OPEN_EXISTING,             // create new file only
		FILE_ATTRIBUTE_NORMAL,  // normal file
		NULL);                  // no attr. template

	if (hFile == INVALID_HANDLE_VALUE)
	{
		_tprintf(TEXT("Terminal failure: Unable to open file for write.\n"));
		Sleep(2000);
	}
	else
	{
		_tprintf(TEXT("file found!!.\n"));
		Sleep(2000);
	}
	return 0;
}