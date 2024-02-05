#ifdef _WIN_PLATFORM_
#include <Windows.h>
int  wWinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance, _In_ LPWSTR lpCmdLine, _In_ int nShowCmd) {
#else
int main(int argc, char** argv){
#endif
	return 0;
}
