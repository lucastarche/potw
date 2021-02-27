# FezzBozz

### Building

Building requires .NET 5 SDK or .NET Framework 4.7.2 SDK.  Artifacts are written to `bin/Debug`.

* Run immediately through .NET 5: `dotnet run -f net5.0 [project path] [--] [args]`
* Build .NET 5: `dotnet build -f net5.0 [project path]`
* Build .NET Framework 4.7,2 (through `dotnet` from .NET 5 SDK): `dotnet build -f net472 [project path]`
* Build .NET Framework 4.7.2 (through MSBuild): `path/to/msbuild.exe [project path]`
