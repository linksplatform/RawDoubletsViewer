//
// ЗАГОЛОВОК ОСНОВНОГО МОДУЛЯ: MAIN.CPP
//
// ОПИСАНИЕ: содержит прототипы функций модуля
//

#ifndef main_h_
#define main_h_

#define LV_ItemClick 1
#define LV_StateClick -1

int  APIENTRY    _tWinMain(HINSTANCE, HINSTANCE, LPTSTR, int);
ATOM             RegisterWndClass();
HWND             InitWnd(); //
bool             InitListView(HWND);
bool             InitStatusBar(HWND);
LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);
void             RefreshWindow(HWND hWnd);
LPTSTR           OpenFileDialog(LPTSTR, LPCTSTR, HWND);

#endif
