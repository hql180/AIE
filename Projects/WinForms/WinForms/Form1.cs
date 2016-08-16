using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;


namespace WinForms
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        List<MouseEventArgs> EventList = new List<MouseEventArgs>();

        private void pictureBox1_Click(object sender, EventArgs e)
        {
            if(e.GetType() == typeof(MouseEventArgs))
            {
                MouseEventArgs me = e as MouseEventArgs; 
                textOutput.Text += me.Location.ToString();
                if (me != null)
                    EventList.Add(me);
            }
        }

        public void save()
        {
            SaveFileDialog saveFileDialog1 = new SaveFileDialog();

            saveFileDialog1.Filter = "txt files (*.txt)|*.txt|All files (*.*)|*.*";
            saveFileDialog1.FilterIndex = 1;
            saveFileDialog1.RestoreDirectory = true;

            if(saveFileDialog1.ShowDialog() == DialogResult.OK)
            {

                StreamWriter file = new StreamWriter(saveFileDialog1.FileName, false);

                file.WriteLine(textOutput.Text);                

                file.Close();
            }
        }

        private void buttonClear_Click(object sender, EventArgs e)
        {
            textOutput.Clear();
        }

        private void buttonRead_Click(object sender, EventArgs e)
        {
            foreach (var me in EventList)
            {
                textOutput.Text += me.Location.ToString();
            }
        }
    }
}
