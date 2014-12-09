using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.Runtime.InteropServices;

namespace AppDllUser
{
    [StructLayout(LayoutKind.Sequential,CharSet=CharSet.Ansi)]
    public struct PROJECT_INFO
    {
        public UInt32 ulPrjID;
        public double dVersion;
        [MarshalAs(UnmanagedType.ByValTStr, SizeConst = 20)]
        public string szPrjName;
    };

    public struct PRJ_TABLE
    {
        public int nPrjIndex;
        [MarshalAs(UnmanagedType.ByValArray, SizeConst = 3)]
        public PROJECT_INFO[] stPrj;
    };

    public struct SERIALIZED_BUF
    {
        [MarshalAs(UnmanagedType.ByValTStr,SizeConst=128)]
        public string strContent;
    }

    public class CallDll
    {
        [DllImport("SerializeDll.dll", EntryPoint = "Serialize", CallingConvention = CallingConvention.Cdecl)]
        public static extern void Serialize(ref PRJ_TABLE stPrjTbl, Byte[] stBuf, int nBuffSize);

        [DllImport("SerializeDll.dll", EntryPoint = "Deserialize", CallingConvention = CallingConvention.Cdecl)]
        public static extern void Deserialize(ref PRJ_TABLE stPrjTbl, Byte[] strContent);
    };

    static class Program
    {
        /// <summary>
        /// 应用程序的主入口点。
        /// </summary>
        [STAThread]
        static void Main()
        {
            Application.EnableVisualStyles();
            Application.SetCompatibleTextRenderingDefault(false);
            Application.Run(new Form1());

            PRJ_TABLE stPrjTbl = new PRJ_TABLE();
            stPrjTbl.nPrjIndex = 1;
            stPrjTbl.stPrj = new PROJECT_INFO[3];
            stPrjTbl.stPrj[0].ulPrjID = 1;
            stPrjTbl.stPrj[0].dVersion = 10.1;
            stPrjTbl.stPrj[0].szPrjName = "Prj1";

            stPrjTbl.stPrj[1].ulPrjID = 2;
            stPrjTbl.stPrj[1].dVersion = 10.2;
            stPrjTbl.stPrj[1].szPrjName = "Prj2";

            SERIALIZED_BUF stBUF = new SERIALIZED_BUF();
            Byte[] stBuf = new Byte[512];

            //将C#中的结构体序列化
            CallDll.Serialize(ref stPrjTbl, stBuf, 512);

            //将序列化后的内容，反序列化为C#中的结构体
            PRJ_TABLE stPrjTblOut = new PRJ_TABLE();
            CallDll.Deserialize(ref stPrjTblOut, stBuf);
        }
    }
}
