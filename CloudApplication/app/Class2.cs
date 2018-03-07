using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using Newtonsoft.Json;

using uPLibrary.Networking.M2Mqtt;
using uPLibrary.Networking.M2Mqtt.Messages;

namespace WindowsFormsApp1
{

    class awsClient
    {
        static string username;
        static string password;
        static string brokerIP;
        static int port = 1883;
        static string topic = "test";
        private static string message = "";
        static MqttClient client;
        static string clientId;
        
        public static void setIP(string ip)
        { brokerIP = ip;}

        public static void setUsername(string name)
        { username = name;}

        public static void setPassword(string passw)
        { password = passw;}

        public static void setTopic(string t)
        { topic = t;}

        public static void setMessage(string msg)
        { message = msg;}
        
        public static void connect()
        {
            client = new MqttClient(brokerIP);
            clientId = Guid.NewGuid().ToString();
            client.Connect(clientId, username, password);
        }

        public static void sendMessage()
        {
            string msg = "{\"deviceid\":\"isasCSharpApp\",\"message\":\"" + message + "\"Timestamp\":\"" + DateTime.Now.ToString("h:mm:ss tt") + "\"}";
            client.Publish(topic, Encoding.UTF8.GetBytes(msg), MqttMsgBase.QOS_LEVEL_EXACTLY_ONCE, false); 
        }
    }
}
