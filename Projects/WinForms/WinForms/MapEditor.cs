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
using System.Runtime.Serialization;
using System.Runtime.Serialization.Json;

namespace WinForms
{
     public partial class MapEditor : Form
    {
        Bitmap tileSet = null;

        Bitmap background = null;

        TileLayer map;

        Rectangle hover;

        Rectangle selection;

        Rectangle target;

        float zoom = 1f;

        float gridZoom = 1f;

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

                        g.DrawImage(tileSet, new RectangleF(x * (float)tileWidth.Value * zoom, 
                                                            y * (float)tileHeight.Value * zoom,
                                                            (float)tileWidth.Value * zoom, 
                                                            (float)tileHeight.Value * zoom),
                                             new RectangleF(x * (float)tileWidth.Value, 
                                                            y * (float)tileHeight.Value, 
                                                            (float)tileWidth.Value, 
                                                            (float)tileHeight.Value), GraphicsUnit.Pixel);
                    }
                }

                try
                {
                    g.DrawRectangle(new Pen(Color.Blue), hover); // 
                }
                catch { Console.WriteLine("Something went wrong in tileBox_Paint"); }

                tileBox.Size = new Size(new Point((int)((float)tileSet.Width * zoom), (int)((float)tileSet.Height * zoom)));                
            }
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
            Invalidate();
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
            int mouseX = (int)Math.Floor(e.X / (double)mapBox.Width * gridColumns);
            int mouseY = (int)Math.Floor(e.Y / (double)mapBox.Height * gridRows);

            target = new Rectangle((int)(mouseX * (float)gridWidth.Value * gridZoom), (int)(mouseY * (float)gridHeight.Value * gridZoom), (int)((float)gridWidth.Value * gridZoom), (int)((float)gridHeight.Value * gridZoom));

            Refresh();
        }

        private void mapBox_Paint(object sender, PaintEventArgs e)
        {
            Graphics g = e.Graphics;

            if (background != null && mapBox.BackgroundImage == null)
                mapBox.BackgroundImage = new Bitmap(background);      

            try
            {
                if (gridZoom <= 0)
                    gridZoom = 1;


                g.DrawImage(tileSet, target, selection, GraphicsUnit.Pixel);

                for (int columns = 0; columns < gridColumns; ++columns)
                    for (int rows = 0; rows < gridRows; ++rows)
                    {
                        if (map.tilelayer[columns][rows].draw == true)
                        {
                            g.DrawImage(tileSet, new RectangleF(map.tilelayer[columns][rows].dest.X * gridZoom,
                                                                map.tilelayer[columns][rows].dest.Y * gridZoom,
                                                                map.destWidth * gridZoom, map.destHeight * gridZoom),
                                                    new RectangleF(map.tilelayer[columns][rows].src.X,
                                                                map.tilelayer[columns][rows].src.Y,
                                                                map.srcWidth, map.srcHeight),
                                                                GraphicsUnit.Pixel);
                        }
                    }                
            }
            catch { Console.WriteLine("Something went wrong in mapBox_paint"); }

            mapBox.Size = new Size((int)((float)gridWidth.Value * gridZoom) * gridColumns, (int)((float)gridHeight.Value * gridZoom) * gridRows);
        }

        private void menuItemNewFile_Click(object sender, EventArgs e)
        {
            NewFileForm file = new NewFileForm();

            file.ShowDialog();

            gridWidth = file.gridWidth;
            gridHeight = file.gridHeight;
            gridColumns = (int)file.gridColumns.Value;
            gridRows = (int)file.gridRows.Value;

            map = new TileLayer((int)tileWidth.Value, (int)tileHeight.Value, (int)gridWidth.Value, (int)gridHeight.Value, gridColumns, gridRows);

            mapBox.Size = new Size((int)gridWidth.Value * gridColumns, (int)gridHeight.Value * gridRows);
        }

        private void mapBox_MouseClick(object sender, MouseEventArgs e)
        {
            int mouseX = (int)Math.Floor(e.X / (double)mapBox.Width * gridColumns);
            int mouseY = (int)Math.Floor(e.Y / (double)mapBox.Height * gridRows);

            if (map != null)
            {
                if (e.Button == MouseButtons.Left)
                    map.set(selection, mouseX, mouseY);
                else if (e.Button == MouseButtons.Right)
                    map.remove(mouseX, mouseY);
            }
        }

        private void setBackground_Click(object sender, EventArgs e)
        {
            OpenFileDialog loadBackGround = new OpenFileDialog();

            loadBackGround.Filter = "png files (*.png)|*.png|All files (*.*)|*.*";
            loadBackGround.FilterIndex = 1;
            loadBackGround.RestoreDirectory = true;

            if (loadBackGround.ShowDialog() == DialogResult.OK)
            {
                FileStream file = new FileStream(loadBackGround.FileName, FileMode.Open);
                background = new Bitmap(file);

                mapBox.BackgroundImage = new Bitmap(background);

                file.Close();                              

                mapBox.Refresh();
            }
        }

        private void saveToolStripMenuItem_Click(object sender, EventArgs e)
        {
            SaveFileDialog saveFileDialog1 = new SaveFileDialog();

            saveFileDialog1.Filter = "JSON (*.json)|*.json";
            saveFileDialog1.FilterIndex = 1;
            saveFileDialog1.RestoreDirectory = true;

            if (saveFileDialog1.ShowDialog() == DialogResult.OK)
            {
                FileStream file = new FileStream(saveFileDialog1.FileName, FileMode.Create);

                Save saveData = new Save();

                saveData.saveData(tileSet, background, map, gridColumns, gridRows, (int)gridHeight.Value, 
                                (int)gridWidth.Value, (int)tileHeight.Value, (int)tileWidth.Value);

                DataContractJsonSerializer ser = new DataContractJsonSerializer(typeof(Save));

                ser.WriteObject(file, saveData);

                file.Close();
            }
        }

        private void fileToolStripMenuItem1_Click(object sender, EventArgs e)
        {
            OpenFileDialog saveFileDialog1 = new OpenFileDialog();

            saveFileDialog1.Filter = "JSON (*.json)|*.json";
            saveFileDialog1.FilterIndex = 1;
            saveFileDialog1.RestoreDirectory = true;

            if (saveFileDialog1.ShowDialog() == DialogResult.OK)
            {
                FileStream file = new FileStream(saveFileDialog1.FileName, FileMode.Open);

                DataContractJsonSerializer ser = new DataContractJsonSerializer(typeof(Save));

                Save saveData = (Save)ser.ReadObject(file);
                
                tileSet = Save.ByteToBitmap(saveData.tileSetByte);

                background = Save.ByteToBitmap(saveData.backgroundByte);

                map = saveData.map;

                gridColumns = saveData.gridColumns;

                gridRows = saveData.gridRows;

                gridHeight.Value = saveData.gridHeight;

                gridWidth.Value = saveData.gridWidth;

                tileHeight.Value = saveData.tileHeight;

                tileWidth.Value = saveData.tileWidth;

                mapBox.Size = new Size((int)gridWidth.Value * gridColumns, (int)gridHeight.Value * gridRows);

                file.Close();

                Invalidate();
            }
        }

        private void trackGridZoom_Scroll(object sender, EventArgs e)
        {
            gridZoom = trackGridZoom.Value * .5f;

            if (gridZoom <= 0)
                gridZoom = 1;

            mapBox.Refresh();
        }

        private void trackGridZoom_ValueChanged(object sender, EventArgs e)
        {
            Invalidate();
        }

        private void snakeToolStripMenuItem_Click(object sender, EventArgs e)
        {
            Snake game = new Snake();

            game.ShowDialog();


        }
    }


}
