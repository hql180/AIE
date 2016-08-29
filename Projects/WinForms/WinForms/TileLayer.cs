using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Drawing;
using System.Windows.Forms;
using System.Runtime.Serialization;

namespace WinForms
{
    [DataContract]
    class TileLayer // Used for storing location data for tiles and map
    {
        [DataContract]
        public struct Tile
        {
            [DataMember(Name = "tileLayerTileSrc", IsRequired = true)]
            public Rectangle src;
            [DataMember(Name = "tileLayerTileDest", IsRequired = true)]
            public Rectangle dest;
            [DataMember(Name = "tileLayerdraw", IsRequired = true)]
            public bool draw;

        }

        [DataMember(Name = "tileLayer", IsRequired = true)]
        public Tile[][] tilelayer;

        [DataMember(Name = "tileLayerSrcHeight", IsRequired = true)]
        public int srcHeight;

        [DataMember(Name = "tileLayerSrcWidth", IsRequired = true)]
        public int srcWidth;

        [DataMember(Name = "tileLayerDestHeight", IsRequired = true)]
        public int destHeight;

        [DataMember(Name = "tileLayerDestWidth", IsRequired = true)]
        public int destWidth;

        //public Tile[][] jaggedForSaving;

        public TileLayer() { }

        public TileLayer(int tileWidth, int tileHeight, int gridWidth, int gridHeight, int gridColumns, int gridRows)
        {
            tilelayer = new Tile[gridColumns][];
            //jaggedForSaving = new Tile[gridColumns][];

            for (int columns = 0; columns < gridColumns; ++columns)
            {
                tilelayer[columns] = new Tile[gridRows];
            }

            srcHeight = tileHeight;
            srcWidth = tileWidth;
            destHeight = gridHeight;
            destWidth = gridWidth;            
        }

        public void set(Rectangle src, int column, int row)
        {
            try
            {
                tilelayer[column][row].src = src;
                tilelayer[column][row].dest = new Rectangle(column * destWidth, row * destHeight, destWidth, destHeight);
                tilelayer[column][row].draw = true;
            }
            catch
            {
                MessageBox.Show("Something went wrong in layertile.set");
            }
        }

        public void remove(int column, int row)
        {
            tilelayer[column][row] = new Tile();
        }
    }
}
