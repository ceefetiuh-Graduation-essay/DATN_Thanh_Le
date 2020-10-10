namespace Form_Mouse
{
    partial class Form_Mouse
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

        #region Windows Form Designer generated code

        /// <summary>
        /// Required method for Designer support - do not modify
        /// the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            System.ComponentModel.ComponentResourceManager resources = new System.ComponentModel.ComponentResourceManager(typeof(Form_Mouse));
            this.button_Close = new System.Windows.Forms.Button();
            this.button_Save = new System.Windows.Forms.Button();
            this.button_Draw = new System.Windows.Forms.Button();
            this.button_Clear = new System.Windows.Forms.Button();
            this.Button_DisConnect = new System.Windows.Forms.Button();
            this.Button_Connect = new System.Windows.Forms.Button();
            this.Display_X_Y = new System.Windows.Forms.ListBox();
            this.label1 = new System.Windows.Forms.Label();
            this.ComboBox_COMPort = new System.Windows.Forms.ComboBox();
            this.PictureBox_DoThi = new System.Windows.Forms.PictureBox();
            this.label_Lưu = new System.Windows.Forms.Label();
            this.groupBox1 = new System.Windows.Forms.GroupBox();
            this.label3 = new System.Windows.Forms.Label();
            this.label_Xóa = new System.Windows.Forms.Label();
            this.label_vẽ = new System.Windows.Forms.Label();
            this.label_connect = new System.Windows.Forms.Label();
            this.label_disconnect = new System.Windows.Forms.Label();
            this.label_thoát = new System.Windows.Forms.Label();
            this.groupBox2 = new System.Windows.Forms.GroupBox();
            this.textBox_Status = new System.Windows.Forms.TextBox();
            this.label2 = new System.Windows.Forms.Label();
            ((System.ComponentModel.ISupportInitialize)(this.PictureBox_DoThi)).BeginInit();
            this.groupBox1.SuspendLayout();
            this.groupBox2.SuspendLayout();
            this.SuspendLayout();
            // 
            // button_Close
            // 
            this.button_Close.BackColor = System.Drawing.Color.Transparent;
            this.button_Close.BackgroundImage = ((System.Drawing.Image)(resources.GetObject("button_Close.BackgroundImage")));
            this.button_Close.Font = new System.Drawing.Font("Microsoft Sans Serif", 9.75F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.button_Close.Location = new System.Drawing.Point(23, 420);
            this.button_Close.Name = "button_Close";
            this.button_Close.Size = new System.Drawing.Size(48, 49);
            this.button_Close.TabIndex = 71;
            this.button_Close.UseVisualStyleBackColor = false;
            this.button_Close.Click += new System.EventHandler(this.button_Close_Click);
            // 
            // button_Save
            // 
            this.button_Save.BackColor = System.Drawing.Color.Transparent;
            this.button_Save.Font = new System.Drawing.Font("Microsoft Sans Serif", 9.75F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.button_Save.Image = ((System.Drawing.Image)(resources.GetObject("button_Save.Image")));
            this.button_Save.Location = new System.Drawing.Point(9, 21);
            this.button_Save.Name = "button_Save";
            this.button_Save.Size = new System.Drawing.Size(57, 55);
            this.button_Save.TabIndex = 70;
            this.button_Save.UseVisualStyleBackColor = false;
            this.button_Save.Click += new System.EventHandler(this.button_Save_Click);
            // 
            // button_Draw
            // 
            this.button_Draw.BackColor = System.Drawing.Color.Transparent;
            this.button_Draw.Font = new System.Drawing.Font("Microsoft Sans Serif", 9.75F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.button_Draw.Image = ((System.Drawing.Image)(resources.GetObject("button_Draw.Image")));
            this.button_Draw.Location = new System.Drawing.Point(9, 83);
            this.button_Draw.Name = "button_Draw";
            this.button_Draw.Size = new System.Drawing.Size(57, 55);
            this.button_Draw.TabIndex = 68;
            this.button_Draw.UseVisualStyleBackColor = false;
            this.button_Draw.Click += new System.EventHandler(this.button_Draw_Click);
            // 
            // button_Clear
            // 
            this.button_Clear.BackColor = System.Drawing.Color.Transparent;
            this.button_Clear.Font = new System.Drawing.Font("Microsoft Sans Serif", 9.75F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.button_Clear.Image = ((System.Drawing.Image)(resources.GetObject("button_Clear.Image")));
            this.button_Clear.Location = new System.Drawing.Point(11, 144);
            this.button_Clear.Name = "button_Clear";
            this.button_Clear.Size = new System.Drawing.Size(57, 54);
            this.button_Clear.TabIndex = 67;
            this.button_Clear.UseVisualStyleBackColor = false;
            this.button_Clear.Click += new System.EventHandler(this.button_Clear_Click);
            // 
            // Button_DisConnect
            // 
            this.Button_DisConnect.BackColor = System.Drawing.Color.Transparent;
            this.Button_DisConnect.Font = new System.Drawing.Font("Microsoft Sans Serif", 9.75F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.Button_DisConnect.Image = ((System.Drawing.Image)(resources.GetObject("Button_DisConnect.Image")));
            this.Button_DisConnect.Location = new System.Drawing.Point(97, 53);
            this.Button_DisConnect.Name = "Button_DisConnect";
            this.Button_DisConnect.Size = new System.Drawing.Size(51, 53);
            this.Button_DisConnect.TabIndex = 66;
            this.Button_DisConnect.UseVisualStyleBackColor = false;
            this.Button_DisConnect.Click += new System.EventHandler(this.Button_DisConnect_Click);
            // 
            // Button_Connect
            // 
            this.Button_Connect.BackColor = System.Drawing.Color.Transparent;
            this.Button_Connect.Cursor = System.Windows.Forms.Cursors.Default;
            this.Button_Connect.Font = new System.Drawing.Font("Microsoft Sans Serif", 9.75F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.Button_Connect.Image = ((System.Drawing.Image)(resources.GetObject("Button_Connect.Image")));
            this.Button_Connect.Location = new System.Drawing.Point(19, 53);
            this.Button_Connect.Name = "Button_Connect";
            this.Button_Connect.Size = new System.Drawing.Size(57, 53);
            this.Button_Connect.TabIndex = 65;
            this.Button_Connect.UseVisualStyleBackColor = false;
            this.Button_Connect.Click += new System.EventHandler(this.Button_Connect_Click);
            // 
            // Display_X_Y
            // 
            this.Display_X_Y.Font = new System.Drawing.Font("Microsoft Sans Serif", 9.75F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(163)));
            this.Display_X_Y.FormattingEnabled = true;
            this.Display_X_Y.ItemHeight = 16;
            this.Display_X_Y.Location = new System.Drawing.Point(151, 39);
            this.Display_X_Y.Name = "Display_X_Y";
            this.Display_X_Y.Size = new System.Drawing.Size(112, 164);
            this.Display_X_Y.TabIndex = 64;
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.BackColor = System.Drawing.Color.Transparent;
            this.label1.Font = new System.Drawing.Font("Times New Roman", 15.75F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(163)));
            this.label1.ForeColor = System.Drawing.Color.Red;
            this.label1.Location = new System.Drawing.Point(27, 9);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(249, 48);
            this.label1.TabIndex = 63;
            this.label1.Text = "GIAO TIẾP VÀ HIỂN THỊ\r\nTỌA ĐỘ ROBOT";
            this.label1.TextAlign = System.Drawing.ContentAlignment.MiddleCenter;
            // 
            // ComboBox_COMPort
            // 
            this.ComboBox_COMPort.BackColor = System.Drawing.SystemColors.ControlLightLight;
            this.ComboBox_COMPort.Font = new System.Drawing.Font("Microsoft Sans Serif", 8.25F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.ComboBox_COMPort.ForeColor = System.Drawing.Color.Black;
            this.ComboBox_COMPort.FormattingEnabled = true;
            this.ComboBox_COMPort.Location = new System.Drawing.Point(19, 26);
            this.ComboBox_COMPort.Name = "ComboBox_COMPort";
            this.ComboBox_COMPort.Size = new System.Drawing.Size(129, 21);
            this.ComboBox_COMPort.TabIndex = 61;
            this.ComboBox_COMPort.Text = "CHỌN CỔNG COM";
            // 
            // PictureBox_DoThi
            // 
            this.PictureBox_DoThi.BackColor = System.Drawing.Color.White;
            this.PictureBox_DoThi.BackgroundImage = ((System.Drawing.Image)(resources.GetObject("PictureBox_DoThi.BackgroundImage")));
            this.PictureBox_DoThi.Location = new System.Drawing.Point(287, 12);
            this.PictureBox_DoThi.Name = "PictureBox_DoThi";
            this.PictureBox_DoThi.Size = new System.Drawing.Size(620, 520);
            this.PictureBox_DoThi.SizeMode = System.Windows.Forms.PictureBoxSizeMode.AutoSize;
            this.PictureBox_DoThi.TabIndex = 72;
            this.PictureBox_DoThi.TabStop = false;
            // 
            // label_Lưu
            // 
            this.label_Lưu.AutoSize = true;
            this.label_Lưu.Font = new System.Drawing.Font("Microsoft Sans Serif", 9.75F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(163)));
            this.label_Lưu.Location = new System.Drawing.Point(77, 40);
            this.label_Lưu.Name = "label_Lưu";
            this.label_Lưu.Size = new System.Drawing.Size(32, 16);
            this.label_Lưu.TabIndex = 74;
            this.label_Lưu.Text = "Lưu";
            // 
            // groupBox1
            // 
            this.groupBox1.BackColor = System.Drawing.Color.Transparent;
            this.groupBox1.Controls.Add(this.label3);
            this.groupBox1.Controls.Add(this.label_Xóa);
            this.groupBox1.Controls.Add(this.label_vẽ);
            this.groupBox1.Controls.Add(this.label_Lưu);
            this.groupBox1.Controls.Add(this.button_Save);
            this.groupBox1.Controls.Add(this.button_Draw);
            this.groupBox1.Controls.Add(this.button_Clear);
            this.groupBox1.Controls.Add(this.Display_X_Y);
            this.groupBox1.Font = new System.Drawing.Font("Microsoft Sans Serif", 9.75F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(163)));
            this.groupBox1.ForeColor = System.Drawing.Color.Yellow;
            this.groupBox1.Location = new System.Drawing.Point(12, 205);
            this.groupBox1.Name = "groupBox1";
            this.groupBox1.Size = new System.Drawing.Size(271, 209);
            this.groupBox1.TabIndex = 75;
            this.groupBox1.TabStop = false;
            this.groupBox1.Text = "Bảng điều khiển";
            // 
            // label3
            // 
            this.label3.AutoSize = true;
            this.label3.Font = new System.Drawing.Font("Microsoft Sans Serif", 9F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(163)));
            this.label3.Location = new System.Drawing.Point(148, 21);
            this.label3.Name = "label3";
            this.label3.Size = new System.Drawing.Size(105, 15);
            this.label3.TabIndex = 77;
            this.label3.Text = " Tín hiệu gửi về";
            // 
            // label_Xóa
            // 
            this.label_Xóa.AutoSize = true;
            this.label_Xóa.Location = new System.Drawing.Point(74, 163);
            this.label_Xóa.Name = "label_Xóa";
            this.label_Xóa.Size = new System.Drawing.Size(35, 16);
            this.label_Xóa.TabIndex = 76;
            this.label_Xóa.Text = "Xóa";
            // 
            // label_vẽ
            // 
            this.label_vẽ.AutoSize = true;
            this.label_vẽ.Location = new System.Drawing.Point(77, 102);
            this.label_vẽ.Name = "label_vẽ";
            this.label_vẽ.Size = new System.Drawing.Size(27, 16);
            this.label_vẽ.TabIndex = 75;
            this.label_vẽ.Text = "Vẽ";
            // 
            // label_connect
            // 
            this.label_connect.AutoSize = true;
            this.label_connect.BackColor = System.Drawing.Color.Transparent;
            this.label_connect.Font = new System.Drawing.Font("Microsoft Sans Serif", 9.75F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(163)));
            this.label_connect.ForeColor = System.Drawing.Color.Yellow;
            this.label_connect.Location = new System.Drawing.Point(21, 109);
            this.label_connect.Name = "label_connect";
            this.label_connect.Size = new System.Drawing.Size(55, 16);
            this.label_connect.TabIndex = 76;
            this.label_connect.Text = "Kết nối";
            // 
            // label_disconnect
            // 
            this.label_disconnect.AutoSize = true;
            this.label_disconnect.BackColor = System.Drawing.Color.Transparent;
            this.label_disconnect.Font = new System.Drawing.Font("Microsoft Sans Serif", 9.75F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(163)));
            this.label_disconnect.ForeColor = System.Drawing.Color.Yellow;
            this.label_disconnect.Location = new System.Drawing.Point(77, 109);
            this.label_disconnect.Name = "label_disconnect";
            this.label_disconnect.Size = new System.Drawing.Size(91, 16);
            this.label_disconnect.TabIndex = 77;
            this.label_disconnect.Text = "Ngắt kết nối";
            // 
            // label_thoát
            // 
            this.label_thoát.AutoSize = true;
            this.label_thoát.BackColor = System.Drawing.Color.Transparent;
            this.label_thoát.Font = new System.Drawing.Font("Microsoft Sans Serif", 11.25F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(163)));
            this.label_thoát.ForeColor = System.Drawing.Color.Yellow;
            this.label_thoát.Location = new System.Drawing.Point(86, 434);
            this.label_thoát.Name = "label_thoát";
            this.label_thoát.Size = new System.Drawing.Size(149, 18);
            this.label_thoát.TabIndex = 78;
            this.label_thoát.Text = "Thoát chương trình";
            // 
            // groupBox2
            // 
            this.groupBox2.BackColor = System.Drawing.Color.Transparent;
            this.groupBox2.Controls.Add(this.textBox_Status);
            this.groupBox2.Controls.Add(this.label_disconnect);
            this.groupBox2.Controls.Add(this.label_connect);
            this.groupBox2.Controls.Add(this.Button_DisConnect);
            this.groupBox2.Controls.Add(this.Button_Connect);
            this.groupBox2.Controls.Add(this.ComboBox_COMPort);
            this.groupBox2.Font = new System.Drawing.Font("Microsoft Sans Serif", 9.75F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(163)));
            this.groupBox2.ForeColor = System.Drawing.Color.Yellow;
            this.groupBox2.Location = new System.Drawing.Point(12, 63);
            this.groupBox2.Name = "groupBox2";
            this.groupBox2.Size = new System.Drawing.Size(270, 136);
            this.groupBox2.TabIndex = 79;
            this.groupBox2.TabStop = false;
            this.groupBox2.Text = "Cổng COM";
            // 
            // textBox_Status
            // 
            this.textBox_Status.BackColor = System.Drawing.SystemColors.InfoText;
            this.textBox_Status.Font = new System.Drawing.Font("Microsoft Sans Serif", 12F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(163)));
            this.textBox_Status.ForeColor = System.Drawing.Color.Green;
            this.textBox_Status.Location = new System.Drawing.Point(168, 40);
            this.textBox_Status.Multiline = true;
            this.textBox_Status.Name = "textBox_Status";
            this.textBox_Status.ReadOnly = true;
            this.textBox_Status.Size = new System.Drawing.Size(85, 48);
            this.textBox_Status.TabIndex = 78;
            this.textBox_Status.Text = "KHÔNG KẾT NỐI\r\n";
            this.textBox_Status.TextAlign = System.Windows.Forms.HorizontalAlignment.Center;
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.BackColor = System.Drawing.Color.Transparent;
            this.label2.Font = new System.Drawing.Font("Lucida Calligraphy", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label2.ForeColor = System.Drawing.Color.Yellow;
            this.label2.Location = new System.Drawing.Point(34, 490);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(219, 42);
            this.label2.TabIndex = 81;
            this.label2.Text = "SVTH : Trần Hoàng Huy\r\n             Lê Hoài Thanh";
            this.label2.TextAlign = System.Drawing.ContentAlignment.TopCenter;
            // 
            // Form_Mouse
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.BackgroundImage = ((System.Drawing.Image)(resources.GetObject("$this.BackgroundImage")));
            this.ClientSize = new System.Drawing.Size(923, 552);
            this.Controls.Add(this.label2);
            this.Controls.Add(this.groupBox2);
            this.Controls.Add(this.label_thoát);
            this.Controls.Add(this.groupBox1);
            this.Controls.Add(this.PictureBox_DoThi);
            this.Controls.Add(this.button_Close);
            this.Controls.Add(this.label1);
            this.Icon = ((System.Drawing.Icon)(resources.GetObject("$this.Icon")));
            this.MaximizeBox = false;
            this.Name = "Form_Mouse";
            this.Text = "HỆ TỌA ĐỘ ẢO CHO ROBOT DI ĐỘNG";
            ((System.ComponentModel.ISupportInitialize)(this.PictureBox_DoThi)).EndInit();
            this.groupBox1.ResumeLayout(false);
            this.groupBox1.PerformLayout();
            this.groupBox2.ResumeLayout(false);
            this.groupBox2.PerformLayout();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        internal System.Windows.Forms.Button button_Close;
        internal System.Windows.Forms.Button button_Save;
        internal System.Windows.Forms.Button button_Draw;
        internal System.Windows.Forms.Button button_Clear;
        internal System.Windows.Forms.Button Button_DisConnect;
        internal System.Windows.Forms.Button Button_Connect;
        private System.Windows.Forms.ListBox Display_X_Y;
        internal System.Windows.Forms.Label label1;
        internal System.Windows.Forms.ComboBox ComboBox_COMPort;
        private System.Windows.Forms.PictureBox PictureBox_DoThi;
        private System.Windows.Forms.Label label_Lưu;
        private System.Windows.Forms.GroupBox groupBox1;
        private System.Windows.Forms.Label label3;
        private System.Windows.Forms.Label label_Xóa;
        private System.Windows.Forms.Label label_vẽ;
        private System.Windows.Forms.Label label_connect;
        private System.Windows.Forms.Label label_disconnect;
        private System.Windows.Forms.Label label_thoát;
        private System.Windows.Forms.GroupBox groupBox2;
        private System.Windows.Forms.Label label2;
        private System.Windows.Forms.TextBox textBox_Status;
    }
}

