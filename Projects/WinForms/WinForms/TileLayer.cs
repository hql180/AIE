using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Drawing;
using System.Windows.Forms;

namespace WinForms
{
    class TileLayer
    {
        public struct Tile
        {
            public Rectangle src;
            public Rectangle dest;            
        }

        public Tile[,] tilelayer;

        public int srcHeight, srcWidth, destHeight, destWidth;

        public TileLayer(int tileWidth, int tileHeight, int gridWidth, int gridHeight, int gridColumns, int gridRows)
        {
            tilelayer = new Tile[gridColumns, gridRows];

            srcHeight = tileHeight;
            srcWidth = tileWidth;
            destHeight = gridHeight;
            destWidth = gridWidth;
        }

        public void set(Rectangle src, int column, int row)
        {
            try
            {
                tilelayer[column, row].src = src;
                tilelayer[column, row].dest = new Rectangle(column * destWidth, row * destHeight, destWidth, destHeight);
            }
            catch
            {
                MessageBox.Show("Something went wrong in layertile.set");
            }
        }
    }
}
