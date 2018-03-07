using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading.Tasks;
using System.Windows.Forms;
using Microsoft.Azure.Devices.Client;
using Microsoft.ServiceBus.Messaging;
using System.Threading;
using Newtonsoft.Json;
using static WindowsFormsApp1.AzureClient;
using Microsoft.Azure.Devices;
using Microsoft.Azure.Devices.Common.Exceptions;


namespace WindowsFormsApp1
{

    static class Program
    {
        
        public static Form1 form1 = new Form1();
        /// <summary>
        /// The main entry point for the application.
        /// </summary>
        [STAThread]

        static void Main()
        {
            Application.EnableVisualStyles();
            
            //Application.SetCompatibleTextRenderingDefault(false);
            Application.Run(form1);
            
        }
        
    }

}
