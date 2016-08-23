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

namespace WinForms
{
    public partial class MapEditor : Form
    {
        Bitmap tileSet = null;

        //Bitmap currentTile = null;

        Rectangle hover;

        Rectangle selection;

        Rectangle target;

        float zoom = 1f;

        int columns;

        int rows;

        int gridColumns;

        int gridRows;

        public MapEditor()
        {
            InitializeComponent();
            InitializeTileZoom();


        }

        private void InitializeTileZoom()
        {
            trackTileZoom.Minimum = 1;
            trackTileZoom.Maximum = 20;

            trackTileZoom.TickFrequency = 1;

        }

        private void TileMapMenu_Click(object sender, EventArgs e)
        {
            OpenFileDialog loadTiles = new OpenFileDialog();

            loadTiles.Filter = "png files (*.png)|*.png|All files (*.*)|*.*";
            loadTiles.FilterIndex = 1;
            loadTiles.RestoreDirectory = true;

            if(loadTiles.ShowDialog() == DialogResult.OK)
            {
                FileStream file = new FileStream(loadTiles.FileName, FileMode.Open);
                tileSet = new Bitmap(file);

                file.Close();

                tileBox.Refresh();
            }
        }

        private void tileBox_Paint(object sender, PaintEventArgs e)
        {
            Graphics g = e.Graphics;

            if(tileSet != null)
            {
                columns = (int)(tileSet.Width / tileWidth.Value);
                rows = (int)(tileSet.Height / tileHeight.Value);

                for (int x = 0; x <= columns; ++x)
                {
                    for (int y = 0; y <= rows; ++y)
                    {
                        if (zoom <= 0)
                            zoom = 1f;

                        g.DrawImage(tileSet, new RectangleF(x * (float)tileWidth.Value * zoom, y * (float)tileHeight.Value * zoom, (float)tileWidth.Value * zoom, (float)tileHeight.Value * zoom),
                                             new RectangleF(x * (float)tileWidth.Value, y * (float)tileHeight.Value, (float)tileWidth.Value, (float)tileHeight.Value), GraphicsUnit.Pixel);
                    }
                }

                try
                {
                    g.DrawRectangle(new Pen(Color.Blue), hover); // 
                }
                catch { }

                tileBox.Size = new Size(new Point((int)((float)tileSet.Width * zoom), (int)((float)tileSet.Height * zoom)));                
            }

            


            //g.ScaleTransform(zoom, zoom);   


            //if (tileSet != null)
            //{
            //    if (tileWidth.Value < 1)
            //        tileWidth.Value = 1;
            //    if (tileHeight.Value < 1)
            //        tileHeight.Value = 1;

            //    int columns = tileSet.Width / (int)tileWidth.Value;

            //    int rows = tileSet.Height / (int)tileHeight.Value;

            //    int width = (int)tileWidth.Value * columns;
            //    int height = (int)tileHeight.Value * rows;

            //    //if(zoom >0)
            //    //{
            //    //    width *= (int)zoom;
            //    //    height *= (int)zoom;
            //    //}

            //    Bitmap bmp = new Bitmap(width, height);
            //    Graphics g = Graphics.FromImage(bmp);

            //    for (int x = 0; x<= columns; ++x )
            //    {
            //        for(int y = 0; y<= rows; ++y)
            //        {
            //            g.DrawImage(tileSet, new RectangleF(x * (float)tileWidth.Value, y * (float)tileHeight.Value, (float)tileWidth.Value, (float)tileHeight.Value),
            //                                 new RectangleF(x * (float)tileWidth.Value, y * (float)tileHeight.Value, (float)tileWidth.Value, (float)tileHeight.Value), GraphicsUnit.Pixel);

            //            //g.DrawImage(tileSet, new Rectangle(x * (int)tileWidth.Value * (int)zoom, y * (int)tileHeight.Value * (int)zoom, (int)tileWidth.Value * (int)zoom, (int)tileHeight.Value * (int)zoom),
            //            //                     new Rectangle(x * (int)tileWidth.Value, y * (int)tileHeight.Value, (int)tileWidth.Value, (int)tileHeight.Value), GraphicsUnit.Pixel);

            //        }
            //    }

            //    g.Dispose();

            //    tileBox.Image = bmp;

            //    tileBox.Size = new Size(bmp.Width* (int)zoom, bmp.Height *(int)zoom);
            //    // g.DrawImage(tileSet, 0, 0);                
            //} 
        }

        private void tileBox_Resize(object sender, EventArgs e)
        {
            tileBox.Invalidate();
        }

        private void MapEditor_Resize(object sender, EventArgs e)
        {
            Invalidate();
            //tilePanel.Size = 
        }

        private void trackTileZoom_Scroll(object sender, EventArgs e)
        {
            zoom = trackTileZoom.Value * .5f;

            if (zoom <= 0)
                zoom = 1;

            //Invalidate();
            tileBox.Refresh();
        }

        private void refreshButton_Click(object sender, EventArgs e)
        {
            tileBox.Invalidate();
        }

        private void tileHeight_ValueChanged(object sender, EventArgs e)
        {
            Invalidate();
        }

        private void tileWidth_ValueChanged(object sender, EventArgs e)
        {
            Invalidate();
        }

        private void trackTileZoom_ValueChanged(object sender, EventArgs e)
        {
            Invalidate();
        }

        private void tileBox_MouseHover(object sender, EventArgs e)
        {
   
        }

        private void tileBox_MouseMove(object sender, MouseEventArgs e) // Gets tile from location of mouse
        {
            int mouseX = (int)Math.Floor(e.X / (double)tileBox.Width * columns);
            int mouseY = (int)Math.Floor(e.Y / (double)tileBox.Height * rows);

            hover = new Rectangle((int)(mouseX  * (float)tileWidth.Value * zoom), (int)(mouseY * (float)tileHeight.Value *  zoom), (int)((float)tileWidth.Value * zoom), (int)((float)tileHeight.Value * zoom));

            Refresh();
        }

        private void tileBox_Click(object sender, EventArgs e)
        {
            selection = hover;

            selection.X = (int)(hover.X / zoom);
            selection.Y = (int)(hover.Y / zoom);
            selection.Width = (int)(hover.Width / zoom);
            selection.Height = (int)(hover.Height / zoom);
        }

        private void mapBox_MouseMove(object sender, MouseEventArgs e)
        {
            int columns = mapBox.Width / (int)gridWidth.Value;
            int rows = mapBox.Height / (int)gridHeight.Value;

            int mouseX = (int)Math.Floor(e.X / (double)mapBox.Width * gridColumns);
            int mouseY = (int)Math.Floor(e.Y / (double)mapBox.Height * gridRows);

            target = new Rectangle((int)(mouseX * (float)gridWidth.Value), (int)(mouseY * (float)gridHeight.Value), (int)gridWidth.Value, (int)gridHeight.Value);

            Refresh();
        }

        private void mapBox_Paint(object sender, PaintEventArgs e)
        {
            Graphics g = e.Graphics;

            try
            {
                g.DrawImage(tileSet, target, selection, GraphicsUnit.Pixel);
            }
            catch { }
        }

        private void menuItemNewFile_Click(object sender, EventArgs e)
        {
            NewFileForm file = new NewFileForm();

            file.Parent = this;

            file.ShowDialog();

            gridWidth = file.gri
        }
    }
}
