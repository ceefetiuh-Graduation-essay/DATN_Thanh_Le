using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.IO;
using System.IO.Ports;
using System.Runtime.InteropServices;
using System.Diagnostics;

namespace Form_Mouse
{
    public partial class Form_Mouse : Form
    {
        SerialPort serialComPort = new SerialPort();
        private string in_data;

        public Form_Mouse()
        {
            InitializeComponent();
            foreach (string portName in SerialPort.GetPortNames())//tim cong COM co trong may va add no
            {
                ComboBox_COMPort.Items.Add(portName);
            }
            if (ComboBox_COMPort.Items.Count > 0)
                ComboBox_COMPort.SelectedIndex = ComboBox_COMPort.Items.Count - 1;

            serialComPort.DataReceived += new SerialDataReceivedEventHandler(serialComPort_DataReceived);
        }

        void serialComPort_DataReceived(object sender, SerialDataReceivedEventArgs e)
        {
            in_data = serialComPort.ReadLine();
            this.Invoke(new EventHandler(displaydata_event));
        }

        private void displaydata_event(object sender, EventArgs e)
        {
            // hiển thị các giá trị nhận được
            try
            {                
                Display_X_Y.Items.Add(in_data);
                Draw();
                //timer.Enabled = true;
            }
            catch (Exception ex3)
            {
                MessageBox.Show(ex3.Message, "LỖI ĐỌC GIÁ TRỊ");
            }
        }

        private void Button_Connect_Click(object sender, EventArgs e)
        {
            if (ComboBox_COMPort.Text == "CHỌN CỔNG COM")
                MessageBox.Show("Hãy chọn một cổng COM", "Cảnh báo", MessageBoxButtons.OK, MessageBoxIcon.Warning);
            else
            {
                try
                {
                    bool portError = false;
                    if (serialComPort.IsOpen)
                        serialComPort.Close();
                    else
                    {
                        serialComPort.PortName = ComboBox_COMPort.Text;
                        serialComPort.BaudRate = int.Parse("9600");
                        MessageBox.Show(ComboBox_COMPort.Text + " đã kết nối", "Thông tin", MessageBoxButtons.OK, MessageBoxIcon.Information);
                        textBox_Status.Text = "ĐÃ KẾT NỐI";
                        textBox_Status.ForeColor = Color.LimeGreen;
                    }
                    try
                    {
                        serialComPort.Open();
                    }
                    catch (IOException)
                    {
                        portError = true;
                    }
                    if (portError)
                    {
                        MessageBox.Show("KHÔNG THỂ KẾT NỐI");
                    }
                    else
                    {
                        ComboBox_COMPort.Enabled = false;
                        Button_Connect.Enabled = false;
                        Button_DisConnect.Enabled = true;
                    }
                }
                catch (Exception ex1)
                {
                    {
                        MessageBox.Show(ex1.Message, "LỖI KẾT NỐI");
                    }
                }
            }
        }

        private void Button_DisConnect_Click(object sender, EventArgs e)
        {
            if (serialComPort.IsOpen)
            {
                serialComPort.Close();
                textBox_Status.Text = "KHÔNG KẾT NỐI";
                textBox_Status.ForeColor = Color.LimeGreen;
                MessageBox.Show("COM ĐÃ NGẮT KẾT NỐI", "Information", MessageBoxButtons.OK,
MessageBoxIcon.Information);
            }
            ComboBox_COMPort.Enabled = true;
            Button_Connect.Enabled = true;
            Button_DisConnect.Enabled = false;
        }

        private void button_Clear_Click(object sender, EventArgs e)
        {
            try
            {
                File.WriteAllText(@"savedata.txt", String.Empty);
            }
            catch (Exception ex4)
            {
                {
                    MessageBox.Show(ex4.Message, "LỖI XÓA FILE");
                }
            }         
            // xóa đồ thị và list box
            PictureBox_DoThi.Refresh();
            Display_X_Y.Refresh();
            Display_X_Y.ResetText();
            Display_X_Y.Items.Clear();
        }

        private void button_Draw_Click(object sender, EventArgs e)
        {
            this.Invoke(new EventHandler(displaydata_event));
            Ler();
            Draw();
        }

        private void Ler()
        {
            //hàm đọc giá trị từ file .txt
            System.IO.StreamReader stRead = new System.IO.StreamReader(@"savedata.txt");
            while (!stRead.EndOfStream)
            {
                Display_X_Y.Items.Add(stRead.ReadLine());
            }
        }

        private void Draw()
        {
            //hàm vẽ giá trị
            try
            {
                Graphics graph = PictureBox_DoThi.CreateGraphics();
                Point toaDo = new Point();
                Point ptAnt = new Point(0, 100);

                graph.SmoothingMode = System.Drawing.Drawing2D.SmoothingMode.HighQuality;

                for (int ContItems = 0; ContItems <= Display_X_Y.Items.Count - 1; ContItems++)
                {
                    string str = Display_X_Y.Items[ContItems].ToString();
                    for (int ContChar = 0; ContChar < str.Length; ContChar++)
                    {
                        if (Display_X_Y.Items[ContItems].ToString().Substring(ContChar, 1) == " ")
                        {
                            toaDo.X = Convert.ToInt32(str.Remove(ContChar, str.Length - ContChar));
                            toaDo.Y = 100 - Convert.ToInt32(str.Remove(0, ContChar));
                            ContChar = str.Length;
                        }
                    }
                    graph.DrawLine(new Pen(Color.Blue, 2), ptAnt.X + 310, ptAnt.Y + 160, toaDo.X + 310, toaDo.Y + 160);//vẽ đường nối

                    graph.FillEllipse(new SolidBrush(Color.Red), toaDo.X + 310, toaDo.Y + 153, 6, 6);//vẽ chấm đỏ

                    graph.DrawLine(new Pen(Color.Black, 1), 0, 260, 620, 260);//vẽ trục X

                    graph.DrawLine(new Pen(Color.Black, 1), 310, 1, 310, 520);//vẽ trục Y

                    

                    graph.DrawString("O",
                        new Font("Palatino Linotype", 10, FontStyle.Bold),
                        new SolidBrush(Color.Black), 310, 260);//ghi tâm O

                    graph.DrawString("Y",
                        new Font("Palatino Linotype", 10, FontStyle.Bold),
                        new SolidBrush(Color.Black), 310, 1); // ghi trục y

                    graph.DrawString("X",
                       new Font("Palatino Linotype", 10, FontStyle.Bold),
                       new SolidBrush(Color.Black), 600, 260); // ghi trục x

                   

                    ptAnt = toaDo;
                }
            }
            catch (Exception ex2)
            {
                MessageBox.Show(ex2.Message, "LỖI VẼ HÌNH");
            }
        }

        private void button_Save_Click(object sender, EventArgs e)
        {
            //Hàm lưu giá trị nhận được
            try
            {
                if (Display_X_Y.Items.Count > 0)
                {
                    using (TextWriter tw = new StreamWriter("savedata.txt"))
                    {
                        foreach (string ab in Display_X_Y.Items)
                        {
                            tw.WriteLine(ab);
                        }
                    }
                    Process.Start("savedata.txt");
                }
            }
            catch (Exception ex3)
            {
                MessageBox.Show(ex3.Message, "LỖI LƯU FILE");
            }
        }

        private void button_Close_Click(object sender, EventArgs e)
        {
            //thoát chương trình
            Application.Exit();
        }

        private void Label_COMPort_Click(object sender, EventArgs e)
        {

        }
    }
}
