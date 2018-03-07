using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using static WindowsFormsApp1.AzureClient;
using static WindowsFormsApp1.awsClient;


namespace WindowsFormsApp1
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void button1_Click(object sender, EventArgs e)
        {
            azurePage();
            ReadFromBlob();
        }

        private void button2_Click(object sender, EventArgs e)
        {
            awsClient.setIP(Program.form1.getBrokerIP());
            awsPage();
        }

        private void back_Click(object sender, EventArgs e)
        {
            this.Controls.Clear();
            startPage();
        }

        private void aws_sendClick(object sender, EventArgs e)
        {
            awsClient.setUsername(Program.form1.getUsername());
            awsClient.setPassword(Program.form1.getPassword());
            awsClient.setTopic(Program.form1.getTopic());
            awsClient.setMessage(Program.form1.getMessage());
            awsClient.connect();
            awsClient.sendMessage();
        }

        private void startPage()
        {
            this.Controls.Add(this.button1);
            this.Controls.Add(this.button2);
            this.Controls.Add(this.pictureBox1);
            this.Controls.Add(this.pictureBox2);
            this.Controls.Add(this.keyText);
            this.Controls.Add(this.deviceKeyBox);
            this.Controls.Add(this.brokerIPText);
            this.Controls.Add(this.brokerIPBox);
        }

        private void azurePage()
        {
            this.Controls.Clear();
            this.Controls.Add(this.pictureBox3);
            this.Controls.Add(this.backButton);
            this.Controls.Add(uriTextBox);
            this.Controls.Add(deviceIDBox);
            this.Controls.Add(messageBox);
            this.Controls.Add(deviceIDText);
            this.Controls.Add(sendAzure);
            this.Controls.Add(iotHubUriText);
            this.Controls.Add(messageText);
            this.Controls.Add(this.rainButton);
           
        }

        private void awsPage()
        {
            Controls.Clear();
            Controls.Add(this.pictureBox4);
            Controls.Add(backButton);
            Controls.Add(aws_messageText);
            Controls.Add(usernameBox);
            Controls.Add(passwordBox);
            Controls.Add(usernameText);
            Controls.Add(passwordText);
            
            Controls.Add(topicText);
            Controls.Add(topicBox);
            Controls.Add(aws_messageBox);
            Controls.Add(aws_send);
        }
        private void sendAzure_Click(object sender, EventArgs e)
        {
            AzureClient.SendD2CMessagesAsync();
        }

        private void button3_Click(object sender, EventArgs e)
        {
            if (AzureClient.probForRain)
            {
                this.Controls.Add(this.yesBox);
            }
            else
            {
                this.Controls.Add(this.noBox);
            }
        }
    }
}
