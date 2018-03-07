using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using Microsoft.Azure.Devices.Client;
using Newtonsoft.Json;
using static WindowsFormsApp1.Form1;
using Microsoft.WindowsAzure; 
using Microsoft.WindowsAzure.Storage; 
using Microsoft.WindowsAzure.Storage.Blob; 
using System.Globalization;

namespace WindowsFormsApp1
{
    
    class AzureClient
    {
        
        static string iotHubUri = "";
        static string deviceKey = "";
        static string device_Id = "";
        public static bool probForRain;
        static DeviceClient deviceClient;
        
        public static string getIoTHubUri() {return iotHubUri; }
        public static void setIoTHubri(string argumentedUri) { iotHubUri = argumentedUri; }
        public static void ReadFromBlob()
        {
            string connectionString = "";
            CloudStorageAccount storageAccount = CloudStorageAccount.Parse(connectionString);

            CloudBlobClient blobClient = storageAccount.CreateCloudBlobClient();

            CloudBlobContainer container = blobClient.GetContainerReference("mlcontainer");

            CloudBlockBlob blockBlob = container.GetBlockBlobReference("mlfile.csv");
           
            string text;
            using (var memoryStream = new MemoryStream())
            {
                blockBlob.DownloadToStream(memoryStream);
                text = System.Text.Encoding.UTF8.GetString(memoryStream.ToArray());
            }
            
            List<string> variables = text.Split(',').ToList<string>();
            string probability = variables.Last();
            probability = probability.Substring(0, 3);
            float prob = float.Parse(probability, CultureInfo.InvariantCulture);
            
            if (prob > 0.5)
            {
                probForRain = true;
            }
            else
            {
                probForRain = false;
            }
        }
        
        public static async void SendD2CMessagesAsync()
        {
            device_Id = Program.form1.getDeviceIDText();
            int messageId = 1;
            iotHubUri = Program.form1.getUriText();
            deviceKey = Program.form1.getDeviceKeytext();
            byte[] textAsBytes = System.Text.Encoding.UTF8.GetBytes(deviceKey);
            string key = Convert.ToBase64String(textAsBytes);
            deviceClient = DeviceClient.Create(iotHubUri, new DeviceAuthenticationWithRegistrySymmetricKey("myFirstDevice", deviceKey), TransportType.Mqtt);
            
            deviceClient.ProductInfo = "isas_cSharpApplication";
            var telemetryDataPoint = new
            {
                messageId = messageId++,
                deviceId = device_Id,
                messageContent = Program.form1.getMsg()
            };

            
            var messageString = JsonConvert.SerializeObject(telemetryDataPoint);
            var message = new Message(Encoding.ASCII.GetBytes(messageString));
            message.Properties.Add("sender", "isas_cSharpApplication");
            
            await deviceClient.SendEventAsync(message);
            //Console.WriteLine("{0} > Sending message: {1}", DateTime.Now, messageString);

            await Task.Delay(1000);
        }
        
    }
}
