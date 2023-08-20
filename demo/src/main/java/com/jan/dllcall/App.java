package com.jan.dllcall;

import com.sun.jna.Library;
import com.sun.jna.Native;
import com.sun.jna.Pointer;
import com.sun.jna.Platform;


/**
 * Hello world!
 *
 */
public class App
{
    public static String DLL = "D:\\Repo\\JavaCallDLL\\cpp\\x64\\Release\\cpp.dll";
    public static String C_STD_DLL = Platform.isWindows()? "msvcrt": "c";
    public interface CLibrary extends Library
    {
        CLibrary INSTANCE = Native.load(C_STD_DLL, CLibrary.class);
        void printf(String format, Object...args);
    }

    public interface DLLLibrary extends Library
    {
        DLLLibrary INSTANCE = Native.load(DLL, DLLLibrary.class);
        Pointer CreateObject();
        int AddBaudRate(Pointer self, int a);
        String SetName(Pointer self, String name);
    }

    public static void main( String[] args )
    {
        System.out.println( "Hello Java!" );
        CLibrary.INSTANCE.printf("Hello %s!\n", "C");

        Pointer obj = DLLLibrary.INSTANCE.CreateObject();
        System.out.println(DLLLibrary.INSTANCE.AddBaudRate(obj, 33));
        System.out.println(DLLLibrary.INSTANCE.SetName(obj, "Test String"));
    }
}
