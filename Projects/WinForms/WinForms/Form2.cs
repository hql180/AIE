using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace WinForms
{
    public partial class Form2 : Form
    {
        public Form2()
        {
            InitializeComponent();
        }

        private void newToolStripMenuItem_Click(object sender, EventArgs e)
        {
            Form1 newMDIChild = new Form1();
            newMDIChild.MdiParent = this;
            newMDIChild.Show();
        }

        private void saveToolStripMenuItem_Click(object sender, EventArgs e)
        {
            Form activeChild = this.ActiveMdiChild;
            if (activeChild != null)
            {
                if(activeChild.GetType() == typeof(Form1))
                {
                    try 
                    {
                        Form1 active = (Form1)activeChild;                                              
                        if(active != null)
                        {
                            active.save();
                        }
                    }
                    catch
                    {
                        MessageBox.Show("Error");
                    }
                }
            }
        }
    }
}
