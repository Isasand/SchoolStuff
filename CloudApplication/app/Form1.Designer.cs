namespace WindowsFormsApp1
{
    partial class Form1
    {
        /// <summary>
        /// Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Clean up any resources being used.
        /// </summary>
        /// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        /// <summary>
        /// Required method for Designer support - do not modify
        /// the contents of this method with the code editor.
        /// </summary>
        public void InitializeComponent()
        {
            System.ComponentModel.ComponentResourceManager resources = new System.ComponentModel.ComponentResourceManager(typeof(Form1));
            this.button1 = new System.Windows.Forms.Button();
            this.button2 = new System.Windows.Forms.Button();
            this.backButton = new System.Windows.Forms.Button();
            this.uriTextBox = new System.Windows.Forms.TextBox();
            this.deviceIDBox = new System.Windows.Forms.TextBox();
            this.deviceKeyBox = new System.Windows.Forms.TextBox();
            this.messageBox = new System.Windows.Forms.TextBox();
            this.keyText = new System.Windows.Forms.Label();
            this.sendAzure = new System.Windows.Forms.Button();
            this.deviceIDText = new System.Windows.Forms.Label();
            this.iotHubUriText = new System.Windows.Forms.Label();
            this.messageText = new System.Windows.Forms.Label();
            this.brokerIPBox = new System.Windows.Forms.TextBox();
            this.brokerIPText = new System.Windows.Forms.Label();
            this.usernameText = new System.Windows.Forms.Label();
            this.passwordText = new System.Windows.Forms.Label();
            this.topicText = new System.Windows.Forms.Label();
            this.aws_messageText = new System.Windows.Forms.Label();
            this.usernameBox = new System.Windows.Forms.TextBox();
            this.passwordBox = new System.Windows.Forms.TextBox();
            this.topicBox = new System.Windows.Forms.TextBox();
            this.aws_messageBox = new System.Windows.Forms.TextBox();
            this.aws_send = new System.Windows.Forms.Button();
            this.pictureBox1 = new System.Windows.Forms.PictureBox();
            this.pictureBox2 = new System.Windows.Forms.PictureBox();
            this.pictureBox3 = new System.Windows.Forms.PictureBox();
            this.pictureBox4 = new System.Windows.Forms.PictureBox();
            this.rainButton = new System.Windows.Forms.Button();
            this.yesBox = new System.Windows.Forms.PictureBox();
            this.noBox = new System.Windows.Forms.PictureBox();
            ((System.ComponentModel.ISupportInitialize)(this.pictureBox1)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.pictureBox2)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.pictureBox3)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.pictureBox4)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.yesBox)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.noBox)).BeginInit();
            this.SuspendLayout();
            // 
            // button1
            // 
            this.button1.BackColor = System.Drawing.SystemColors.GradientActiveCaption;
            this.button1.FlatStyle = System.Windows.Forms.FlatStyle.Popup;
            this.button1.Location = new System.Drawing.Point(400, 300);
            this.button1.Name = "button1";
            this.button1.Size = new System.Drawing.Size(75, 23);
            this.button1.TabIndex = 0;
            this.button1.Text = "Connect";
            this.button1.UseVisualStyleBackColor = false;
            this.button1.Click += new System.EventHandler(this.button1_Click);
            // 
            // button2
            // 
            this.button2.BackColor = System.Drawing.SystemColors.GradientActiveCaption;
            this.button2.FlatStyle = System.Windows.Forms.FlatStyle.Popup;
            this.button2.Location = new System.Drawing.Point(109, 300);
            this.button2.Name = "button2";
            this.button2.Size = new System.Drawing.Size(75, 23);
            this.button2.TabIndex = 1;
            this.button2.Text = "Connect";
            this.button2.UseVisualStyleBackColor = false;
            this.button2.Click += new System.EventHandler(this.button2_Click);
            // 
            // backButton
            // 
            this.backButton.Location = new System.Drawing.Point(5, 0);
            this.backButton.Name = "backButton";
            this.backButton.Size = new System.Drawing.Size(75, 23);
            this.backButton.TabIndex = 2;
            this.backButton.Text = "Back";
            this.backButton.UseVisualStyleBackColor = true;
            this.backButton.Click += new System.EventHandler(this.back_Click);
            // 
            // uriTextBox
            // 
            this.uriTextBox.Location = new System.Drawing.Point(100, 295);
            this.uriTextBox.Name = "uriTextBox";
            this.uriTextBox.Size = new System.Drawing.Size(200, 20);
            this.uriTextBox.TabIndex = 0;
            this.uriTextBox.Text = "isaSandTestHub.azure-devices.net";
            // 
            // deviceIDBox
            // 
            this.deviceIDBox.Location = new System.Drawing.Point(100, 270);
            this.deviceIDBox.Name = "deviceIDBox";
            this.deviceIDBox.Size = new System.Drawing.Size(100, 20);
            this.deviceIDBox.TabIndex = 1;
            this.deviceIDBox.Text = "myFirstDevice";
            // 
            // deviceKeyBox
            // 
            this.deviceKeyBox.Location = new System.Drawing.Point(390, 275);
            this.deviceKeyBox.Name = "deviceKeyBox";
            this.deviceKeyBox.Size = new System.Drawing.Size(100, 20);
            this.deviceKeyBox.TabIndex = 2;
            this.deviceKeyBox.Text = "rsI2NEnci8O4Y+Sv+NyzptURRmellNdR8mBUGuSuKds=";
            // 
            // messageBox
            // 
            this.messageBox.Location = new System.Drawing.Point(100, 320);
            this.messageBox.Name = "messageBox";
            this.messageBox.Size = new System.Drawing.Size(200, 20);
            this.messageBox.TabIndex = 3;
            this.messageBox.Text = "messagebox";
            // 
            // keyText
            // 
            this.keyText.AutoSize = true;
            this.keyText.BackColor = System.Drawing.Color.Transparent;
            this.keyText.Location = new System.Drawing.Point(405, 258);
            this.keyText.Name = "keyText";
            this.keyText.Size = new System.Drawing.Size(62, 13);
            this.keyText.TabIndex = 2;
            this.keyText.Text = "Device Key";
            // 
            // sendAzure
            // 
            this.sendAzure.Location = new System.Drawing.Point(100, 345);
            this.sendAzure.Name = "sendAzure";
            this.sendAzure.Size = new System.Drawing.Size(75, 23);
            this.sendAzure.TabIndex = 2;
            this.sendAzure.Text = "Send";
            this.sendAzure.UseVisualStyleBackColor = true;
            this.sendAzure.Click += new System.EventHandler(this.sendAzure_Click);
            // 
            // deviceIDText
            // 
            this.deviceIDText.AutoSize = true;
            this.deviceIDText.Location = new System.Drawing.Point(10, 270);
            this.deviceIDText.Name = "deviceIDText";
            this.deviceIDText.Size = new System.Drawing.Size(35, 13);
            this.deviceIDText.TabIndex = 3;
            this.deviceIDText.Text = "Device ID";
            // 
            // iotHubUriText
            // 
            this.iotHubUriText.AutoSize = true;
            this.iotHubUriText.Location = new System.Drawing.Point(10, 295);
            this.iotHubUriText.Name = "iotHubUriText";
            this.iotHubUriText.Size = new System.Drawing.Size(35, 13);
            this.iotHubUriText.TabIndex = 4;
            this.iotHubUriText.Text = "IoT Hub Uri";
            // 
            // messageText
            // 
            this.messageText.AutoSize = true;
            this.messageText.Location = new System.Drawing.Point(10, 320);
            this.messageText.Name = "messageText";
            this.messageText.Size = new System.Drawing.Size(35, 13);
            this.messageText.TabIndex = 0;
            this.messageText.Text = "Message";
            // 
            // brokerIPBox
            // 
            this.brokerIPBox.Location = new System.Drawing.Point(97, 275);
            this.brokerIPBox.Name = "brokerIPBox";
            this.brokerIPBox.Size = new System.Drawing.Size(100, 20);
            this.brokerIPBox.TabIndex = 4;
            // 
            // brokerIPText
            // 
            this.brokerIPText.AutoSize = true;
            this.brokerIPText.BackColor = System.Drawing.Color.Transparent;
            this.brokerIPText.Location = new System.Drawing.Point(106, 258);
            this.brokerIPText.Name = "brokerIPText";
            this.brokerIPText.Size = new System.Drawing.Size(77, 13);
            this.brokerIPText.TabIndex = 5;
            this.brokerIPText.Text = "AWS bridge IP";
            // 
            // usernameText
            // 
            this.usernameText.AutoSize = true;
            this.usernameText.Location = new System.Drawing.Point(10, 270);
            this.usernameText.Name = "usernameText";
            this.usernameText.Size = new System.Drawing.Size(51, 13);
            this.usernameText.TabIndex = 0;
            this.usernameText.Text = "Username";
            // 
            // passwordText
            // 
            this.passwordText.AutoSize = true;
            this.passwordText.Location = new System.Drawing.Point(10, 290);
            this.passwordText.Name = "passwordText";
            this.passwordText.Size = new System.Drawing.Size(51, 13);
            this.passwordText.TabIndex = 0;
            this.passwordText.Text = "Password";
            // 
            // topicText
            // 
            this.topicText.AutoSize = true;
            this.topicText.Location = new System.Drawing.Point(10, 310);
            this.topicText.Name = "topicText";
            this.topicText.Size = new System.Drawing.Size(51, 13);
            this.topicText.TabIndex = 0;
            this.topicText.Text = "Topic";
            // 
            // aws_messageText
            // 
            this.aws_messageText.AutoSize = true;
            this.aws_messageText.Location = new System.Drawing.Point(10, 330);
            this.aws_messageText.Name = "aws_messageText";
            this.aws_messageText.Size = new System.Drawing.Size(51, 13);
            this.aws_messageText.TabIndex = 0;
            this.aws_messageText.Text = "Message";
            // 
            // usernameBox
            // 
            this.usernameBox.Location = new System.Drawing.Point(100, 270);
            this.usernameBox.Name = "usernameBox";
            this.usernameBox.Size = new System.Drawing.Size(100, 20);
            this.usernameBox.TabIndex = 1;
            // 
            // passwordBox
            // 
            this.passwordBox.Location = new System.Drawing.Point(100, 290);
            this.passwordBox.Name = "passwordBox";
            this.passwordBox.Size = new System.Drawing.Size(100, 20);
            this.passwordBox.TabIndex = 2;
            // 
            // topicBox
            // 
            this.topicBox.Location = new System.Drawing.Point(100, 310);
            this.topicBox.Name = "topicBox";
            this.topicBox.Size = new System.Drawing.Size(100, 20);
            this.topicBox.TabIndex = 3;
            // 
            // aws_messageBox
            // 
            this.aws_messageBox.Location = new System.Drawing.Point(100, 330);
            this.aws_messageBox.Name = "aws_messageBox";
            this.aws_messageBox.Size = new System.Drawing.Size(100, 20);
            this.aws_messageBox.TabIndex = 4;
            // 
            // aws_send
            // 
            this.aws_send.Location = new System.Drawing.Point(100, 350);
            this.aws_send.Name = "aws_send";
            this.aws_send.Size = new System.Drawing.Size(100, 20);
            this.aws_send.TabIndex = 5;
            this.aws_send.Text = "Send";
            this.aws_send.UseVisualStyleBackColor = true;
            this.aws_send.Click += new System.EventHandler(this.aws_sendClick);
            // 
            // pictureBox1
            // 
            this.pictureBox1.BackColor = System.Drawing.Color.Transparent;
            this.pictureBox1.Image = global::WindowsFormsApp1.Properties.Resources.icon_cloud_aws;
            this.pictureBox1.Location = new System.Drawing.Point(45, 70);
            this.pictureBox1.Name = "pictureBox1";
            this.pictureBox1.Size = new System.Drawing.Size(230, 146);
            this.pictureBox1.SizeMode = System.Windows.Forms.PictureBoxSizeMode.StretchImage;
            this.pictureBox1.TabIndex = 2;
            this.pictureBox1.TabStop = false;
            // 
            // pictureBox2
            // 
            this.pictureBox2.BackColor = System.Drawing.Color.Transparent;
            this.pictureBox2.Image = global::WindowsFormsApp1.Properties.Resources.main_qimg_1fe92f769db92a3db864bccd1167e2cb;
            this.pictureBox2.Location = new System.Drawing.Point(322, 70);
            this.pictureBox2.Name = "pictureBox2";
            this.pictureBox2.Size = new System.Drawing.Size(223, 137);
            this.pictureBox2.SizeMode = System.Windows.Forms.PictureBoxSizeMode.StretchImage;
            this.pictureBox2.TabIndex = 3;
            this.pictureBox2.TabStop = false;
            // 
            // pictureBox3
            // 
            this.pictureBox3.Image = global::WindowsFormsApp1.Properties.Resources.az;
            this.pictureBox3.Location = new System.Drawing.Point(83, -4);
            this.pictureBox3.Name = "pictureBox3";
            this.pictureBox3.Size = new System.Drawing.Size(420, 259);
            this.pictureBox3.SizeMode = System.Windows.Forms.PictureBoxSizeMode.StretchImage;
            this.pictureBox3.TabIndex = 4;
            this.pictureBox3.TabStop = false;
            // 
            // pictureBox4
            // 
            this.pictureBox4.Image = global::WindowsFormsApp1.Properties.Resources._2000px_AmazonWebservices_Logo_svg;
            this.pictureBox4.Location = new System.Drawing.Point(64, 31);
            this.pictureBox4.Name = "pictureBox4";
            this.pictureBox4.Size = new System.Drawing.Size(448, 196);
            this.pictureBox4.SizeMode = System.Windows.Forms.PictureBoxSizeMode.StretchImage;
            this.pictureBox4.TabIndex = 6;
            this.pictureBox4.TabStop = false;
            // 
            // rainButton
            // 
            this.rainButton.Location = new System.Drawing.Point(373, 258);
            this.rainButton.Name = "rainButton";
            this.rainButton.Size = new System.Drawing.Size(146, 34);
            this.rainButton.TabIndex = 6;
            this.rainButton.Text = "Will it rain?";
            this.rainButton.UseVisualStyleBackColor = true;
            this.rainButton.Click += new System.EventHandler(this.button3_Click);
            // 
            // yesBox
            // 
            this.yesBox.BackgroundImageLayout = System.Windows.Forms.ImageLayout.None;
            this.yesBox.Image = ((System.Drawing.Image)(resources.GetObject("yesBox.Image")));
            this.yesBox.Location = new System.Drawing.Point(350, 300);
            this.yesBox.Name = "yesBox";
            this.yesBox.Size = new System.Drawing.Size(179, 72);
            this.yesBox.TabIndex = 6;
            this.yesBox.TabStop = false;
            // 
            // pictureBox5
            // 
            this.noBox.BackgroundImage = ((System.Drawing.Image)(resources.GetObject("pictureBox5.BackgroundImage")));
            this.noBox.Location = new System.Drawing.Point(373, 300);
            this.noBox.Name = "pictureBox5";
            this.noBox.Size = new System.Drawing.Size(132, 92);
            this.noBox.TabIndex = 6;
            this.noBox.TabStop = false;
            // 
            // Form1
            // 
            this.BackColor = System.Drawing.SystemColors.GradientActiveCaption;
            this.BackgroundImageLayout = System.Windows.Forms.ImageLayout.Center;
            this.ClientSize = new System.Drawing.Size(592, 415);
           
            this.Controls.Add(this.brokerIPText);
            this.Controls.Add(this.brokerIPBox);
            this.Controls.Add(this.pictureBox1);
            this.Controls.Add(this.pictureBox2);
            this.Controls.Add(this.button2);
            this.Controls.Add(this.button1);
            this.Controls.Add(this.keyText);
            this.Controls.Add(this.deviceKeyBox);
            this.ForeColor = System.Drawing.SystemColors.ControlText;
            this.FormBorderStyle = System.Windows.Forms.FormBorderStyle.Fixed3D;
            this.Name = "Form1";
            ((System.ComponentModel.ISupportInitialize)(this.pictureBox1)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.pictureBox2)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.pictureBox3)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.pictureBox4)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.yesBox)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.noBox)).EndInit();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        public string getUriText()
        {
            return uriTextBox.Text;
        }

        public string getDeviceKeytext()
        {
            return  deviceKeyBox.Text;
        }

        public string getDeviceIDText()
        {
            return deviceIDBox.Text;
        }
        public string getMsg()
        {
            return messageBox.Text;
        }

        public string getBrokerIP()
        {
            return brokerIPBox.Text;
        }

        public string getUsername()
        {
            return usernameBox.Text; 
        }

        public string getPassword()
        {
            return passwordBox.Text; 
        }

        public string getTopic()
        {
            return topicBox.Text; 
        }

        public string getMessage()
        {
            return aws_messageBox.Text; 
        }
        
        private System.Windows.Forms.Button button1;
        private System.Windows.Forms.Button button2;
        private System.Windows.Forms.Button backButton;
        private System.Windows.Forms.TextBox deviceKeyBox;
        private System.Windows.Forms.PictureBox pictureBox1;
        private System.Windows.Forms.Label keyText;
        private System.Windows.Forms.Label deviceIDText;
        private System.Windows.Forms.Label iotHubUriText;
        private System.Windows.Forms.Label messageText;
        private System.Windows.Forms.Button sendAzure;
        private System.Windows.Forms.PictureBox pictureBox2;
        private System.Windows.Forms.PictureBox pictureBox3;
        private System.Windows.Forms.TextBox uriTextBox;
        private System.Windows.Forms.TextBox deviceIDBox;
        private System.Windows.Forms.TextBox messageBox;
        private System.Windows.Forms.TextBox brokerIPBox;
        private System.Windows.Forms.Label brokerIPText;
        private System.Windows.Forms.PictureBox pictureBox4;
        private System.Windows.Forms.Label usernameText;
        private System.Windows.Forms.Label passwordText;
        private System.Windows.Forms.Label topicText;
        private System.Windows.Forms.Label aws_messageText;
        private System.Windows.Forms.TextBox usernameBox;
        private System.Windows.Forms.TextBox passwordBox;
        private System.Windows.Forms.TextBox topicBox;
        private System.Windows.Forms.TextBox aws_messageBox;
        private System.Windows.Forms.Button aws_send;
        private System.Windows.Forms.Button rainButton;
        private System.Windows.Forms.PictureBox yesBox;
        private System.Windows.Forms.PictureBox noBox;
    }
}

