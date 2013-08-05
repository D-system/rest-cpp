:clean solution
"C:\Program Files (x86)\Microsoft Visual Studio 11.0\Common7\IDE\devenv.exe" myrestsql2.sln /Clean

:build solution
C:\Windows\Microsoft.NET\Framework64\v4.0.30319\MSBuild.exe myrestsql2.sln
:/property:Configuration=Release

:make directory
mkdir C:\myrestsql

:copy exe
copy Debug\myrestsql2.exe C:\myrestsql\myrestsql.exe
