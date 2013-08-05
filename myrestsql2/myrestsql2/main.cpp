
#include <boost/bind.hpp>
#include <boost/asio.hpp>
#include "socket_listener.hpp"

void restsql () {
  try {
    boost::asio::io_service io;
    listener(io);
  } catch (std::exception& e) {
    std::cerr << "Exception: " << e.what() << std::endl;
  }
}


#ifdef _WIN32


# include <Windows.h>
# include <tchar.h>
# define SERVICE_NAME  _T("MyRESTSQL")

SERVICE_STATUS        g_ServiceStatus = {0};
SERVICE_STATUS_HANDLE g_StatusHandle = NULL;
HANDLE                g_ServiceStopEvent = INVALID_HANDLE_VALUE;
HANDLE		      hThread = INVALID_HANDLE_VALUE;

VOID WINAPI ServiceMain (DWORD argc, LPTSTR *argv);
VOID WINAPI ServiceCtrlHandler (DWORD);
DWORD WINAPI ServiceWorkerThread (LPVOID lpParam);

int _tmain (int argc, TCHAR *argv[])
{
    SERVICE_TABLE_ENTRY ServiceTable[] = 
    {
        {SERVICE_NAME, (LPSERVICE_MAIN_FUNCTION) ServiceMain},
        {NULL, NULL}
    };

    if (StartServiceCtrlDispatcher (ServiceTable) == FALSE)
    {
       return GetLastError ();
    }
    return 0;
}


VOID WINAPI ServiceMain (DWORD argc, LPTSTR *argv)
{
  DWORD Status = E_FAIL;

  g_StatusHandle = RegisterServiceCtrlHandler (SERVICE_NAME, ServiceCtrlHandler);

  if (g_StatusHandle == NULL) 
    return ;

  // Tell the service controller we are starting
  ZeroMemory (&g_ServiceStatus, sizeof (g_ServiceStatus));
  g_ServiceStatus.dwServiceType = SERVICE_WIN32_OWN_PROCESS;
  g_ServiceStatus.dwControlsAccepted = 0;
  g_ServiceStatus.dwCurrentState = SERVICE_START_PENDING;
  g_ServiceStatus.dwWin32ExitCode = 0;
  g_ServiceStatus.dwServiceSpecificExitCode = 0;
  g_ServiceStatus.dwCheckPoint = 0;

  if (SetServiceStatus (g_StatusHandle, &g_ServiceStatus) == FALSE) 
    OutputDebugString(_T("MyRESTSQL: ServiceMain: SetServiceStatus returned error"));

  /* 
   * Perform tasks neccesary to start the service here
   */
  // Create stop event to wait on later.
  g_ServiceStopEvent = CreateEvent (NULL, TRUE, FALSE, NULL);
  if (g_ServiceStopEvent == NULL) 
    {
      g_ServiceStatus.dwControlsAccepted = 0;
      g_ServiceStatus.dwCurrentState = SERVICE_STOPPED;
      g_ServiceStatus.dwWin32ExitCode = GetLastError();
      g_ServiceStatus.dwCheckPoint = 1;

      if (SetServiceStatus (g_StatusHandle, &g_ServiceStatus) == FALSE)
	OutputDebugString(_T("MyRESTSQL: ServiceMain: SetServiceStatus returned error"));
      return ;
    }    

  // Tell the service controller we are started
  g_ServiceStatus.dwControlsAccepted = SERVICE_ACCEPT_STOP;
  g_ServiceStatus.dwCurrentState = SERVICE_RUNNING;
  g_ServiceStatus.dwWin32ExitCode = 0;
  g_ServiceStatus.dwCheckPoint = 0;

  if (SetServiceStatus (g_StatusHandle, &g_ServiceStatus) == FALSE)
    OutputDebugString(_T("MyRESTSQL: ServiceMain: SetServiceStatus returned error"));

  // Start the thread that will perform the main task of the service
  hThread = CreateThread (NULL, 0, ServiceWorkerThread, NULL, 0, NULL);

  // Wait until our worker thread exits effectively signaling that the service needs to stop
  WaitForSingleObject (hThread, INFINITE);
    
  /* 
   * Perform any cleanup tasks
   */
  CloseHandle (g_ServiceStopEvent);

  g_ServiceStatus.dwControlsAccepted = 0;
  g_ServiceStatus.dwCurrentState = SERVICE_STOPPED;
  g_ServiceStatus.dwWin32ExitCode = 0;
  g_ServiceStatus.dwCheckPoint = 3;

  if (SetServiceStatus (g_StatusHandle, &g_ServiceStatus) == FALSE)
    OutputDebugString(_T("MyRESTSQL: ServiceMain: SetServiceStatus returned error"));
}


VOID WINAPI ServiceCtrlHandler (DWORD CtrlCode)
{
  switch (CtrlCode) 
    {
    case SERVICE_CONTROL_STOP :

      OutputDebugString(_T("My Sample Service: ServiceCtrlHandler: SERVICE_CONTROL_STOP Request"));

      if (g_ServiceStatus.dwCurrentState != SERVICE_RUNNING)
	break;

      /* 
       * Perform tasks neccesary to stop the service here 
       */
      TerminateThread(hThread, 0);
      CloseHandle(hThread);
      g_ServiceStatus.dwControlsAccepted = 0;
      g_ServiceStatus.dwCurrentState = SERVICE_STOP_PENDING;
      g_ServiceStatus.dwWin32ExitCode = 0;
      g_ServiceStatus.dwCheckPoint = 4;

      if (SetServiceStatus (g_StatusHandle, &g_ServiceStatus) == FALSE)
	OutputDebugString(_T("My Sample Service: ServiceCtrlHandler: SetServiceStatus returned error"));

      // This will signal the worker thread to start shutting down
      SetEvent (g_ServiceStopEvent);

      break;

    default:
      break;
    }

}


DWORD WINAPI ServiceWorkerThread (LPVOID lpParam)
{
  while (WaitForSingleObject(g_ServiceStopEvent, 0) != WAIT_OBJECT_0) {        
    restsql();
  }

  return ERROR_SUCCESS;
}


#else

int	main(int argc, char** argv)
{
  restsql();
  return (0);
}

#endif
