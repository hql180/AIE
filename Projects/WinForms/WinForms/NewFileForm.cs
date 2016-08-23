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
    public partial class NewFileForm : Form
    {
        //public int width;

        //public int height;

        //public int gColumns;

        //public int gRows;     

        public NewFileForm()
        {
            InitializeComponent();
        }

        private void Okay_Click(object sender, EventArgs e)
        {
            //width = (int)gridWidth.Value;
            //height = (int)gridHeight.Value;
            //gColumns = (int)gridColumns.Value;
            //gRows = (int)gridRows.Value;

            //gridWidth.IsAccessible = true;

            Close();
        }
    }
}
